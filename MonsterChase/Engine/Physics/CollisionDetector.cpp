#include "CollisionDetector.h"



CollisionDetector::CollisionDetector()
{
}

bool CollisionDetector::CheckCollision(AxisAlignedBoundingBox & i_AABB_1, AxisAlignedBoundingBox & i_AABB_2) {
	Vector3D l_max = i_AABB_1.GetMaxPosition();
	Vector3D l_min = i_AABB_1.GetMinPosition();
	Vector3D r_max = i_AABB_2.GetMaxPosition();
	Vector3D r_min = i_AABB_2.GetMinPosition();

	// compare the max and min of the two objects along each axis 
	// to see if there's any axis along which the projection does not overlap
	if (l_max.x() < r_min.x() || r_max.x() < l_min.x()) {
		return true;
	}
	else if (l_max.y() < r_min.y() || r_max.y() < l_min.y()) {
		return true;
	}
	else if (l_max.z() < r_min.z() || r_max.z() < l_min.z()) {
		return true;
	}

	return false;

}

CollisionDetector::~CollisionDetector()
{
}
