#include "FixedSizeAllocator.h"
#include <intrin.h>
#include "BitArray.h"
#include "MemoryAllocator.h"
#include "Debug.h"
#define HEAP_SIZE 1024 * 256
#define DEFAULT_ALIGNMENT_SIZE 4
#define DEFAULT_ALLOCATOR_SIZE 8
#define NUM_OF_BITS 256
#define NUM_BLOCK 1 //allocates 1 block per allocation

static char* heap = nullptr;
FixedSizeAllocator* FixedSizeAllocator::p_fsa_instance = nullptr;
MemoryAllocator* FixedSizeAllocator::p_mem_allocator = nullptr;
BitArray* FixedSizeAllocator::bit_array = nullptr;
FixedSizeAllocator::FixedSizeAllocator()
{
	// create a bit array for this allocator
	bit_array = BitArray::get_instance(NUM_OF_BITS, false);
	allocator_size = DEFAULT_ALLOCATOR_SIZE;
}

FixedSizeAllocator* FixedSizeAllocator::get_instance() {
	if (p_fsa_instance == nullptr) {
		p_fsa_instance = new FixedSizeAllocator();
	}
	return p_fsa_instance;
}

void FixedSizeAllocator::create_heap(const size_t heap_size, const uint8_t alignment) {
	p_mem_allocator = MemoryAllocator::get_instance();
	// fixed size allocator shares the same heap as the memory allocator
	base_ptr = static_cast<char*>(p_mem_allocator->alloc_mem(heap_size));
	alignment_size = alignment;
}

void FixedSizeAllocator::set_alignment_size(const uint8_t i_alignment) {
	alignment_size = i_alignment;
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

bool FixedSizeAllocator::free_mem(void *p_mem) {
	size_t offset = (static_cast<char*>(p_mem) - base_ptr) / allocator_size;
	bit_array->set_bits_to_one(offset, NUM_BLOCK);
	return true;
}

void* FixedSizeAllocator::operator new(const size_t size) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();

	return allocator->alloc_mem(size);
}

void FixedSizeAllocator::operator delete(void* ptr) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();

	allocator->free_mem(ptr);
}

void FixedSizeAllocator::destroy_instance() {
#if defined(_DEBUG)
	if (!bit_array->are_all_one()) {
		//log_error("outstanding memory when FSA is being destroyed");
	}
#endif
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	allocator->free_mem(p_fsa_instance);

	p_fsa_instance = nullptr;
	bit_array->destroy_instatnce();
}

FixedSizeAllocator::~FixedSizeAllocator()
{
}
