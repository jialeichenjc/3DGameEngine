#pragma once
#include <vector>
class Collidable;
class PhysicsWorld
{
public:
	PhysicsWorld();
	void AddToCollidables(const Collidable & i_Collidable);
	void RemoveFromCollidables(const Collidable & i_Collidable);
	std::vector<Collidable> & GetAllCollidables() const;
	~PhysicsWorld();

private:
	std::vector<Collidable> m_CollidableObjects;
};

