#pragma once
#include <stdint.h>
#include "MemoryAllocator.h"
// singleton class storing strings
class StringPool
{
public:
	static StringPool* get_instance(size_t i_bytesInPool);
	// Add a string to pool, if it doesn't exist yet
	const char* add(const char* i_pString);

	const char* find(const char* i_pString);

	~StringPool();
private:
	StringPool(uint8_t* i_pPool, size_t i_sizePool);
	StringPool(size_t i_sizePool);
	// points to the start of the string pool
	uint8_t* m_pStart;
	// total size of the pool
	size_t pool_size;
	static StringPool* str_pool_instance;
};

