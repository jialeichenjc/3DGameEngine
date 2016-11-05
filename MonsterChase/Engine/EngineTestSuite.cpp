#include "EngineTestSuite.h"



EngineTestSuite::EngineTestSuite()
{
}

void EngineTestSuite::testVector2D() {
	testVector2DAssignment();
	testVector2DEquals();
	testVector2DNotEquals();
	testVector2DCross();
	testVector2DPlus();
	testVector2Ddot();
	testVector2DSetCoord();
}

void EngineTestSuite::testVector2DAssignment() {
	const Vector2D vec1(1.0, 2.0);
	Vector2D vec2;
	vec2 = vec1;
	assert(vec2.x() == 1.0, "Vector 2D Assignment failed -- X coordinate");
	assert(vec2.y() == 2.0, "Vector 2D Assignment failed -- Y coordinate");
}

void EngineTestSuite::testVector2DEquals() {
	const Vector2D vec1(1.0, 2.0);
	const Vector2D vec2(1.0, 2.0);
	const Vector2D vec3(2.0, 2.0);
	assert(vec1 == vec2, "Vector 2D equals failed");
	assert(vec1 != vec3, "Vector 2D equals failed");
}

void EngineTestSuite::testVector2DCross() {
	const Vector2D vec1(1.0, 2.0);
	const Vector2D vec2(2.0, 3.0);
	const Vector2D vec3(0.0, 0.0);
	assert(cross(vec1, vec2) == -1.0, "Vector 2D cross product failed");
	assert(cross(vec1, vec3) == 0.0, "Vector 2D cross product failed");
}

void EngineTestSuite::testVector2DPlus() {
	const Vector2D vec1(1.0, 2.0);
	const Vector2D vec2(2.0, 3.0);
	Vector2D vec3 = vec1 + vec2;
	assert(vec3.x() == 3.0, "Vector 2D addition failed");
	assert(vec3.y() == 5.0, "Vector 2D addition failed");
}

void EngineTestSuite::testVector2DNotEquals() {
	const Vector2D vec1(1.0, 2.0);
	const Vector2D vec2(3.0, 2.0);
	const Vector2D vec3(2.0, 2.0);
	assert(vec1 != vec2, "Vector 2D not equals failed");
	assert(vec2 != vec3, "Vector 2D not equals failed");
}

void EngineTestSuite::testVector2DSetCoord() {
	Vector2D vec1;
	const float x_coord = 1.0;
	const float y_coord = 2.0;
	vec1.set_x(x_coord);
	vec1.set_y(y_coord);
	assert(vec1.x() == 1.0, "Vector 2D set coord failed");
	assert(vec1.y() == 2.0, "Vector 2D set coord failed");
}

void EngineTestSuite::testVector2Ddot() {
	const Vector2D vec1(1.0, 2.0);
	const Vector2D vec2(2.0, 3.0);
	assert(dot(vec1, vec2) == 8.0, "Vector 2D doc product failed");
}

EngineTestSuite::~EngineTestSuite()
{
}
