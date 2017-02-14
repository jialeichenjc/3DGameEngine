#include "StringPoolUnitTest.h"
#include "StringPool.h"
#include "PooledString.h"
#include "HashedString.h"
#include <assert.h>
#define TEST_POOL_SIZE 128

bool StringPool_UnitTest() {
	StringPool* test_pool = StringPool::get_instance(TEST_POOL_SIZE);
	assert(test_pool);
	return true;
}