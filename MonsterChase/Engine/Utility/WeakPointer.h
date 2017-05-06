#pragma once
#include <stdint.h>
#include "../ObjectManager.h"
#include "SmartPointer.h"
using namespace std;
template <class T>
class WeakPointer
{
public:
	ObjectManager *p_manager;
	//T *p_object;
	
	WeakPointer(T *p = nullptr) {
		//p_object = p;
		p_manager = new ObjectManager;
		p_manager->set_object(p);
		p_manager->increase_weak_count();
	}

	// copy constructor
	WeakPointer(const WeakPointer& i_weak_ptr) {
		p_manager = i_weak_ptr.p_manager;
		p_manager->increase_weak_count();
	}

	// overload copy assignment operator
	WeakPointer<T>& operator =(const WeakPointer& i_weak_ptr) {
		if (this != &i_weak_ptr) {
			p_manager = i_weak_ptr.p_manager;
			p_manager->increase_weak_count();
		}
		return *this;
	}
	bool operator ==(T *i_ptr) { return p_object == i_ptr; }

	// construct and return a smart pointer 
	SmartPointer<T> make_smart_pointer() {
		if (p_manager->get_smart_count() > 0) {
			SmartPointer<T> o_smt_ptr(new T);
			return o_smt_ptr;
		}
		return nullptr;
	}
	
	~WeakPointer() {
		p_manager->decrease_weak_count();
		// if weak count is zero and smart count is also zero
		// then delete the manager object
		if (p_manager->get_smart_count() == 0 && p_manager->get_weak_count() == 0) {
			delete p_manager;
		}
	}
};

