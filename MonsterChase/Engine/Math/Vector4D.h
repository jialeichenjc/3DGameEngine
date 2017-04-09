#pragma once
#include "Vector3D.h"
#include "../Utility.h"

class Vector4D
{
public:
	Vector4D() = default;
	Vector4D(float i_x, float i_y, float i_u, float i_v) 
		: x_coord(i_x), y_coord(i_y), u_coord(i_u), v_coord(i_v) {}

	Vector4D(const Vector3D & i_vec)
		: x_coord(i_vec.x()), y_coord(i_vec.y()), u_coord(i_vec.z()), v_coord(1.0f) {}

	inline float x() const {
		return x_coord;
	}

	inline float y() const {
		return y_coord;
	}

	inline float u() const {
		return u_coord;
	}

	inline float v() const {
		return v_coord;
	}

	inline void set_x(const float i_x) {
		x_coord = i_x;
	}

	inline void set_y(const float i_y) {
		y_coord = i_y;
	}

	inline void set_u(const float i_u) {
		u_coord = i_u;
	}

	inline void set_v(const float i_v) {
		v_coord = i_v;
	}

	inline void set_all_coords(const float i_x, const float i_y, const float i_u, const float i_v) {
		x_coord = i_x;
		y_coord = i_y;
		u_coord = i_u;
		v_coord = i_v;
	}

	float operator[](const size_t i_index) const {
		switch (i_index)
		{
		case 0:
			return x_coord;
		case 1:
			return y_coord;
		case 2:
			return u_coord;
		case 3:
			return v_coord;
		default:
			return 0.0f;
		}
	}

	float& operator[](const size_t i_index) {
		float result = 0.0f;
		switch (i_index)
		{
		case 0:
			return x_coord;
		case 1:
			return y_coord;
		case 2:
			return u_coord;
		case 3:
			return v_coord;
		default:
			return result;
		}
	}

	~Vector4D() {};

private:
	float x_coord;
	float y_coord;
	float u_coord;
	float v_coord;
};

inline bool operator ==(const Vector4D i_lvec, const Vector4D i_rvec) {
	for (size_t i = 0; i <= 3; i++) {
		if (! is_approx_equals(i_lvec[i], i_rvec[i], static_cast<float>(0.00001))) {
			return false;
		}
	}
	return true;
}