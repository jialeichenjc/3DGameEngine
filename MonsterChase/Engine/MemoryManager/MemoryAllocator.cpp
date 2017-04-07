#include "MemoryAllocator.h"
#include "../Debug.h"
#define INCLUDE_GUARDBAND false
#if defined(_DEBUG)
#define INCLUDE_GUARDBAND true
#endif
#define HEAP_SIZE 1024 * 1024
#define TOTAL_NUM_BLOCK_DESCRIPTORS 2048
#define DEFAULT_ALIGNMENT_SIZE 4
#define GUARD_BAND_SIZE 4
#define GUARD_BAND_VALUE 0XFFFFFFFF

//static const size_t heap_size = 1024 * 1024;
static char *heap;
MemoryAllocator* MemoryAllocator::p_instance = nullptr;
MemoryAllocator::MemoryAllocator() : mem_alignment(DEFAULT_ALIGNMENT_SIZE){	
}

MemoryAllocator::MemoryAllocator(size_t alignment_size) : mem_alignment(alignment_size) {
}

void MemoryAllocator::create_heap(const size_t heap_size) {
	heap = (char*)malloc(heap_size);
	init();
}

MemoryAllocator* MemoryAllocator::get_instance() {
	if (p_instance == nullptr) {
		p_instance = new MemoryAllocator(DEFAULT_ALIGNMENT_SIZE);
	}
	return p_instance;
}

MemoryAllocator* MemoryAllocator::get_instance(const size_t alignment_size) {
	if (p_instance == nullptr) {
		p_instance = new MemoryAllocator(alignment_size);
	}
	return p_instance;
}

void MemoryAllocator::destroy_instance() {
	delete p_instance;
	p_instance = nullptr;
}

void MemoryAllocator::set_alignment_size(const size_t alignment_size) {
	mem_alignment = alignment_size;
}

void MemoryAllocator::init() {
	for (int i = 0; i < TOTAL_NUM_BLOCK_DESCRIPTORS; i++) {
		BlockDescriptor *bd = new (heap + i * sizeof(BlockDescriptor)) BlockDescriptor();
		available_bd_list.push(bd);
	}
	heap_mem_bd.block_base_ptr = &heap[TOTAL_NUM_BLOCK_DESCRIPTORS * sizeof(BlockDescriptor)];
	heap_mem_bd.block_size = HEAP_SIZE - TOTAL_NUM_BLOCK_DESCRIPTORS * sizeof(BlockDescriptor);
	free_mem_bd_list.head = &available_bd_list.pop_head();
	free_mem_bd_list.head->block_base_ptr = heap_mem_bd.block_base_ptr;
	free_mem_bd_list.head->block_size = HEAP_SIZE - TOTAL_NUM_BLOCK_DESCRIPTORS * sizeof(BlockDescriptor);
	free_mem_bd_list.size = 1;
}

// In Debug build, returns 8 bytes memory more than requested to create 4-byte guardbands on each end
void* MemoryAllocator::alloc_mem(const size_t req_size) {
	// Make sure there is a heap, create one if not defined by the user
	if (heap == nullptr) {
		create_heap(HEAP_SIZE);
	}
	size_t allocated_size = req_size + (mem_alignment - req_size % mem_alignment); // size of the memory to be allocated, equals req_size in non-debug build
	void *mem_ptr = NULL;
	BlockDescriptor *curr = free_mem_bd_list.head;
	if (INCLUDE_GUARDBAND) {
		allocated_size += 8;
	}
	// go through the block descriptor list for free memory
	// if any memory block has required size, then use that block.
	while (curr != NULL) {
		if (curr->block_size >= allocated_size) {
			// grab a new block descriptor
			assert(available_bd_list.head != NULL, "ERROR: Not enough block descriptors");
			if (available_bd_list.head != NULL) {
				BlockDescriptor &bd_alloc = available_bd_list.pop_head();
				// have it describe the memeory to be allocated
				bd_alloc.block_size = allocated_size;
				// mem_ptr point to the memory block to be allocated
				mem_ptr = curr->block_base_ptr;
				bd_alloc.block_base_ptr = mem_ptr;
				// add it to the memory in use block descriptor list
				in_use_bd_list.push(&bd_alloc);
			}

			// shrink the block size of the current block descriptor
			// also modify the pointer to memeory block
			curr->block_size = curr->block_size - allocated_size;
			curr->block_base_ptr = static_cast<char*>(curr->block_base_ptr) + allocated_size;

			// if the block descriptor points to no memory after the allocation, remove it from the free memory list
			if (curr->block_size == 0) {
				free_mem_bd_list.remove(curr);
			}
			break;
		} 
		curr = curr->next_bd;
	}
	// out of memory
	if (mem_ptr == NULL) {
		return mem_ptr;
	}
	// return the pointer 4 bytes into the allocated memory to include guardband at the front
	if (INCLUDE_GUARDBAND) {
		// write bytes of special value into the guardbands
		*static_cast<char*>(mem_ptr) = GUARD_BAND_VALUE;
		mem_ptr = static_cast<char*>(mem_ptr) + GUARD_BAND_SIZE;
		// write to the other end of the guardband
		*(static_cast<char*>(mem_ptr) + req_size) = GUARD_BAND_VALUE;
	}
	return mem_ptr;
}

