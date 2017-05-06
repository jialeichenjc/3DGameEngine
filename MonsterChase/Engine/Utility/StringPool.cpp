#include "StringPool.h"
StringPool* StringPool::str_pool_instance = nullptr;

StringPool* StringPool::get_instance(size_t i_bytes) {
	if (str_pool_instance == nullptr) {
		str_pool_instance = new StringPool(i_bytes);
	}
	return str_pool_instance;
}

StringPool::StringPool(uint8_t* i_pPool, size_t i_sizePool) {
	m_pStart = i_pPool;
	pool_size = i_sizePool;
}

// true indicates success in adding string, false otherwise
bool StringPool::add(const char* i_pString) {


	return true;
}

char* StringPool::find(const char* i_pString) {
	char* result = "";
	return result;
}

StringPool::StringPool(size_t i_sizePool) {

}
StringPool::~StringPool()
{
	delete str_pool_instance;
}
