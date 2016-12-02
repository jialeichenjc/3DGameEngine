#include "Utility.h"

void* Utility::operator new(const size_t size) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	return allocator->alloc_mem(size);
}

void Utility::operator delete(void *ptr) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	allocator->free_mem(ptr);
}


Utility::Utility()
{
}


Utility::~Utility()
{
}
