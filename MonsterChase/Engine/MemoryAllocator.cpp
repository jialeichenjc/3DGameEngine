#include "MemoryAllocator.h"


// constructor                                                       
MemoryAllocator::MemoryAllocator()
{
	// set up free block descriptor list

	// grab first item in the free list to describe entire block

}

void MemoryAllocator::set_up_bd_idle(int num_total_bd) {
	for (int i = 0; i < num_total_bd; i++) {
		//m_total
	}
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
