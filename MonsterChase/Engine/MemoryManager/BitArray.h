#pragma once
#include <cstdint>
#include <cstring>
class MemoryAllocator;
class BitArray
{
public:
	
	// return a static instance of BitArray
	static BitArray* get_instance(size_t i_num_bits, bool i_init_to_zero);

	// delete the singleton
	static void destroy_instatnce();

	// return the underlying bit (byte) array
	uint8_t* get_byte_array() const;

	// set the byte array
	void set_byte_array(uint8_t *i_p_byte_array);

	// set consecutive bits to zero, starting from start_index
	// targeted bit has to have trailing zeros (i.e., 01011000)
	void set_bits_to_zero(uint8_t &i_p_bits, const uint8_t &start_index, const uint8_t &num_bits);
	void set_bits_to_zero(const size_t &offset, const uint8_t &num_bits);

	void set_bits_to_one(uint8_t &i_p_bits, const uint8_t &start_index, const uint8_t &num_bits);
	void set_bits_to_one(const size_t &offset, const uint8_t &num_bits);

	void clear_all();
	void set_all();
	// if the bits are all zero, then no memory block is available
	bool are_all_zero() const;
	bool are_all_one() const;

	// override new to allocate with MemoryAllocator
	void* operator new(const size_t size);
	// override delete
	void operator delete(void* ptr);

	void* operator new[](const size_t size);
	void operator delete[](void *ptr);
	
	// return the index of the set bit, relative to first element of the entire bit array
	size_t get_set_bit_offset() const;

	// return the first set bit in a non-zero byte
	unsigned long get_first_set_bit(const uint8_t& i_byte) const;

	// return the index of the first non-zero byte in the byte_array
	size_t get_first_set_byte() const;
	~BitArray();

private:
	static MemoryAllocator *p_mem_allocator;
	// BitArray is a singleton class
	BitArray(size_t i_num_bits, bool i_init_to_zero);
	// Singleton instance of BitArray
	static BitArray *p_instance;
	// store bits in an array of bytes
	static uint8_t  *p_byte_array;
	size_t num_bytes; // length of this bit array
};

