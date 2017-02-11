#pragma once
#include <stdint.h>
using namespace std;
// Manager class to be used by shared(smart) pointers and weak pointers
class ObjectManager
{
public:
	ObjectManager() {
		smart_ptr_count = 0;
		weak_ptr_count = 0;
	}

	// increase/decrease smart/weak pointer count accordingly
	void increase_smart_count() {
		smart_ptr_count++;
	}
	void decrease_smart_count() {
		if (smart_ptr_count > 0) {
			smart_ptr_count--;
		}
	}
	void increase_weak_count() {
		weak_ptr_count++;
	}
	void decrease_weak_count() {
		if (weak_ptr_count > 0) {
			weak_ptr_count--;
		}
	}

	uint32_t get_smart_count() {
		return smart_ptr_count;
	}

	uint32_t get_weak_count() {
		return weak_ptr_count;
	}

	void* get_object() {
		return object;
	}

	void set_object(void* i_obj) {
		object = i_obj;
	}

	void destroy_object() {
		if (object != NULL) {
			delete object;
		}
	}
	~ObjectManager() {
		//delete object;
	}
	
private:
	void *object;
	uint32_t smart_ptr_count;
	uint32_t weak_ptr_count;
};

