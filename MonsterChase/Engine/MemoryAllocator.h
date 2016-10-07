#pragma once
#include "BlockDescriptor.h"
#include "BlockDescriptorList.h"
#define MEMORY_TOTAL 256
class MemoryAllocator
{
public:
	MemoryAllocator();
	void* alloc_mem(size_t req_size);
	void free_mem(void *mem_ptr);
	~MemoryAllocator();
	static char total_mem[MEMORY_TOTAL];
	//void set_up_bd_idle(int num_total_bd);

	// A list of available BlockDescriptors
	// They aren't currently describing a block of memory but available when new blocks are created
	BlockDescriptorList bd_idle;

	// A list of BLockDescriptors describing blocks of memory available to allocate from
	BlockDescriptorList mem_free;

	// A list of BlockDescriptors describing blocks of memory outstanding, in use by the user
	BlockDescriptorList mem_in_use;
};

