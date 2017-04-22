#include "Collidable.h"
void Collidable::InitAABB() {
	float MaxX = m_Position.x() + m_SizeX / 2.0f;
	float MaxY = m_Position.y() + m_SizeY / 2.0f;
	float MaxZ = m_Position.z() + m_SizeY / 2.0f;
	float MinX = m_Position.x() - m_SizeX / 2.0f;
	float MinY = m_Position.y() - m_SizeY / 2.0f;
	float MinZ = m_Position.z() - m_SizeZ / 2.0f;

	m_MaxPosition.set_x(MaxX);
	m_MaxPosition.set_y(MaxY);
	m_MaxPosition.set_z(MaxZ);
	
	m_MinPosition.set_x(MinX);
	m_MinPosition.set_y(MinY);
	m_MinPosition.set_z(MinZ);

	m_AABB = AxisAlignedBoundingBox(m_MaxPosition, m_MinPosition);
}