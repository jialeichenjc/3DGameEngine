#pragma once
#include "../MemoryManager/MemoryAllocator.h"
#include "../Debug.h"
class MemoryAllocatorTest
{
public:
	void test_mem_alloc(int num_allocation);
	void test_free_alloc(int num_free);

	MemoryAllocatorTest();
	~MemoryAllocatorTest();
};

