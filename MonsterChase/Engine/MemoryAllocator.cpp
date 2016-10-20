#include "MemoryAllocator.h"
#include "Debug.h"

static char total_mem[256];
// constructor                                                       
MemoryAllocator::MemoryAllocator()
{
	// create a list of block descriptors available to describe memory block
	bd_idle = BlockDescriptorList(20);
	// grab first item in the free list to describe entire block
	BlockDescriptor *total_block = &(bd_idle.pop_head());
	total_block->block_size = MEMORY_TOTAL;
	total_block->block_base_ptr = total_mem;
	total_block->offset = 0;
	
	// start with a list of free memory of the total block
	mem_free = BlockDescriptorList(total_block);
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
				mem_in_use.add(bd_alloc);
			}

			// shrink the block size of the current block descriptor
			// also modify the pointer to memeory block
			curr->block_size = curr->block_size - req_size;
			curr->block_base_ptr = total_mem + curr->offset + req_size;
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

void set_Block_Descriptor_List() {
	
}

MemoryAllocator::~MemoryAllocator()
{
}
