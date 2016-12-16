#include "BitArray.h"
BitArray* BitArray::p_instance = nullptr;
BitArray::BitArray(size_t i_num_bits, bool i_init_to_zero) {
	const size_t bits_per_byte = 8;

	p_bits_array = new uint8_t[i_num_bits / bits_per_byte];

	memset(p_bits_array, i_init_to_zero ? 0 : 1, i_num_bits / bits_per_byte);
}

BitArray* BitArray::get_instance(size_t i_num_bits, bool i_init_zero) {
	if (p_instance == nullptr) {
		p_instance = new BitArray(i_num_bits, i_init_zero);
	}

	return p_instance;
}

size_t BitArray::FindFirstSetBit() const {
	size_t index = 0;

	// find the first non-zero byte
	while ((p_bits_array[index] == 0x00) && (index < num_bytes)) {
		index++;
	}

	uint8_t non_zero_byte = p_bits_array[index];
	size_t bit;

	// find the non-zero bit within that byte
	for (bit = 0; bit < 8; bit++) {
		if (non_zero_byte & (1 << bit)) {
			break;
		}
	}

	size_t bitset = index * 8 + bit;

	return bitset;
}

BitArray::~BitArray() {
	delete p_bits_array;
}
