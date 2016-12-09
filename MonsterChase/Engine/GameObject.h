#pragma once
#include <string.h>
#include "Vector2D.h"
#include "MemoryAllocator.h"
class GameObject {
public:
	GameObject();
	void set_name(const char* name);
	const char* get_name() const;
	Vector2D get_position() const;
	static void create_mem_allocator(size_t alignment);
	void set_position(const Vector2D &vec);
	void move_next(const Vector2D &delta_vec); // move game object by delta_x and delta_y

	void* operator new(const size_t size);
	void operator delete(void* ptr);
	//void* operator new[](const size_t size);
	//void operator delete[](void *ptr);

	~GameObject() {
		if (name) {
			MemoryAllocator* allocator = MemoryAllocator::get_instance();
			allocator->free_mem((void*)name);
		}
	};

protected:
	Vector2D position; // a 2D vector representing the position {x_coord, y_coord}
private:
	const char *name;
	static MemoryAllocator *p_mem_allocator;
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
