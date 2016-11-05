#pragma once
#include "Debug.h"
#include "Vector2D.h"
class EngineTestSuite
{
public:
	EngineTestSuite();
	void testVector2D();
	~EngineTestSuite();

private:
	void testVector2DSetCoord();
	void testVector2DAssignment();
	void testVector2DEquals();
	void testVector2DNotEquals();
	void testVector2DCross();
	void testVector2DPlus();
	void testVector2Ddot();
};

