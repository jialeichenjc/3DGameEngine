#pragma once
class Vector4D
{
public:
	Vector4D() = default;
	Vector4D(float i_x, float i_y, float i_u, float i_v) 
		: x_coord(i_x), y_coord(i_y), u_coord(i_u), v_coord(i_v) {}

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

	~Vector4D() {};

private:
	float x_coord;
	float y_coord;
	float u_coord;
	float v_coord;
};

