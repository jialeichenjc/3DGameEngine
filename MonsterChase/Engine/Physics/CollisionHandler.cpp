#include "CollisionHandler.h"

bool CollisionHandler::CheckCollision(AxisAlignedBoundingBox & i_AABB_1, AxisAlignedBoundingBox & i_AABB_2) {
	Vector3D l_max = i_AABB_1.GetMaxPosition();
	Vector3D l_min = i_AABB_1.GetMinPosition();
	Vector3D r_max = i_AABB_2.GetMaxPosition();
	Vector3D r_min = i_AABB_2.GetMinPosition();

	// compare the max and min of the two objects along each axis 
	// to see if there's any axis along which the projection does not overlap
	// Separating axis parallel to Y 
	if (l_max.x() < r_min.x() || r_max.x() < l_min.x()) {
		YSeparated = true;
		return false;
	}
	if (l_max.y() < r_min.y() || r_max.y() < l_min.y()) {
		XSeparated = true;
		return false;
	}

	if (
		(l_max.x() >= r_min.x() && l_min.x() <= r_min.x())
		|| (r_max.x() >= l_min.x() && r_min.x() <= l_min.x())
		&& YSeparated
		) {
		//l_max.x() == r_min.x() || r_max.x() == l_min.x()) {
		// collision occurs on the y-axis of AABB's
		i_AABB_1.SetCollidingVec(Vector3D(-1.0f, 1.0f, 1.0f));
		i_AABB_2.SetCollidingVec(Vector3D(-1.0f, 1.0f, 1.0f));
		YSeparated = false;
		return true;
	}

	// collision detected
	else if (
		(r_max.y() >= l_min.y() && r_min.y() <= l_min.y())
		|| (l_max.y() >= r_min.y() && l_min.y() <= r_min.y())
		&& XSeparated
		) {
		// collision occurs on the x-axis of AABB's
		i_AABB_1.SetCollidingVec(Vector3D(1.0f, -1.0f, 1.0f));
		i_AABB_2.SetCollidingVec(Vector3D(1.0f, -1.0f, 1.0f));
		XSeparated = false;
		return true;
	}
}

bool CollisionHandler::CheckCollision(Collidable & i_Collidable_1, Collidable & i_Collidable_2) {
	return CheckCollision(i_Collidable_1.GetAABB(), i_Collidable_2.GetAABB());
}

void CollisionHandler::OnCollision(Collidable & i_Collidable_1, Collidable & i_Collidable_2) {
	if (i_Collidable_1.IsBouncy()) {
		i_Collidable_1.ChangeVelocityDirection(i_Collidable_1.GetAABB().GetCollidingVec());
	}
	else {
		i_Collidable_1.ChangeVelocityDirection(Vector3D(0.0f, 0.0f, 0.0f));
	}

	if (i_Collidable_2.IsBouncy()) {
		i_Collidable_2.ChangeVelocityDirection(i_Collidable_2.GetAABB().GetCollidingVec());
	}
	else {
		i_Collidable_2.ChangeVelocityDirection(Vector3D(0.0f, 0.0f, 0.0f));
	}

	//YSeparated = true;
	//XSeparated = true;
}

void CollisionHandler::HandleCollision(Collidable & i_Collidable_1, Collidable & i_Collidable_2) {
	if (CheckCollision(i_Collidable_1, i_Collidable_2)) {
		OnCollision(i_Collidable_1, i_Collidable_2);
	}
}