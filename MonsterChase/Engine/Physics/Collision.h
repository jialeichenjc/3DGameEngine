#pragma once
#include "AxisAlignedBoundingBox.h"
#include "OrientedBoundingBox.h"
namespace Collision
{

	// Check for collision between two AABB's
	bool CheckCollision(AxisAlignedBoundingBox & i_AABB_1, AxisAlignedBoundingBox & i_AABB_2);

	bool CheckCollision(AxisAlignedBoundingBox & i_AABB, OrientedBoundingBox & i_OBB);
	bool CheckCollision(OrientedBoundingBox & i_OBB_1, OrientedBoundingBox & i_OBB_2);

};

