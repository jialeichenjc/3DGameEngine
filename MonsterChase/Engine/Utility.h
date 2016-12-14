#pragma once
#include <cmath>
#include "MemoryAllocator.h"
inline bool is_nan(const float arg) {
	return (arg == NAN) ? true : false;
}