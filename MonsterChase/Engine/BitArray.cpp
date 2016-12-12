#include "BitArray.h"



BitArray::BitArray(size_t i_num_bits, bool i_init_to_zero) {
	const size_t bits_per_byte = 8;

	p_bits_array = new uint8_t[i_num_bits / bits_per_byte];

	memset(p_bits_array, i_init_to_zero ? 0 : 1, i_num_bits / bits_per_byte);
}


BitArray::~BitArray() {
	delete p_bits_array;
}
