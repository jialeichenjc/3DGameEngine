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
	void* alloc_mem(size_t req_size);
	void free_mem(void *mem_ptr);
	~MemoryAllocator();

	void printHeap();
	
	// They aren't currently describing a block of memory but available when new blocks are created
	BlockDescriptorList bd_idle;

	// A list of BLockDescriptors describing blocks of memory available to allocate from
	BlockDescriptorList mem_free;

	// A list of BlockDescriptors describing blocks of memory outstanding, in use by the user
	BlockDescriptorList mem_in_use;

private:
	//put the list of block descriptors at the beginning of the memory blocks.
	void set_Block_Descriptor_List();
};

