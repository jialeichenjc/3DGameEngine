#pragma once
#include <assert.h>
#include <string>
class HashedString
{
public:
	HashedString();
	unsigned int Hash(const char* i_string);
	unsigned int Hash(const void* i_bytes, unsigned int i_bytecount);
	
	~HashedString();
};

