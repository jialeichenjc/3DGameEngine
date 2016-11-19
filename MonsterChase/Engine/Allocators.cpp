#include "Allocators.h"
#include "Debug.h"
MemoryAllocator mem_allocator;
// standard new & delete
void* operator new(size_t size) {
	DEBUG_PRINT("Calling new(size_t) with (%Iu).\n", size);
	return mem_allocator.alloc_mem(size);
}

void operator delete(void *ptr) {
	DEBUG_PRINT("Calling delete( void * ) with (%p).\n", ptr);
	if (ptr) {
		mem_allocator.free_mem(ptr);
	}
}

void *operator new[](size_t size) {
	DEBUG_PRINT("Calling new[](size_t) with (%Iu).\n", size);
	return mem_allocator.alloc_mem(size);
}

void operator delete[](void *ptr) {
	DEBUG_PRINT("Calling delete( void * ) with (%p).\n", ptr);
	if (ptr) {
		mem_allocator.free_mem(ptr);
	}
}
