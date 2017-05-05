#pragma once
#include "AxisAlignedBoundingBox.h"
#include "OrientedBoundingBox.h"
#include "Collidable.h"

class CollisionHandler
{
public:

	CollisionHandler() : XSeparated(false), YSeparated(false), ZSeparated(false) {

	}

	bool CheckCollision(AxisAlignedBoundingBox & i_AABB_1, AxisAlignedBoundingBox & i_AABB_2);
	bool CheckCollision(Collidable & i_Collidable_1, Collidable & i_Collidable_2);

	// handles collision
	void OnCollision(Collidable & i_Collidable_1, Collidable & i_Collidable_2);

	// high level handler, check for collision and handles it if collision occurs
	void HandleCollision(Collidable & i_Collidable_1, Collidable & i_Collidable_2);

	~CollisionHandler() {};

	bool XSeparated;
	bool YSeparated;
	bool ZSeparated;
};
