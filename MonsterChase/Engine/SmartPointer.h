#pragma once
#include <stdint.h>
#include "ObjectManager.h"
using namespace std;
template <class T>
class SmartPointer
{
public:
	ObjectManager *p_manager;
	T *p_object;
	void *managed_object;
	//uint32_t ref_count; // initialized to 0
	SmartPointer(T *p = nullptr) {
		p_object = p;
	}
	// overload dereferencing operator
	T & operator *() { return *p_object; }
	T * operator ->() { return p_object; }
	bool operator ==(T *i_ptr) { return p_object == i_ptr; }
	~SmartPointer() {
		delete(p_object);
	}
};

