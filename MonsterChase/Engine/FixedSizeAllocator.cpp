#include "FixedSizeAllocator.h"
#include <intrin.h>
#include "BitArray.h"
#include "Debug.h"
#define HEAP_SIZE 1024 * 256
#define DEFAULT_ALIGNMENT_SIZE 4
#define GUARD_BAND_SIZE 4
#define GUARD_BAND_VALUE 0XFFFFFFFF
#define NUM_BLOCK 1 //allocates 1 block per allocation

static char* heap = nullptr;
FixedSizeAllocator* FixedSizeAllocator::p_fsa_instance = nullptr;
uint8_t FixedSizeAllocator::alignment_size = DEFAULT_ALIGNMENT_SIZE;
FixedSizeAllocator::FixedSizeAllocator()
{
	// create 256 bits for this allocator
	bit_array = BitArray::get_instance(256, false);
	allocator_size = 16;
}

FixedSizeAllocator* FixedSizeAllocator::get_instance() {
	if (p_fsa_instance == nullptr) {
		p_fsa_instance = new FixedSizeAllocator();
	}
	return p_fsa_instance;
}

void FixedSizeAllocator::create_heap(const size_t heap_size, const uint8_t alignment) {
	heap = (char*)malloc(heap_size);
	base_ptr = heap;
	alignment_size = alignment;
}

void* FixedSizeAllocator::alloc_mem(const size_t req_size) {
	void* mem_ptr = nullptr;
	
	// this FSA only handles allocation of small size memory
	if (req_size > allocator_size) {
		log_error("requested size exceeds allocator size");
		return mem_ptr;
	}
	// Make sure there is a heap, create one if not defined by the user
	if (heap == nullptr) {
		create_heap(HEAP_SIZE, DEFAULT_ALIGNMENT_SIZE);
	}
	
	size_t offset = bit_array->get_set_bit_offset();
	mem_ptr = base_ptr + offset * allocator_size;
	
	// set the corresponding bits to zero to indicate memory in use
	bit_array->set_bits_to_zero(offset, NUM_BLOCK);
	
	// Find the first set bit in the bit array
	return mem_ptr;
}

void FixedSizeAllocator::free_mem(void *p_mem) {
	size_t offset = (static_cast<char*>(p_mem) - base_ptr) / allocator_size;
	bit_array->set_bits_to_one(offset, NUM_BLOCK);
	p_mem = nullptr;
}

void FixedSizeAllocator::destroy_instance() {
	delete p_fsa_instance;
	p_fsa_instance = nullptr;
}

FixedSizeAllocator::~FixedSizeAllocator()
{
	free(heap);
}
