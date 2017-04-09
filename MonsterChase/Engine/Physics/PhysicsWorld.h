#pragma once
#include <vector>
#include "Collidable.h"
class PhysicsWorld
{
public:
	PhysicsWorld();
	void AddToCollidables(const Collidable & i_Collidable);
	void RemoveFromCollidables(const Collidable & i_Collidable);
	std::vector<Collidable> & PhysicsWorld::GetAllCollidables();

	~PhysicsWorld();

private:
	std::vector<Collidable> m_CollidableObjects;
};

