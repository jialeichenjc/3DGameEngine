#pragma once
#include <cstdint>
class BitArray
{
public:
	BitArray(size_t i_num_bits, bool i_init_to_zero);
	~BitArray();

private:
	// store bits in an array of bytes
	uint8_t  *p_bits_array;
};

