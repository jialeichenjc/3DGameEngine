#pragma once
#include <stdint.h>
using namespace std;
// Manager class to be used by shared(smart) pointers and weak pointers
class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void* get_manager() {
		return object;
	}
private:
	void *object;
	uint32_t smart_ptr_count;
	uint32_t weak_ptr_count;
};

