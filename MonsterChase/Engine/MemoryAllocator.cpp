#include "MemoryAllocator.h"
#include "Debug.h"
#define HEAP_SIZE 1024 * 256

//static const size_t heap_size = 1024 * 1024;
static char *heap = (char*) malloc(HEAP_SIZE);
MemoryAllocator::MemoryAllocator()
{	
	// Allocate a list of block descirptors at the "top" of the heap
	for (int i = 0; i < 30; i++) {
		BlockDescriptor *bd = new (heap + i * sizeof(BlockDescriptor)) BlockDescriptor;
		bd_idle.push(bd);
	}
	mem_free.head = &bd_idle.pop_head();
	mem_free.head->block_base_ptr = &heap[30 * sizeof(BlockDescriptor)];
	mem_free.head->block_size = HEAP_SIZE - 30 * sizeof(BlockDescriptor);
	mem_in_use = BlockDescriptorList();
}


void* MemoryAllocator::alloc_mem(size_t req_size) {
	void *mem_ptr = NULL;
	BlockDescriptor *curr = mem_free.head;
	while (curr->next_bd != NULL) {
		if (curr->block_size >= req_size) {
			// grab a new block descriptor
			assert(bd_idle.head != NULL, "ERROR: Not enough block descriptors");
			if (bd_idle.head != NULL) {
				BlockDescriptor &bd_alloc = bd_idle.pop_head();
				// have it describe the memeory to be allocated
				bd_alloc.block_size = req_size;
				// mem_ptr point to the memory block to be allocated
				mem_ptr = curr->block_base_ptr;
				bd_alloc.block_base_ptr = mem_ptr;
				// add it to the memory in use block descriptor list
				mem_in_use.push(&bd_alloc);
			}

			// shrink the block size of the current block descriptor
			// also modify the pointer to memeory block
			curr->block_size = curr->block_size - req_size;
			curr->block_base_ptr = heap + curr->offset + req_size;
			curr->offset += curr->offset + req_size;

			// if the block descriptor points to no memory after the allocation, remove it from the free memory list
			if (curr->block_size == 0) {
				mem_free.remove(curr);
			}
			break;
		} 
		curr = curr->next_bd;
	}

	return mem_ptr;
}

void MemoryAllocator::free_mem(void *mem_ptr) {
	/*
	Insert functionality of free_mem

	*/
}

void MemoryAllocator::printHeap() {
	printf("head of heap is %p size of heap is %zu\n", heap, sizeof(heap));
	printf("size of block descriptor %zu\n", sizeof(BlockDescriptor));
	printf("free block address at %p size is %zu\n", mem_free.head->block_base_ptr, mem_free.head->block_size);
}

void set_Block_Descriptor_List() {
	
}

MemoryAllocator::~MemoryAllocator()
{
	free(heap);
}
