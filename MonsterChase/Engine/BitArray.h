#pragma once
#include <cstdint>
#include <cstring>
class FixedSizeAllocator;
class BitArray
{
public:
	
	// return a static instance of BitArray
	static BitArray* get_instance(size_t i_num_bits, FixedSizeAllocator* i_fs_allocator);

	size_t FindFirstSetBit();
	~BitArray();

private:

	// BitArray is a singleton class
	BitArray(size_t i_num_bits, bool i_init_to_zero);
	// store bits in an array of bytes
	uint8_t  *p_bits_array;
	size_t num_bytes;
};

