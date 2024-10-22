#include "BitArray.h"
#include "MemoryAllocator.h"
#include <intrin.h>
#include <stdio.h>
#include <cmath>
#define BITS_PER_BYTE 8

BitArray* BitArray::p_instance = nullptr;
MemoryAllocator* BitArray::p_mem_allocator = nullptr;
uint8_t* BitArray::p_byte_array = nullptr;
BitArray::BitArray(size_t i_num_bits, bool i_init_to_zero) {
	const size_t bits_per_byte = 8;

	num_bytes = i_num_bits / bits_per_byte;
	p_byte_array = new uint8_t[i_num_bits / bits_per_byte];

	uint8_t init_value = i_init_to_zero ? 0x00 : 0xff;
	for (size_t i = 0; i < num_bytes; i++) {
		p_byte_array[i] = init_value;
	}
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

// if the returned index == num_bytes then all bytes are zero in the array
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
		mask += uint8_t(pow(2, i));
	}
	mask = mask << start_index;
	i_p_bits = i_p_bits ^ mask;
}

void BitArray::set_bits_to_zero(const size_t &offset, const uint8_t &num_bits) {
	size_t byte_index = offset / BITS_PER_BYTE;
	uint8_t bit_index = offset % BITS_PER_BYTE;
	set_bits_to_zero(p_byte_array[byte_index], bit_index, num_bits);
}

void BitArray::set_bits_to_one(uint8_t &i_p_bits, const uint8_t &start_index, const uint8_t &num_bits) {
	uint8_t mask = 0;
	for (uint8_t i = 0; i < num_bits; i++) {
		mask += uint8_t(pow(2, i));
	}
	mask = mask << start_index;
	i_p_bits = i_p_bits | mask;
}

void BitArray::set_bits_to_one(const size_t &offset, const uint8_t &num_bits) {
	size_t byte_index = offset / BITS_PER_BYTE;
	uint8_t bit_index = offset % BITS_PER_BYTE;
	set_bits_to_one(p_byte_array[byte_index], bit_index, num_bits);
}

unsigned long BitArray::get_first_set_bit(const uint8_t &i_byte) const {
	unsigned long index;
	unsigned char test_bs_forward = _BitScanForward(&index, i_byte);

	return index;
}

bool BitArray::are_all_zero() const {
	for (size_t i = 0; i < num_bytes; i++) {
		if (p_byte_array[i] != 0x00) {
			return false;
		}
	}
	return true;
}

bool BitArray::are_all_one() const {
	for (size_t i = 0; i < num_bytes; i++) {
		if (p_byte_array[i] != 0xff) {
			return false;
		}
	}
	return true;
}

// set all bits to 1 (i.e., all bytes to 0xff)
void BitArray::set_all() {
	for (size_t i = 0; i < num_bytes; i++) {
		p_byte_array[i] = 0xff;
	}
}

// set all bits to 0 (i.e., all bytes to 0x00)
void BitArray::clear_all() {
	for (size_t i = 0; i < num_bytes; i++) {
		p_byte_array[i] = 0x00;
	}
}

void* BitArray::operator new(const size_t size) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();

	return allocator->alloc_mem(size);
}

void BitArray::operator delete(void* ptr) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();

	allocator->free_mem(ptr);
}

void* BitArray::operator new[](const size_t size) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();

	return allocator->alloc_mem(size);
}

void BitArray::operator delete[](void* ptr) {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();

	allocator->free_mem(ptr);
}

void BitArray::destroy_instatnce() {
	MemoryAllocator *allocator = MemoryAllocator::get_instance();

	allocator->free_mem(p_instance);
	p_instance = nullptr;
	delete[] p_byte_array;
}

BitArray::~BitArray() {
}
