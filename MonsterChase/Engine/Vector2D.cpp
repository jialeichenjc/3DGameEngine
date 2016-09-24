#include "Vector2D.h"

Vector2D::~Vector2D() {
}

float Vector2D::dot(const Vector2D &lhs, const Vector2D &rhs) {
	return lhs.x() * rhs.x() + lhs.y() * rhs.y();
}

Vector2D operator +(const Vector2D &lhs, const Vector2D &rhs) {
	return Vector2D(lhs.x() + rhs.x(), lhs.y() + rhs.y());
}