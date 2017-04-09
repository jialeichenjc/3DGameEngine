#include "SmartPointerUnitTest.h"
#include "../SmartPointer.h"
#include "../WeakPointer.h"
#include "../GameObject.h"
#include "../ObjectManager.h"
#include <assert.h>
using namespace std;

bool SmartPointer_UnitTest() {
	SmartPointer<int> ptr(new int(300));
	assert(*ptr == 300);

	//SmartPointer<GameObject> game_obj_1(new GameObject());
	//ObjectManager* test_obj_mgr = game_obj_1.p_manager;
	//assert(test_obj_mgr->get_smart_count() == 1);
	//assert(test_obj_mgr->get_weak_count() == 0);

	//SmartPointer<GameObject> game_obj_2 = game_obj_1;
	//assert(test_obj_mgr->get_smart_count() == 2);
	//// create a weak pointer to a new game object
	//WeakPointer<GameObject> wk_ptr_1(new GameObject());
	//SmartPointer<GameObject> game_obj_3;
	//game_obj_3 = wk_ptr_1.make_smart_pointer();
	//assert(game_obj_3.p_manager->get_smart_count() == 1);
	//assert(game_obj_3.p_manager->get_weak_count() == 0);
	//assert(game_obj_1);
	return true;
}
