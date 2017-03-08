#pragma once
class Vector4D
{
public:
	Vector4D();
	Vector4D(float i_x, float i_y, float i_u, float i_v) 
		: x(i_x), y(i_y), u(i_u), v(i_v) {}
	~Vector4D();

private:
	float x;
	float y;
	float u;
	float v;
};

