#include "Vector2D.h"

Vector2D::~Vector2D() {
}

void Vector2D::operator =(const Vector2D &vec) {
	this->x_coord = vec.x();
	this->y_coord = vec.y();
}


