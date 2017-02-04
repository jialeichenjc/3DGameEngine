#include "SmartPointerUnitTest.h"
#include "SmartPointer.h"

#include <assert.h>
using namespace std;

bool SmartPointer_UnitTest() {
	SmartPointer<int> ptr(new int(300));
	assert(*ptr == 300);

	return true;
}
