#pragma once
#include "MemoryAllocator.h"
// standard new/delete
void* operator new(size_t size);
void operator delete(void *ptr);

// standard array new/delete
void* operator new[](size_t size);
void operator delete[](void *ptr);

enum NewAlignment {
	NEW_ALIGN_DEFAULT,
	NEW_ALIGN_16 = 16,
	NEW_ALIGN_32 = 32
};

// new and delete with alignment
void* operator new(size_t size, NewAlignment alignment);
void operator delete(void *ptr, NewAlignment alignment);


