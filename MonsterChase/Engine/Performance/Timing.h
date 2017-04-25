#pragma once
#include <ctime>
namespace Timing {
	std::clock_t tick;

	std::clock_t GetCurrentTick() {
		return std::clock();
	}
}