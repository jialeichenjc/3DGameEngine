#pragma once
#include <assert.h>
class HashedString
{
public:
	HashedString();
	unsigned int HashedString::Hash(const char* i_string);
	unsigned int HashedString::Hash(const void* i_bytes, unsigned int i_bytecount);
	~HashedString();
};