void MemoryAllocator::coalesce_mem() {
	BlockDescriptor *curr = free_mem_bd_list.head;
	BlockDescriptor *curr_check;
	// compares each block descriptor with every other block descriptor in free list
	// if they point to adjacent memories, combine them
	while (curr != NULL) {
		curr_check = curr->next_bd;
		while (curr_check != NULL) {
			if (static_cast<char*>(curr->block_base_ptr) + curr->block_size == curr_check->block_base_ptr) {
				curr->block_size += curr_check->block_size;
				BlockDescriptor *bd_to_delete = curr_check;
				free_mem_bd_list.remove(bd_to_delete);
				curr_check = curr_check->next_bd;
			}
			// similar situation, just different order of locations
			else if (static_cast<char*>(curr_check->block_base_ptr) + curr_check->block_size == curr->block_base_ptr) {
				curr->block_base_ptr = static_cast<char*>(curr->block_base_ptr) - curr_check->block_size;
				curr->block_size += curr_check->block_size;
				BlockDescriptor *bd_to_delete = curr_check;
				free_mem_bd_list.remove(bd_to_delete);
				curr_check = curr_check->next_bd;
			}

			// nothing to coalesce, keep moving
			else {
				curr_check = curr_check->next_bd;
			}			
		}
		curr = curr->next_bd;
	}
}

bool MemoryAllocator::free_mem(void *mem_ptr) {
	if (INCLUDE_GUARDBAND) {
		mem_ptr = static_cast<char*>(mem_ptr) - GUARD_BAND_SIZE;
	}
	// first, find the block descriptor that contains the pointer to the memory block
	BlockDescriptor *curr = in_use_bd_list.head;
	while (curr != NULL) {
		if (curr->block_base_ptr == mem_ptr) {			
			BlockDescriptor &bd = *curr;
			// delete the block descriptor from the in-use list
			in_use_bd_list.remove(curr);
			// add it to the free memory block list
			free_mem_bd_list.push(&bd);

			return true;
		}
		else {
			curr = curr->next_bd;
		}
	}
	// indicate failure
	return false;
}


void MemoryAllocator::printHeap() const {
	printf("\n*****************head of heap is %p size of heap is %zu\n", heap, sizeof(heap));
	printf("\n*****************heap block descriptor points to %p, heap memory size is %zu\n", heap_mem_bd.block_base_ptr,
		heap_mem_bd.block_size);
	printf("\n*****************size of block descriptor %zu\n", sizeof(BlockDescriptor));
	printf("\n*****************free block address at %p size is %zu\n", free_mem_bd_list.head->block_base_ptr, free_mem_bd_list.head->block_size);
}

void MemoryAllocator::print_list(BlockDescriptorList list) const{
	if (list.head == NULL) {
		return;
	}
	else {
		BlockDescriptor *curr = list.head;
		while (curr != NULL) {
			printf("\nsize of block descriptor is %zu and the memory pointer is %p\n",
				curr->block_size, curr->block_base_ptr);
			curr = curr->next_bd;
		}
		printf("size of block list is %zu", list.size);
	}
}

void set_Block_Descriptor_List() {
	
}

MemoryAllocator::~MemoryAllocator()
{
	free(heap);
}
