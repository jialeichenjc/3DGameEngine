#include "StringPool.h"

StringPool* StringPool::get_instance(size_t i_bytes) {
	if (str_pool_instance == nullptr) {
		str_pool_instance = new StringPool(i_bytes);
	}
	return str_pool_instance;
}

StringPool::StringPool(uint8_t* i_pPool, size_t i_sizePool) {
	m_pStart = i_pPool;

}

StringPool::~StringPool()
{
}
