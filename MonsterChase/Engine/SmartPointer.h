#pragma once
#include <stdint.h>
#include "ObjectManager.h"
class SmartPointer
{
public:
	ObjectManager *manager;
	void *managed_object;
	//uint32_t ref_count; // initialized to 0
	SmartPointer();
	~SmartPointer();
};

