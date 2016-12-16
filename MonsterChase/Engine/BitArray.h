#pragma once
#include <cstdint>
#include <cstring>
class FixedSizeAllocator;
class BitArray
{
public:
	
	// return a static instance of BitArray
	static BitArray* get_instance(size_t i_num_bits, bool i_init_to_zero);
	static void destroy_instatnce();
	// return the underlying bit (byte) array
	uint8_t* get_byte_array() const;
	void clear_all();
	void set_all();
	bool are_all_clear() const;
	bool are_all_set() const;


	size_t FindFirstClearBit() const;
	size_t FindFirstSetBit() const;
	~BitArray();

private:

	// BitArray is a singleton class
	BitArray(size_t i_num_bits, bool i_init_to_zero);
	// Singleton instance of BitArray
	static BitArray *p_instance;
	// store bits in an array of bytes
	uint8_t  *p_byte_array;
	size_t num_bytes; // length of this bit array
};

