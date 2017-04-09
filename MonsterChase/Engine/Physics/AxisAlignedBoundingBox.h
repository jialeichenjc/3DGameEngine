#pragma once
#include "VectorMath.h"
class AxisAlignedBoundingBox
{
public:
	AxisAlignedBoundingBox();
	Vector3D & GetMaxPosition() const;
	Vector3D & GetMinPosition() const;
	void SetMaxPosition(const Vector3D & i_max);
	void SetMinPosition(const Vector3D & i_min);
	~AxisAlignedBoundingBox();
private:
	Vector3D m_MaxPosition;
	Vector3D m_MinPosition;
};

