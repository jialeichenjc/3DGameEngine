#include "BitArray.h"
#include <intrin.h>
#include <stdio.h>
#include <cmath>
#define BITS_PER_BYTE 8

BitArray* BitArray::p_instance = nullptr;
BitArray::BitArray(size_t i_num_bits, bool i_init_to_zero) {
	const size_t bits_per_byte = 8;
	// TODO: this might not be necessray
	num_bytes = i_num_bits / bits_per_byte;
	p_byte_array = new uint8_t[i_num_bits / bits_per_byte];
	uint8_t init_value = 0x00;
	if (!i_init_to_zero) {
		init_value = 0xff;
	}
	for (size_t i = 0; i < num_bytes; i++) {
		p_byte_array[i] = init_value;
	}
	//memset(p_byte_array, i_init_to_zero ? 0 : 0xff, i_num_bits / bits_per_byte);
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

void BitArray::set_byte_array(uint8_t* i_p_array) {
	p_byte_array = i_p_array;
}

size_t BitArray::get_first_set_byte() const {
	size_t index = 0;

	while ((p_byte_array[index] == 0x00) && (index < num_bytes)) {
		index++;
	}

	return index;
}

size_t BitArray::get_set_bit_offset() const {
	size_t index = 0;
	size_t bit_index = 0;
	size_t byte_index = 0;
	byte_index = get_first_set_byte();
	bit_index = get_first_set_bit(p_byte_array[byte_index]);
	index = BITS_PER_BYTE * byte_index + bit_index;
	
	return index;
}

// start_index starts from the least significant bit
void BitArray::set_bits_to_zero(uint8_t &i_p_bits, const uint8_t &start_index, const uint8_t &num_bits) {
	uint8_t mask = 0;
	for (uint8_t i = 0; i < num_bits; i++) {
		mask += pow(2, i);
	}
	mask << (start_index + num_bits);
	i_p_bits = i_p_bits ^ mask;
}


unsigned long BitArray::get_first_set_bit(const uint8_t &i_byte) const {
	//unsigned long mask = 0x22;
	unsigned long index;
	unsigned char test_bs_forward = _BitScanForward(&index, i_byte);

	return index;
}

//size_t BitArray::FindFirstSetBit() const {
//	size_t index = 0;
//
//	// find the first non-zero byte
//	while ((p_byte_array[index] == 0x00) && (index < num_bytes)) {
//		index++;
//	}
//
//	uint8_t non_zero_byte = p_byte_array[index];
//	size_t bit;
//
//	// find the non-zero bit within that byte
//	for (bit = 0; bit < 8; bit++) {
//		if (non_zero_byte & (1 << bit)) {
//			break;
//		}
//	}
//
//	size_t bitset = index * 8 + bit;
//
//	return bitset;
//}

void BitArray::destroy_instatnce() {
	//delete p_byte_array;
	delete p_instance;
	p_instance = nullptr;
}

BitArray::~BitArray() {
	//delete p_instance;
	delete p_byte_array;
}
