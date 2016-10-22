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
	//BlockDescriptor bd = *pos;
	//BlockDescriptor *pos_next = pos->next_bd;
	//BlockDescriptor *pos_prev = pos->prev_bd;
	if (head == NULL) {
		return;
	}
	else {
		/*
		BlockDescriptor *curr = head;
		while (curr != NULL) {
			if (curr->block_base_ptr == pos->block_base_ptr) {
				if (curr->prev_bd == NULL && curr->next_bd == NULL) {
					head = NULL;
					tail = NULL;
				}
				else if (curr->prev_bd != NULL && curr->next_bd == NULL) {
					// set the new tail
					tail = curr->prev_bd;
					curr->prev_bd->next_bd = NULL;
					curr->prev_bd = NULL;
				}
				else if (curr->prev_bd == NULL && curr->next_bd != NULL) {
					head = curr->next_bd;
					curr->next_bd->prev_bd = NULL;
					curr->next_bd = NULL;
				}
				else if (curr->prev_bd != NULL && curr->next_bd != NULL) {
					curr->prev_bd->next_bd = curr->next_bd;
					curr->next_bd->prev_bd = curr->prev_bd;
					curr->next_bd = NULL;
					curr->next_bd = NULL;
				}
				break;
			}
			curr = curr->next_bd;
		}
		*/
		
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
	/*
	if (pos->next_bd == NULL && pos->prev_bd == NULL) {
		return;
	}
	else if (pos->next_bd == NULL && pos->prev_bd != NULL) {
		pos->prev_bd->next_bd = NULL;
		pos->prev_bd = NULL;
	}
	else if (pos->prev_bd == NULL && pos->next_bd != NULL) {
		pos->next_bd->prev_bd = NULL;
		pos->next_bd = NULL;
	}
	else {
		pos->prev_bd->next_bd = pos->next_bd;
		pos->next_bd->prev_bd = pos->prev_bd;
		pos->next_bd = NULL;
		pos->prev_bd = NULL;
	}
	*/
}

/*
void BlockDescriptorList::remove(BlockDescriptor &pos) {
	//BlockDescriptor *pos_next = pos->next_bd;
	//BlockDescriptor *pos_prev = pos->prev_bd;
	if (pos->next_bd == NULL && pos->prev_bd == NULL) {
		return;
	}
	else if (pos->next_bd == NULL && pos->prev_bd != NULL) {
		pos->prev_bd->next_bd = NULL;
		pos->prev_bd = NULL;
	}
	else if (pos->prev_bd == NULL && pos->next_bd != NULL) {
		pos->next_bd->prev_bd = NULL;
		pos->next_bd = NULL;
	}
	else {
		pos->prev_bd->next_bd = pos->next_bd;
		pos->next_bd->prev_bd = pos->prev_bd;
		pos->next_bd = NULL;
		pos->prev_bd = NULL;
	}
}
*/


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

/*
void BlockDescriptorList::push(size_t size) {
	BlockDescriptor bd;
	bd.block_size = size;
	BlockDescriptor *p_bd = &bd;
	if (head == NULL) {
		head = p_bd;
	}
	else if (head != NULL && tail == NULL) {
		tail = p_bd;
		head->next_bd = tail;
		tail->prev_bd = head;
	}
	else {
		tail->next_bd = p_bd;
		p_bd->prev_bd = tail;
	}
}
*/
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
