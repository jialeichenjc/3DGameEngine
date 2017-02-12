#pragma once
#include <string.h>
#include "Vector2D.h"
#include "FixedSizeAllocator.h"
class MemoryAllocator;
class FixedSizeAllocator;
class GameObject {
public:
	GameObject();
	void set_name(const char* name);
	const char* get_name() const;
	Vector2D get_position() const;
	void set_position(const Vector2D &vec);
	void move_next(const Vector2D &delta_vec); // move game object by delta_x and delta_y

	void* operator new(const size_t size);
	void* operator new(const size_t size, const size_t alignment_size);
	void operator delete(void* ptr);
	void* operator new[](const size_t size);
	void operator delete[](void *ptr);

	~GameObject() {
		if (name) {
			MemoryAllocator* allocator = MemoryAllocator::get_instance();
			FixedSizeAllocator* fsa_allocator = FixedSizeAllocator::get_instance();
			on_mem_allocator ? allocator->free_mem((void*)name) : fsa_allocator->free_mem((void*)name);
		}
	};

protected:
	Vector2D position; // a 2D vector representing the position {x_coord, y_coord}
private:
	const char *name;
	static bool on_mem_allocator; // true if game object is allocated through memory allocator
	static bool on_fsa_allocator; // true if game object is allocated through fsa allocator
};

inline void GameObject::set_name(const char* name) {
	this->name = name;
}

inline const char* GameObject::get_name() const {
	return name;
}

inline Vector2D GameObject::get_position() const {
	return position;
}

inline void GameObject::set_position(const Vector2D &vec) {
	this->position = vec;
}

inline void GameObject::move_next(const Vector2D &delta_vec) {
	position = position + delta_vec;
}
