#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Monster.h"
#include "Player.h"
#include "time.h"
#include "MonsterController.h"


MonsterController::MonsterController()
{
}

void MonsterController::add_monster(std::vector<Monster*> &monsters, size_t& num_monsters) const {
	Monster *added_monster = new Monster();
	added_monster->set_name("Machine Added");
	monsters.push_back(added_monster);
	num_monsters++;
}

void MonsterController::move_and_print_monsters(std::vector<Monster*> &monsters, const size_t& num_monsters) const {
	for (size_t i = 0; i < num_monsters; i++) {
		Vector2D monster_pos = monsters[i]->get_position();
		monsters[i]->move_random();
		printf("monster %s is at position [%.2f, %.2f]\n", monsters[i]->get_name(), monster_pos.x(), monster_pos.y());
	}
}

MonsterController::~MonsterController()
{
}
