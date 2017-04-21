#pragma once
#include "AxisAlignedBoundingBox.h"
#include "../GameObject.h"
#include <string>

class Collidable
{
public:
	Collidable() = default;
	Collidable(GameObject * i_GameObject, const float i_Size) : m_GameObject(i_GameObject),
		m_Size(i_Size) {}

	inline std::string GetName() const { return name; }
	inline std::string SetName(const std::string & i_str) { name = i_str; }
	inline bool operator == (const Collidable & i_col) { return this->name == i_col.GetName(); }
	~Collidable() {};

private:
	GameObject * m_GameObject;
	AxisAlignedBoundingBox m_AABB;
	float m_Size; // size of the collision box (AABB / OBB)
	std::string name;
};

