#pragma once
class Vector2D
{
public:
	Vector2D(float i_x, float i_y) : pos_x(i_x), pos_y(i_y) {}

	// dot product (result is scalar value)
	float dot(Vector2D v1, Vector2D v2);

	// addition
	Vector2D operator+();

	// get x position of vector
	float x() const;
	// get y position of vector
	float y() const;

	~Vector2D();

private:
	float pos_x;
	float pos_y;
};

Vector2D operator+ (const Vector2D &lhs, const Vector2D &rhs);

