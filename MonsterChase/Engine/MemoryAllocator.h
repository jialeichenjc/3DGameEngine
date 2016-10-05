#pragma once
#include "BlockDescriptor.h"
class MemoryAllocator
{
public:
	MemoryAllocator();
	void* alloc_mem(size_t req_size);
	void free_mem(void *mem_ptr);
	~MemoryAllocator();
};

