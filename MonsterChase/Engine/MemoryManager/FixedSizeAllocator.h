#pragma once
#include <malloc.h>
#include <new>
#include <stdint.h>
#define MEMORY_TOTAL 1024*1024
class BitArray;
class MemoryAllocator;
// Fixed Size Memory Allocator
class FixedSizeAllocator
{
public:
	static FixedSizeAllocator* get_instance();

	void create_heap(const size_t heap_size, const uint8_t alignment);
	// analogous to malloc()
	void* alloc_mem(const size_t req_size);
	// analogous to free()
	bool free_mem(void* p_mem);

	void set_alignment_size(const uint8_t);

	// override new and delete to use memory allocator
	void* operator new(const size_t size);
	void operator delete(void* ptr);

	static void destroy_instance();
	size_t allocator_size; // block size of this allocator
	~FixedSizeAllocator();

private:
	static MemoryAllocator *p_mem_allocator;
	static FixedSizeAllocator* p_fsa_instance;
	uint8_t alignment_size;
	static BitArray* bit_array; // the bit array that describes the current state of the heap
	char* base_ptr; // points to the beginning of the heap
	FixedSizeAllocator();
};

