#pragma once
#include <malloc.h>
#include <new>
#include "BitArray.h"
#define MEMORY_TOTAL 1024*1024

// Fixed Size Memory Allocator
class FixedSizeAllocator
{
public:
	FixedSizeAllocator();


	~FixedSizeAllocator();
};

