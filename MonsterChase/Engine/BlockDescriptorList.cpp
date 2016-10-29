#include "BlockDescriptorList.h"

BlockDescriptorList::BlockDescriptorList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

BlockDescriptorList::BlockDescriptorList(int num_total_bd) {

}

// construct the list with just a head
BlockDescriptorList::BlockDescriptorList(BlockDescriptor *init_head) {
	head = init_head;
	size = 0;
}

BlockDescriptor& BlockDescriptorList::pop_head() {
	BlockDescriptor &result = *head;
	head = head->next_bd;
	head->prev_bd = NULL;
	result.next_bd = NULL;

	size--;
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
	size++;
}

void BlockDescriptorList::remove(BlockDescriptor *pos) {
	if (head == NULL) {
		return;
	}
	else {
		
		if (pos->prev_bd == NULL && pos->next_bd == NULL) {
			head = NULL;
			tail = NULL;
		}
		else if (pos->prev_bd != NULL && pos->next_bd == NULL) {
			// set the new tail
			tail = pos->prev_bd;
			pos->prev_bd->next_bd = NULL;
			pos->prev_bd = NULL;
		}
		else if (pos->prev_bd == NULL && pos->next_bd != NULL) {
			head = pos->next_bd;
			pos->next_bd->prev_bd = NULL;
			pos->next_bd = NULL;
		}
		else if (pos->prev_bd != NULL && pos->next_bd != NULL) {
			pos->prev_bd->next_bd = pos->next_bd;
			pos->next_bd->prev_bd = pos->prev_bd;
			pos->next_bd = NULL;
			pos->next_bd = NULL;
		}
		size--;
	}
}


// add to the end of list
void BlockDescriptorList::push(BlockDescriptor *bd) {
	if (head == NULL) {
		head = bd;
	}
	else if (head != NULL && tail == NULL) {
		tail = bd;
		head->next_bd = tail;
		tail->prev_bd = head;
	}
	else {
		BlockDescriptor * p_curr = tail;
		p_curr->next_bd = bd;
		bd->prev_bd = p_curr;
		tail = bd;
	}
	size++;
}

void BlockDescriptorList::print_block_list() {
	BlockDescriptor *curr = head;
	while (curr != NULL) {
		printf("block base pointer is %p size of memory block is %p", curr->block_base_ptr, curr->block_size);
		curr = curr->next_bd;
	}
}

BlockDescriptorList::~BlockDescriptorList()
{
}
