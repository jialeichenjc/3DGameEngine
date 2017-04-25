#pragma once
class Accumulator;
class ScopedTimer
{
	//Timing::tick m_Start;
	Accumulator * m_pAccumulator;
public:
	ScopedTimer();
	~ScopedTimer();
};

