#include "stdafx.h"
#include "Vector2D.h"


float Vector2D::x() const {
	return pos_x;
}

float Vector2D::y() const {
	return pos_y;
}

Vector2D::~Vector2D()
{
}

Vector2D operator+ (const Vector2D &lhs, const Vector2D &rhs) {
	return Vector2D(lhs.x() + rhs.x(), lhs.y() + rhs.y());
}