#include "BitArray.h"
#include <stdio.h>
BitArray* BitArray::p_instance = nullptr;
BitArray::BitArray(size_t i_num_bits, bool i_init_to_zero) {
	const size_t bits_per_byte = 8;
	// TODO: this might not be necessray
	num_bytes = i_num_bits / bits_per_byte;
	p_byte_array = new uint8_t[i_num_bits / bits_per_byte];

	memset(p_byte_array, i_init_to_zero ? 0 : 1, i_num_bits / bits_per_byte);
}

BitArray* BitArray::get_instance(size_t i_num_bits, bool i_init_zero) {
	if (p_instance == nullptr) {
		p_instance = new BitArray(i_num_bits, i_init_zero);
	}

	return p_instance;
}

uint8_t* BitArray::get_byte_array() const {
	return p_byte_array;
}

size_t BitArray::FindFirstSetBit() const {
	size_t index = 0;

	// find the first non-zero byte
	while ((p_byte_array[index] == 0x00) && (index < num_bytes)) {
		index++;
	}

	uint8_t non_zero_byte = p_byte_array[index];
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

void BitArray::destroy_instatnce() {
	delete p_instance;
	p_instance = nullptr;
}

BitArray::~BitArray() {
	//delete p_instance;
	delete p_byte_array;
}
