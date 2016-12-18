#pragma once
#include <malloc.h>
#include <new>
#include <stdint.h>
#define MEMORY_TOTAL 1024*1024
class BitArray;
// Fixed Size Memory Allocator
class FixedSizeAllocator
{
public:
	static FixedSizeAllocator* get_instance();
	//static FixedSizeAllocator* get_instance(const size_t alignment_size);

	void create_heap(const size_t heap_size, const uint8_t alignment);
	// analogous to malloc()
	void* alloc_mem(const size_t req_size);
	// analogous to free()
	void free_mem(void* p_mem);

	static void destroy_instance();
	static uint8_t alignment_size;
	~FixedSizeAllocator();

private:
	static FixedSizeAllocator* p_fsa_instance;
	BitArray* bit_array; // the bit array that describes the current state of the heap
	char* base_ptr; // points to the beginning of the heap
	size_t allocator_size; // block size of this allocator
	FixedSizeAllocator();
};

