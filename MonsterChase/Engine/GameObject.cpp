#include "GameObject.h"
#include "MemoryAllocator.h"
#include "FixedSizeAllocator.h"
bool GameObject::on_fsa_allocator = false;
bool GameObject::on_mem_allocator = false;
GameObject::GameObject() : position(0.0, 0.0) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	name = (char*)allocator->alloc_mem(20);

};

void* GameObject::operator new(const size_t size) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();
	if (size < fsa_allocator->allocator_size) {
		on_fsa_allocator = true;
		return fsa_allocator->alloc_mem(size);
	}
	on_mem_allocator = true;
	return allocator->alloc_mem(size);
}

void* GameObject::operator new(const size_t size, const size_t alignment_size) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	allocator->set_alignment_size(alignment_size);
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();
	fsa_allocator->set_alignment_size(alignment_size);
	if (size < fsa_allocator->allocator_size) {
		on_fsa_allocator = true;
		return fsa_allocator->alloc_mem(size);
	}
	on_mem_allocator = true;
	return allocator->alloc_mem(size);
}

void GameObject::operator delete(void *ptr) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();
	
	on_mem_allocator ? allocator->free_mem(ptr) : fsa_allocator->free_mem(ptr);
}

void* GameObject::operator new[](const size_t size) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();
	if (size <= fsa_allocator->allocator_size) {
		on_fsa_allocator = true;
		return fsa_allocator->alloc_mem(size);
	}
	on_mem_allocator = true;
	return allocator->alloc_mem(size);
}

void GameObject::operator delete[](void *ptr) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();

	on_mem_allocator ? allocator->free_mem(ptr) : fsa_allocator->free_mem(ptr);
}
