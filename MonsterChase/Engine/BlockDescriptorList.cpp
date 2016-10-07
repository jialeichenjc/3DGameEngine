#include "BlockDescriptorList.h"



BlockDescriptorList::BlockDescriptorList()
{
}

BlockDescriptorList::BlockDescriptorList(int num_total_bd) {
	BlockDescriptor bd_head;
	head = &bd_head;

	// create a list of given number of BlockDescriptors
	BlockDescriptor *curr = head;
	for (int i = 1; i < num_total_bd; i++) {
		BlockDescriptor bd;
		curr->next_bd = &bd;
		bd.prev_bd = curr;
		curr = curr->next_bd;
	}
}

BlockDescriptor* BlockDescriptorList::pop_head() {
	BlockDescriptor *result = head;
	head = head->next_bd;
	head->prev_bd = NULL;
	result->next_bd = NULL;
}


BlockDescriptorList::~BlockDescriptorList()
{
}
