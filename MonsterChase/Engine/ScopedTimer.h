#pragma once
#include "Timing.h"
class Accumulator;
class ScopedTimer
{
	//Timing::tick m_Start;
	Accumulator * m_pAccumulator;
public:
	ScopedTimer();
	~ScopedTimer();
};

