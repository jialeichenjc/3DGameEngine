#pragma once
#include "BlockDescriptor.h"
#include <stdio.h>
class BlockDescriptorList
{
public:
	BlockDescriptorList() = default;
	BlockDescriptorList(int num_total_bd);
	BlockDescriptorList(BlockDescriptor *init_head);
	void insert_after(BlockDescriptor *pos, BlockDescriptor &bd);

	// remove the block descriptor from the list
	void remove(BlockDescriptor *pos);
	// add to add of block descriptor list
	void add(BlockDescriptor &bd);
	BlockDescriptor& pop_head();

	BlockDescriptor *head;
	BlockDescriptor *tail;
	~BlockDescriptorList();
};

