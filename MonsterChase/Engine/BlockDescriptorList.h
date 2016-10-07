#pragma once
#include "BlockDescriptor.h"
class BlockDescriptorList
{
public:
	BlockDescriptorList() = default;
	BlockDescriptorList(int num_total_bd);
	void insert_after(BlockDescriptor &bd);
	void delete_after(BlockDescriptor &bd);
	BlockDescriptor* pop_head();

	BlockDescriptor *head;
	BlockDescriptor *tail;
	~BlockDescriptorList();
};

