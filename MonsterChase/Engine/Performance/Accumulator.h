#pragma once
#include <stdint.h>
#include <limits>
#include "Profiler.h"
Profiler g_Profiler;

struct Accumulator {
	double m_Sum;
	uint64_t m_Count;
	float m_Min, m_Max;

	Accumulator(const char * i_pName) :
		m_Sum(0.0),
		m_Count(0),
		m_Max(std::numeric_limits<float>::min()),
		m_Min(std::numeric_limits<float>::max()) {
	
		g_Profiler.RegisterAccumulator(i_pName, *this);
	}

	void operator += (float i_time) {
		m_Sum += i_time;
		m_Count++;

		if (i_time > m_Max) {
			m_Max = i_time;
		}
		else if (i_time < m_Min) {
			m_Min = i_time;
		}
	}

	float average() {
		return m_Sum / m_Count;
	}
};