#pragma once
#include <stdint.h>
#include "PaddlePlayer.h"
namespace Input
{
	uint8_t VKeyIDToChar(unsigned int i_VKeyID) {
		switch (i_VKeyID) {
			case 0x0057:
				return 'W';
			case 0x0053:
				return 'S';
			default:
				break;
		}
	}
};

