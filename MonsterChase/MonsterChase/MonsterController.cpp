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

Monster* MonsterController::add_monster(Monster *monsters, int& num_monsters) {
	Monster *new_monsters = new Monster[++num_monsters];

	for (int i = 0; i < num_monsters - 1; i++) {
		new_monsters[i] = monsters[i];
	}
	Monster added_monster;
	added_monster.set_name("Machine Added");
	new_monsters[num_monsters - 1] = added_monster;

	return new_monsters;
}

void MonsterController::move_and_print_monsters(Monster *monsters, const int& num_monsters) {
	for (int i = 0; i < num_monsters; i++) {
		Vector2D monster_pos = monsters[i].get_position();
		monsters[i].move();
		printf("monster %s is at position [%.2f, %.2f]\n", monsters[i].get_name(), monster_pos.x(), monster_pos.y());
	}
}

MonsterController::~MonsterController()
{
}
