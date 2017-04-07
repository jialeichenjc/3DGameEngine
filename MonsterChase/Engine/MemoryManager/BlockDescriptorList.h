#pragma once
#include "BlockDescriptor.h"
#include <stdio.h>
class BlockDescriptorList
{
public:	
	BlockDescriptorList();
	BlockDescriptorList(const int num_total_bd);
	BlockDescriptorList(BlockDescriptor *init_head);
	void insert_after(BlockDescriptor *pos, BlockDescriptor &bd);

	// remove the block descriptor from the list
	void remove(BlockDescriptor *pos);
	// add to add of block descriptor list
	void push(BlockDescriptor *bd);
	//void push(size_t size);
	BlockDescriptor& pop_head();
	void print_block_list() const;

	BlockDescriptor *head;
	BlockDescriptor *tail;
	size_t size;
	~BlockDescriptorList();
};

