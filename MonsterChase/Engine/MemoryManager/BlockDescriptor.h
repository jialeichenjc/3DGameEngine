#pragma once
#include <stdlib.h>
class BlockDescriptor
{
public:
	BlockDescriptor();
	void *block_base_ptr;
	BlockDescriptor *next_bd; // pointer to the next block descriptor, if any
	BlockDescriptor *prev_bd;

	size_t block_size;
	size_t offset; // distance from beginning of the memory block
	~BlockDescriptor();
};

