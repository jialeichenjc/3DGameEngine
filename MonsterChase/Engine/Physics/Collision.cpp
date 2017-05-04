#include "Collision.h"

bool Collision::CheckCollision(AxisAlignedBoundingBox & i_AABB_1, AxisAlignedBoundingBox & i_AABB_2) {
	Vector3D l_max = i_AABB_1.GetMaxPosition();
	Vector3D l_min = i_AABB_1.GetMinPosition();
	Vector3D r_max = i_AABB_2.GetMaxPosition();
	Vector3D r_min = i_AABB_2.GetMinPosition();

	// compare the max and min of the two objects along each axis 
	// to see if there's any axis along which the projection does not overlap
	// Separating axis parallel to Y 
	if (l_max.x() < r_min.x() || r_max.x() < l_min.x()) {
		return false; 
	}
	else if (l_max.y() < r_min.y() || r_max.y() < l_min.y()) {
		return false;
	}
	else if (l_max.z() < r_min.z() || r_max.z() < l_min.z()) {
		return false;
	}
	// if no separating axis were found
	else if (   
		(l_max.x() >= r_min.x() && l_min.x() <= r_min.x())
		|| (r_max.x() >= l_min.x() && r_min.x() <= l_min.x())
		) {
		// collision occurs on the x-axis of AABB's
		i_AABB_1.SetCollidingVec(Vector3D(-1.0f, 1.0f, 1.0f));
		i_AABB_2.SetCollidingVec(Vector3D(-1.0f, 1.0f, 1.0f));
		return true;
	}

	else if (
		(r_max.y() >= l_min.y() && r_min.y() <= l_min.y()) 
		|| (l_max.y() >= r_min.y() && l_min.y() <= r_min.y())
		) {
		// collision occurs on the y-axis of AABB's
		i_AABB_1.SetCollidingVec(Vector3D(1.0f, -1.0f, 1.0f));
		i_AABB_2.SetCollidingVec(Vector3D(1.0f, -1.0f, 1.0f));
		return true;
	}

	else if (
		(r_max.z() >= l_min.z() && r_min.z() <= l_min.z())
		|| (l_max.z() >= r_min.z() && l_min.z() <= r_min.z())
		) {
		// collision occurs on the z-axis of AABB's
		i_AABB_1.SetCollidingVec(Vector3D(1.0f, 1.0f, -1.0f));
		i_AABB_2.SetCollidingVec(Vector3D(1.0f, 1.0f, -1.0f));
		return true;
	}
	return false;

}
