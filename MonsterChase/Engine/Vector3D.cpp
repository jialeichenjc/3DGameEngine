#include "Vector3D.h"

void Vector3D::operator = (const Vector3D& i_lvec) {
	this->x_coord = i_lvec.x();
	this->y_coord = i_lvec.y();
	this->z_coord = i_lvec.z();
}