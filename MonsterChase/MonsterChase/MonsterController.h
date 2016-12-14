#pragma once
#include "Monster.h"
#include <vector>
class MonsterController
{
public:
	MonsterController();

	void add_monster(std::vector<Monster*> &monsters, size_t& num_monsters) const;
	bool should_add_monster() const;
	void destroy_monster(std::vector<Monster*> &monsters, size_t& num_monsters) const;
	bool should_delete_monster(const size_t& num_monsters) const;
	void move_and_print_monsters(std::vector<Monster*> &monsters, const size_t& num_monsters) const;
	~MonsterController();
};

inline bool MonsterController::should_add_monster() const {
	uint8_t chance = rand() % 5 + 1;
	if (chance == 1) {
		return true;
	}
	else
		return false;
}

inline void MonsterController::destroy_monster(std::vector<Monster*> &monsters, size_t& num_monsters) const {
	delete monsters[num_monsters - 1];
	monsters.pop_back();
	num_monsters--;
}

inline bool MonsterController::should_delete_monster(const size_t& num_monsters) const {
	int chance = rand() % 8 + 1;
	if (chance == 4 && num_monsters > 1) {
		return true;
	}
	else
		return false;
}

