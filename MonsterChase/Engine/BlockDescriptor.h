#pragma once
class BlockDescriptor
{
public:
	BlockDescriptor();
	void *block_base_ptr;
	size_t block_size;
	~BlockDescriptor();
};

