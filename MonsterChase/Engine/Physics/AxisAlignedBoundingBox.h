#pragma once
#include "VectorMath.h"
class AxisAlignedBoundingBox
{
public:
	AxisAlignedBoundingBox() = default;
	AxisAlignedBoundingBox(const Vector3D & i_max, const Vector3D & i_min) {
		m_MaxPosition = i_max;
		m_MinPosition = i_min;
	}
	inline Vector3D GetMaxPosition() const { return m_MaxPosition; }
	inline Vector3D GetMinPosition() const { return m_MinPosition; }

	inline void SetMaxPosition(const Vector3D & i_max) { m_MaxPosition = i_max; }
	inline void SetMinPosition(const Vector3D & i_min) { m_MinPosition = i_min; }
	inline Vector3D GetCollidingVec() { return m_CollidingVec; }
	inline void SetCollidingVec(const Vector3D & i_vec) { m_CollidingVec = i_vec; }

	~AxisAlignedBoundingBox() {};

private:
	Vector3D m_MaxPosition;
	//Vector3D m_MaxPosition_y;
	//Vector3D m_MaxPosition_z;

	//Vector3D m_MinPosition_x;
	//Vector3D m_MinPosition_y;
	Vector3D m_MinPosition;

	Vector3D m_CollidingVec; // Handles collision on all three axis
};

