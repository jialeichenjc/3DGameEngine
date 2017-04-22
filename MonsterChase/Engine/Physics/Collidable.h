#pragma once
#include "AxisAlignedBoundingBox.h"
#include "../GameObject.h"
#include <string>

class Collidable
{
public:
	Collidable() = default;
	Collidable(GameObject * i_GameObject, const float i_SizeX, const float i_SizeY, const float i_SizeZ) 
		: m_GameObject(i_GameObject), m_SizeX(i_SizeX), m_SizeY(i_SizeY), m_SizeZ(i_SizeZ) {
		m_Name = i_GameObject->get_name();
		m_Position = i_GameObject->get_position();
		InitAABB();
	}

	void InitAABB(); // initilize the AABB representation
	inline std::string GetName() const { return m_Name; }
	inline std::string SetName(const std::string & i_str) { m_Name = i_str; }
	inline bool operator == (const Collidable & i_col) { return this->m_Name == i_col.GetName(); }
	~Collidable() {};

private:
	GameObject * m_GameObject;
	AxisAlignedBoundingBox m_AABB;
	Vector3D m_Position;
	float m_SizeX; // size of the collision box (AABB / OBB)
	float m_SizeY;
	float m_SizeZ;
	Vector3D m_MinPosition;
	Vector3D m_MaxPosition;

	std::string m_Name;
};

