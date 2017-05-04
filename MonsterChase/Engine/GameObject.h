#pragma once
#include <string.h>
#include "Math/Vector3D.h"
#include "MemoryManager/FixedSizeAllocator.h"
#include "lua.hpp"
#include "GLib.h"

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

	// sprite rendering
	void SetSprite(const GLib::Sprites::Sprite *i_sprite);
	const GLib::Sprites::Sprite* GetSprite() const;

	// physics velocity
	void SetVelocity(const Vector3D & i_vec);
	void SetVelocity(float i_x, float i_y, float i_z);
	Vector3D GetVelocity() const;
	void MoveWithVelocity();

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
	Vector3D position; // a 3D vector representing the position {x_coord, y_coord}
	Vector3D m_Velocity;

private:
	const char *name;
	const GLib::Sprites::Sprite * m_pSprite;
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

inline void GameObject::SetVelocity(const Vector3D & i_vec) {
	m_Velocity = i_vec;
}

inline void GameObject::SetVelocity(float i_x, float i_y, float i_z) {
	m_Velocity = Vector3D(i_x, i_y, i_z);
}

inline Vector3D GameObject::GetVelocity() const {
	return m_Velocity;
}

inline void GameObject::MoveWithVelocity() {
	Move(m_Velocity);
}