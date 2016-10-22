#include "MemoryAllocatorTest.h"

void MemoryAllocatorTest::test_mem_alloc(int num_allocation) {
	for (int i = 0; i < num_allocation; i++) {
		size_t requested_size = rand() % 100 + 1;
		allocator.alloc_mem(requested_size);
	}
	assert(allocator.in_use_bd_list.size == num_allocation, "Wrong allocation");
	printf("free block descriptor size %zu", allocator.free_mem_bd_list.size);
	//no free operation is performed yet, one free block descriptor points to entire memory 
	assert(allocator.free_mem_bd_list.size == 1, "Wrong free block descriptor size");
}

void MemoryAllocatorTest::test_free_alloc(int num_free) {
	for (int i = 0; i < num_free; i++) {
		size_t requested_size = rand() % 100 + 1;
		char *test_ptr = static_cast<char*> (allocator.alloc_mem(requested_size));
		allocator.free_mem(test_ptr);
	}
}

MemoryAllocatorTest::MemoryAllocatorTest()
{
}


MemoryAllocatorTest::~MemoryAllocatorTest()
{
}
