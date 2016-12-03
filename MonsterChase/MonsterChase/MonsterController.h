#pragma once
#include "Monster.h"
#include <vector>
class MonsterController
{
public:
	MonsterController();

	void add_monster(std::vector<Monster> &monsters, int& num_monsters) const;
	bool should_add_monster() const;
	void destroy_monster(std::vector<Monster> &monsters, int& num_monsters) const;
	bool should_delete_monster(const int& num_monsters) const;
	void move_and_print_monsters(std::vector<Monster> &monsters, const int& num_monsters) const;
	~MonsterController();
};

inline bool MonsterController::should_add_monster() const {
	int chance = rand() % 5 + 1;
	if (chance == 1) {
		return true;
	}
	else
		return false;
}

inline void MonsterController::destroy_monster(std::vector<Monster> &monsters, int& num_monsters) const {
	monsters.pop_back();
}

inline bool MonsterController::should_delete_monster(const int& num_monsters) const {
	int chance = rand() % 8 + 1;
	if (chance == 4 && num_monsters > 1) {
		return true;
	}
	else
		return false;
}

