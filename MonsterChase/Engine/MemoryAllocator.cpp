#include "MemoryAllocator.h"
#include "Debug.h"
#define HEAP_SIZE 1024 * 1024
#define TOTAL_NUM_BLOCK_DESCRIPTORS 1000

//static const size_t heap_size = 1024 * 1024;
static char *heap = (char*) malloc(HEAP_SIZE);
MemoryAllocator::MemoryAllocator()
{	
	// Allocate a list of block descirptors at the "top" of the heap
	for (int i = 0; i < TOTAL_NUM_BLOCK_DESCRIPTORS; i++) {
		BlockDescriptor *bd = new (heap + i * sizeof(BlockDescriptor)) BlockDescriptor;
		available_bd_list.push(bd);
	}
	heap_mem_bd.block_base_ptr = &heap[TOTAL_NUM_BLOCK_DESCRIPTORS * sizeof(BlockDescriptor)];
	heap_mem_bd.block_size = HEAP_SIZE - TOTAL_NUM_BLOCK_DESCRIPTORS * sizeof(BlockDescriptor);
	free_mem_bd_list.head = &available_bd_list.pop_head();
	free_mem_bd_list.head->block_base_ptr = heap_mem_bd.block_base_ptr;
	free_mem_bd_list.head->block_size = HEAP_SIZE - TOTAL_NUM_BLOCK_DESCRIPTORS * sizeof(BlockDescriptor);
	free_mem_bd_list.size = 1;
}


void* MemoryAllocator::alloc_mem(size_t req_size) {
	void *mem_ptr = NULL;
	BlockDescriptor *curr = free_mem_bd_list.head;
	// go through the block descriptor list for free memory
	// if any memory block has required size, then use that block.
	while (curr != NULL) {
		if (curr->block_size >= req_size) {
			// grab a new block descriptor
			assert(available_bd_list.head != NULL, "ERROR: Not enough block descriptors");
			if (available_bd_list.head != NULL) {
				BlockDescriptor &bd_alloc = available_bd_list.pop_head();
				// have it describe the memeory to be allocated
				bd_alloc.block_size = req_size;
				// mem_ptr point to the memory block to be allocated
				mem_ptr = curr->block_base_ptr;
				bd_alloc.block_base_ptr = mem_ptr;
				// add it to the memory in use block descriptor list
				in_use_bd_list.push(&bd_alloc);
			}

			// shrink the block size of the current block descriptor
			// also modify the pointer to memeory block
			curr->block_size = curr->block_size - req_size;
			curr->block_base_ptr = static_cast<char*>(curr->block_base_ptr) + req_size;

			// if the block descriptor points to no memory after the allocation, remove it from the free memory list
			if (curr->block_size == 0) {
				free_mem_bd_list.remove(curr);
			}
			break;
		} 
		curr = curr->next_bd;
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

void MemoryAllocator::free_mem(void *mem_ptr) {
	// first, find the block descriptor that contains the pointer to the memory block
	BlockDescriptor *curr = in_use_bd_list.head;
	while (curr != NULL) {
		if (curr->block_base_ptr == mem_ptr) {			
			BlockDescriptor &bd = *curr;
			// delete the block descriptor from the in-use list
			in_use_bd_list.remove(curr);
			// add it to the free memory block list
			free_mem_bd_list.push(&bd);

			return;
		}
		else {
			curr = curr->next_bd;
		}
	}
	// Could not find pointer to be freed. Log an error
	log_error("Pointer to be freed does not exist");
	//return;
}


void MemoryAllocator::printHeap() {
	printf("\n*****************head of heap is %p size of heap is %zu\n", heap, sizeof(heap));
	printf("\n*****************heap block descriptor points to %p, heap memory size is %zu\n", heap_mem_bd.block_base_ptr,
		heap_mem_bd.block_size);
	printf("\n*****************size of block descriptor %zu\n", sizeof(BlockDescriptor));
	printf("\n*****************free block address at %p size is %zu\n", free_mem_bd_list.head->block_base_ptr, free_mem_bd_list.head->block_size);
}

void set_Block_Descriptor_List() {
	
}

MemoryAllocator::~MemoryAllocator()
{
	free(heap);
}
