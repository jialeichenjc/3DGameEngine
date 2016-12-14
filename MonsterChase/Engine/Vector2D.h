#pragma once
#include "Utility.h"
class Vector2D
{
public:
	Vector2D() = default;
	Vector2D(float i_x, float i_y) : x_coord(is_nan(i_x) ? 0.0 : i_x), y_coord(is_nan(i_y) ? 0.0 : i_y) {}

	// get x coordination of vector
	inline float x() const { return x_coord; }
	// get y coordination of vector
	inline float y() const { return y_coord; }

	// set x coordination of vector
	inline void set_x(const float i_x) { 
		if (is_nan(i_x)) {
			return;
		}
		this->x_coord = i_x; 
	}

	// set x coordination of vector
	inline void set_y(const float i_y) { 
		if (is_nan(i_y)) {
			return;
		}
		this->y_coord = i_y;
	}

	// assignment operator
	void operator =(const Vector2D &vec);

	~Vector2D();

private:
	float x_coord;
	float y_coord;
};

inline Vector2D operator +(const Vector2D &lhs, const Vector2D &rhs) {
	return Vector2D(lhs.x() + rhs.x(), lhs.y() + rhs.y());
}

inline bool operator ==(const Vector2D &lhs, const Vector2D &rhs) {
	return lhs.x() == rhs.x() && lhs.y() == rhs.y();
}

inline bool operator !=(const Vector2D &lhs, const Vector2D &rhs) {
	return lhs.x() != rhs.x() || lhs.y() != rhs.y();
}

inline float cross(const Vector2D &lhs, const Vector2D &rhs) {
	return lhs.x()*rhs.y() - lhs.y()*rhs.x();
}

// dot product (result is scalar value)
inline float dot(const Vector2D &lhs, const Vector2D &rhs) {
	return lhs.x() * rhs.x() + lhs.y() * rhs.y();
}