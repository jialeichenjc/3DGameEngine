#include "StringPool.h"

StringPool* StringPool::get_instance(size_t i_bytes) {
	if (str_pool_instance == nullptr) {

	}
}

StringPool::StringPool(uint8_t* i_pPool, size_t i_sizePool) {
	m_pStart = i_pPool;

}

StringPool::~StringPool()
{
}
