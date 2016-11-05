#pragma once
#include "Monster.h"
class MonsterController
{
public:
	MonsterController();

	Monster* add_monster(Monster *monsters, int& num_monsters);
	bool should_add_monster();
	void destroy_monster(Monster *monsters, int& num_monsters);
	bool should_delete_monster(int& num_monsters);
	void print_monsters(Monster *monsters, int& num_monsters);
	~MonsterController();
};

inline bool MonsterController::should_add_monster() {
	int chance = rand() % 5 + 1;
	if (chance == 1) {
		return true;
	}
	else
		return false;
}

inline void MonsterController::destroy_monster(Monster *monsters, int& num_monsters) {
	monsters[num_monsters - 1].~Monster();
	num_monsters--;
}

inline bool MonsterController::should_delete_monster(int& num_monsters) {
	int chance = rand() % 8 + 1;
	if (chance == 4 && num_monsters > 1) {
		return true;
	}
	else
		return false;
}

