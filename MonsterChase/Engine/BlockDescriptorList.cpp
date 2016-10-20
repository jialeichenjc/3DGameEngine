#include "BlockDescriptorList.h"



BlockDescriptorList::BlockDescriptorList(int num_total_bd) {
	BlockDescriptor bd_head = BlockDescriptor();
	head = &bd_head;
	// create a list of given number of BlockDescriptors
	BlockDescriptor curr = *head;
	for (int i = 1; i < num_total_bd; i++) {
		BlockDescriptor bd = BlockDescriptor();
		curr.next_bd = &bd;
		bd.prev_bd = &curr;
		curr = *(curr.next_bd);
	}
	
}

// construct the list with just a head
BlockDescriptorList::BlockDescriptorList(BlockDescriptor *init_head) {
	head = init_head;
}

BlockDescriptor& BlockDescriptorList::pop_head() {
	BlockDescriptor &result = *head;
	head = head->next_bd;
	head->prev_bd = NULL;
	result.next_bd = NULL;

	return result;
}

void BlockDescriptorList::insert_after(BlockDescriptor *pos, BlockDescriptor &bd) {
	BlockDescriptor *pos_next = pos->next_bd;
	pos->next_bd = &bd;
	bd.prev_bd = pos;
	if (pos_next != NULL) {
		bd.next_bd = pos_next;
		pos_next->prev_bd = &bd;
	}	
}

void BlockDescriptorList::remove(BlockDescriptor *pos) {
	BlockDescriptor *pos_next = pos->next_bd;
	BlockDescriptor *pos_prev = pos->prev_bd;
	if (pos_next == NULL && pos_prev == NULL) {
		return;
	}
	else if (pos_next == NULL && pos_prev != NULL) {
		pos_prev->next_bd = NULL;
		pos->prev_bd = NULL;
	}
	else if (pos_prev == NULL && pos_next != NULL) {
		pos_next->prev_bd = NULL;
		pos->next_bd = NULL;
	}
	else {
		pos_prev->next_bd = pos_next;
		pos_next->prev_bd = pos_prev;
		pos->next_bd = NULL;
		pos->prev_bd = NULL;
	}
}

// add to the end of list
void BlockDescriptorList::add(BlockDescriptor &bd) {
	if (head == NULL) {
		head = &bd;
	}
	else {
		BlockDescriptor *curr = head;
		while (curr->next_bd != NULL) {
			curr = curr->next_bd;
		}
		curr->next_bd = &bd;
		bd.prev_bd = curr;
	}
}

void BlockDescriptorList::print_block_list() {
	BlockDescriptor *curr = head;
	while (curr != NULL) {
		printf("block base pointer is %p size of memory block is %d", curr->block_base_ptr, curr->block_size);
		curr = curr->next_bd;
	}
}

BlockDescriptorList::~BlockDescriptorList()
{
}
