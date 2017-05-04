#include "Collidable.h"
#include "Collision.h"

void Collidable::InitAABB() {
	float MaxX = m_Position->x() + m_SizeX / 2.0f;
	float MaxY = m_Position->y() + m_SizeY / 2.0f;
	float MaxZ = m_Position->z() + m_SizeY / 2.0f;
	float MinX = m_Position->x() - m_SizeX / 2.0f;
	float MinY = m_Position->y() - m_SizeY / 2.0f;
	float MinZ = m_Position->z() - m_SizeZ / 2.0f;

	m_MaxPosition->set_x(MaxX);
	m_MaxPosition->set_y(MaxY);
	m_MaxPosition->set_z(MaxZ);
	
	m_MinPosition->set_x(MinX);
	m_MinPosition->set_y(MinY);
	m_MinPosition->set_z(MinZ);

	m_AABB = AxisAlignedBoundingBox(m_MaxPosition, m_MinPosition);
}

void Collidable::UpdateAABB() {
	InitAABB();
}

Vector3D Collidable::GetPosition() {
	return m_pGameObject->GetPosition();
}

void Collidable::SetVelocity(float i_VeloX, float i_VeloY, float i_VeloZ) {
	m_pGameObject->SetVelocity(Vector3D(i_VeloX, i_VeloY, i_VeloZ));
}

void Collidable::ChangeVelocityDirection(const Vector3D & i_DeltaVec) {
	Vector3D Velo = m_pGameObject->GetVelocity();
	m_pGameObject->SetVelocity(Velo.x() * i_DeltaVec.x(), Velo.y() * i_DeltaVec.y(),
		Velo.z() * i_DeltaVec.z());
}