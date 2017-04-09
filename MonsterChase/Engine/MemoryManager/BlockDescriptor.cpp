#include "BlockDescriptor.h"


BlockDescriptor::BlockDescriptor()
{
	// construct a standalone BlockDescriptor, pointing to memory block of size zero
	block_base_ptr = NULL;
	prev_bd = NULL;
	next_bd = NULL;
	block_size = 0;
	offset = 0;
}


BlockDescriptor::~BlockDescriptor()
{
}
