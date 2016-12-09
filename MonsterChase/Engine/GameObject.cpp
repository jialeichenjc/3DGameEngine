#include "GameObject.h"
MemoryAllocator* GameObject::p_mem_allocator = NULL;

GameObject::GameObject() : position(0.0, 0.0) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	name = (char*)allocator->alloc_mem(20);

};

inline void GameObject::create_mem_allocator(size_t alignment) {
	if (p_mem_allocator == NULL) {
		MemoryAllocator* allocator = MemoryAllocator::get_instance();
		p_mem_allocator = allocator;
	}
}

void* GameObject::operator new(const size_t size) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	
	return allocator->alloc_mem(size);
}

void GameObject::operator delete(void *ptr) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();

	allocator->free_mem(ptr);
}

/*
void* GameObject::operator new(const size_t size) {
	MemoryAllocator allocator(4);
	if (p_mem_allocator == NULL) {
		// TODO: fix this...magic number 4
		p_mem_allocator = &allocator;
	}
	void *p_mem = p_mem_allocator->alloc_mem(size);
	if (p_mem == NULL) {
		throw "Not enough memory";
	}
	return p_mem;
}

void* GameObject::operator new[](const size_t size) {
	void *p_mem = p_mem_allocator->alloc_mem(size);
	if (p_mem == NULL) {
		throw "Not enough memory";
	}
	return p_mem;
}

void GameObject::operator delete(void *ptr) {
	p_mem_allocator->free_mem(ptr);
}

void GameObject::operator delete[](void *ptr) {
	p_mem_allocator->free_mem(ptr);
}
*/