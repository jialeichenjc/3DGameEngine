#pragma once
#include "AxisAlignedBoundingBox.h"
#include "OrientedBoundingBox.h"
#include "Collidable.h"
namespace Collision
{

	// Check for collision between two AABB's
	bool CheckCollision(AxisAlignedBoundingBox & i_AABB_1, AxisAlignedBoundingBox & i_AABB_2);

	bool CheckCollision(const Collidable & i_Collidable_1, const Collidable & i_Collidable_2);
	bool CheckCollision(OrientedBoundingBox & i_OBB_1, OrientedBoundingBox & i_OBB_2);

	// handles collision
	void OnCollision(Collidable & i_Collidable_1, Collidable & i_Collidable_2);

	// high level handler, check for collision and handles it if collision occurs
	void HandleCollision(Collidable & i_Collidable_1, Collidable & i_Collidable_2);
};

