#pragma once
#include <string.h>
#include "Math/Vector3D.h"
#include "MemoryManager/FixedSizeAllocator.h"
#include "lua.hpp"
class MemoryAllocator;
class FixedSizeAllocator;
class GameObject {
public:
	GameObject();
	void SetName(const char * name);
	const char* GetName() const;
	Vector3D GetPosition() const;
	void SetPosition(const Vector3D &vec);
	void Move(const Vector3D &delta_vec); // move game object by delta_x and delta_y

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
	Vector3D position; // a 2D vector representing the position {x_coord, y_coord}
private:
	const char *name;
	static bool on_mem_allocator; // true if game object is allocated through memory allocator
	static bool on_fsa_allocator; // true if game object is allocated through fsa allocator
};

inline void GameObject::SetName(const char * name) {
	this->name = name;
}

inline const char* GameObject::GetName() const {
	return name;
}

inline Vector3D GameObject::GetPosition() const {
	return position;
}

inline void GameObject::SetPosition(const Vector3D &vec) {
	this->position = vec;
}

inline void GameObject::Move(const Vector3D &delta_vec) {
	position = position + delta_vec;
}
