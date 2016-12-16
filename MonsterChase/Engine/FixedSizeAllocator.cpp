#include "FixedSizeAllocator.h"
#define INCLUDE_GUARDBAND false
#if defined(_DEBUG)
#define INCLUDE_GUARDBAND true
#endif
#define HEAP_SIZE 1024 * 1024
#define TOTAL_NUM_BLOCK_DESCRIPTORS 2000
#define DEFAULT_ALIGNMENT_SIZE 4
#define GUARD_BAND_SIZE 4
#define GUARD_BAND_VALUE 0XFFFFFFFF

static char* heap;
FixedSizeAllocator* FixedSizeAllocator::p_fsa_instance = nullptr;
uint8_t FixedSizeAllocator::alignment_size = DEFAULT_ALIGNMENT_SIZE;
FixedSizeAllocator::FixedSizeAllocator()
{
}

FixedSizeAllocator* FixedSizeAllocator::get_instance() {
	if (p_fsa_instance == nullptr) {
		p_fsa_instance = new FixedSizeAllocator();
	}
	return p_fsa_instance;
}

void FixedSizeAllocator::create_heap(size_t heap_size, uint8_t alignment) {
	heap = (char*)malloc(heap_size);
	alignment_size = alignment;
}

void FixedSizeAllocator::destroy_instance() {
	delete p_fsa_instance;
	p_fsa_instance = nullptr;
}

FixedSizeAllocator::~FixedSizeAllocator()
{
	free(heap);
}
