#pragma once
#include "BlockDescriptor.h"
class BlockDescriptorList
{
public:
	BlockDescriptorList() = default;
	BlockDescriptorList(int num_total_bd);
	void insert_after(BlockDescriptor *pos, BlockDescriptor &bd);

	// remove the block descriptor from the list
	void remove(BlockDescriptor *pos);
	BlockDescriptor* pop_head();

	BlockDescriptor *head;
	BlockDescriptor *tail;
	~BlockDescriptorList();
};

