#include "MemoryAllocator.h"


// constructor                                                       
MemoryAllocator::MemoryAllocator()
{
	// create a list of block descriptors available to describe memory block
	bd_idle = BlockDescriptorList(20);

	// grab first item in the free list to describe entire block
	BlockDescriptor *total_block = bd_idle.pop_head();
	total_block->block_size = MEMORY_TOTAL;
	total_block->block_base_ptr = total_mem;
	
	// start with a list of free memory of the total block
	mem_free = BlockDescriptorList(total_block);
	mem_in_use = BlockDescriptorList();
}


void* MemoryAllocator::alloc_mem(size_t req_size) {
	void *mem_ptr;
	/*
	Insert functionality of alloc_mem

	*/
	return mem_ptr;
}

void MemoryAllocator::free_mem(void *mem_ptr) {
	/*
	Insert functionality of free_mem

	*/
}

MemoryAllocator::~MemoryAllocator()
{
}
