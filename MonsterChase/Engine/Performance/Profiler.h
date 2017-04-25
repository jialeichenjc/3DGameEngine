#pragma once
#include <stdint.h>
#include <limits>
#include<map>
class Accumulator;
class Profiler
{
public:
	Profiler();

	std::map<const char *, Accumulator *> m_AllAccumulators;

	void RegisterAccumulator(const char * i_pName, const Accumulator & i_Accumulator);
	~Profiler();
};

//Profiler g_Profiler;