#include "PhysicsWorld.h"
#include "../Debug.h"
PhysicsWorld::PhysicsWorld()
{
}

void PhysicsWorld::AddToCollidables(const Collidable & i_Collidable) {
	m_CollidableObjects.push_back(i_Collidable);
}

void PhysicsWorld::RemoveFromCollidables(const Collidable & i_Collidable) {
	auto it = std::find(m_CollidableObjects.begin(), m_CollidableObjects.end(), i_Collidable);
	if (it != m_CollidableObjects.end()) {
		m_CollidableObjects.erase(it);
	}
#ifdef _DEBUG
	else {
		log_error("Attempting to erase a non-included collidable");
	}
#endif // _DEBUG

}

std::vector<Collidable> & PhysicsWorld::GetAllCollidables() {
	return m_CollidableObjects;
}

PhysicsWorld::~PhysicsWorld()
{
}
