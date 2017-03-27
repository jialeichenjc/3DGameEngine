#pragma once
#include "Utility.h"
using namespace Utility;
class Vector3D
{
public:
	Vector3D() = default;
	Vector3D(float i_x, float i_y, float i_z)
		: x_coord(is_nan(i_x) ? float(0.0) : i_x),
		y_coord(is_nan(i_y) ? float(0.0) : i_y),
		z_coord(is_nan(i_z) ? float(0.0) : i_z) {}

	// get x coordinate of vector
	inline float x() const { return x_coord; }

	// get x coordinate of vector
	inline float y() const { return y_coord; }

	// get x coordinate of vector
	inline float z() const { return z_coord; }

	// set x coordinate of vector
	inline void set_x(const float i_x) {
		if (is_nan(i_x)) {
			return;
		}
		this->x_coord = i_x;
	}

	// set y coordinate of vector
	inline void set_y(const float i_y) {
		if (is_nan(i_y)) {
			return;
		}
		this->y_coord = i_y;
	}

	// set z coordinate of vector
	inline void set_z(const float i_z) {
		if (is_nan(i_z)) {
			return;
		}
		this->z_coord = i_z;
	}

	// assignment operator
	void operator = (const Vector3D&);

	~Vector3D() {};

private:
	float x_coord;
	float y_coord;
	float z_coord;
};

