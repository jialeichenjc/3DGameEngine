#pragma once
#include "BlockDescriptor.h"
#include "BlockDescriptorList.h"
#include <malloc.h>
#include <new>
#define MEMORY_TOTAL 1024*1024
class MemoryAllocator
{
public:
	MemoryAllocator();
	MemoryAllocator(size_t alignment_size);
	void init();
	void* alloc_mem(const size_t req_size);
	void free_mem(void *mem_ptr);
	void coalesce_mem(); // acts like a garbage collector
	void operator=(const MemoryAllocator& mem_allocator);
	~MemoryAllocator();

	void printHeap() const;
	
	// They aren't currently describing a block of memory but available when new blocks are created
	BlockDescriptorList available_bd_list;

	// A list of BLockDescriptors describing blocks of memory available to allocate from
	BlockDescriptorList free_mem_bd_list;

	// A list of BlockDescriptors describing blocks of memory outstanding, in use by the user
	BlockDescriptorList in_use_bd_list;

	// a block descriptor for the heap, always points to the first memory address in the heap (after 
	// the memory allocated to all the block descriptors
	BlockDescriptor heap_mem_bd; 

private:
	size_t mem_alignment;
};

