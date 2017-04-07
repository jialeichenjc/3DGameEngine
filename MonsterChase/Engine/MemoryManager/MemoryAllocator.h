#pragma once
#include "BlockDescriptor.h"
#include "BlockDescriptorList.h"
#include <malloc.h>
#include <new>
#include <stdint.h>
#define MEMORY_TOTAL 1024*1024
class MemoryAllocator
{
public:
	// make Memory Allocator a singleton class
	static MemoryAllocator* get_instance();
	static MemoryAllocator* get_instance(const size_t alignment_size);
	void create_heap(const size_t heap_size);
	static void destroy_instance();
	void init();
	void set_alignment_size(const size_t alignment_size);
	void* alloc_mem(const size_t req_size);
	bool free_mem(void *mem_ptr);
	void coalesce_mem(); // acts like a garbage collector
	~MemoryAllocator();

	void printHeap() const;
	void print_list(BlockDescriptorList list) const;
	
	// They aren't currently describing a block of memory but available when new blocks are created
	BlockDescriptorList available_bd_list;

	// A list of BLockDescriptors describing blocks of memory available to allocate from
	BlockDescriptorList free_mem_bd_list;

	// A list of BlockDescriptors describing blocks of memory outstanding, in use by the user
	BlockDescriptorList in_use_bd_list;

	// a block descriptor for the heap, always points to the first memory address in the heap (after 
	// the memory allocated to all the block descriptors)
	BlockDescriptor heap_mem_bd; 

private:
	MemoryAllocator();
	MemoryAllocator(size_t alignment_size);
	static MemoryAllocator *p_instance;
	size_t mem_alignment;
};


