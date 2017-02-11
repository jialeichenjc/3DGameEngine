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
	//uint32_t ref_count; // initialized to 0
	SmartPointer(T *p = nullptr) {
		p_object = p;
		p_manager = new ObjectManager();
		p_manager->set_object(p);
		p_manager->increase_smart_count();
	}

	// copy constructor
	SmartPointer(const SmartPointer& i_smart_ptr) {
		p_manager = i_smart_ptr.p_manager;
		p_manager->increase_smart_count();
	}
	// overload dereferencing operator
	T& operator *() { return *p_object; }
	T* operator ->() { return p_object; }
	// overload copy assignment operator
	SmartPointer<T>& operator =(const SmartPointer& i_smart_ptr) {
		if (this != &i_smart_ptr) {
			// decrease the current manager's smart pointer count
			p_manager->decrease_smart_count(); 

			// use the assigned smart pointer count
			p_manager = i_smart_ptr.p_manager;
			p_manager->increase_smart_count();
		}
		return *this;
	}
	bool operator ==(T *i_ptr) { return p_object == i_ptr; }
	~SmartPointer() {
		p_manager->decrease_smart_count();
		if (p_manager->get_smart_count() == 0) {
			p_manager->destroy_object();
			p_object = nullptr;
			
			// if the weak count is also zero, 
			// then delete the object manager too
			if (p_manager->get_weak_count() == 0) {
				delete(p_manager);
			}
		}
	}
};

