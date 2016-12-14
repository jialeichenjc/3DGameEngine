#pragma once
#include <cmath>
#include "MemoryAllocator.h"
inline bool is_nan(const float arg) {
	return (arg == NAN) ? true : false;
}

inline bool is_approx_equals(const float arg_1, const float arg_2, float epsilon) {
	if (epsilon < 0) {
		epsilon = abs(epsilon);
	}
	float diff = abs(arg_1 - arg_2);
	if (arg_1 == NAN || arg_2 == NAN) {
		return false;
	}
	else if (diff <= epsilon) {
		return true;
	}
	else {
		return false;
	}
}