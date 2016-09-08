#include "MonsterPool.h"
#include <stdlib.h>
#include <stdio.h>


MonsterPool::MonsterPool(const int num_monsters) {
	this->num_monsters = num_monsters;
	monsters = new Monster[num_monsters];
}


void MonsterPool::update_monster_pos() {
	// move all monsters in random directions
	for (int i = 0; i < num_monsters; i++) {
		monsters[i].move();
		printf("monster %s is at position [%d, %d]\n", monsters[i].get_name(), monsters[i].position[0], monsters[i].position[1]);
	}
}

void MonsterPool::destroy_monster(int i) {

}

void MonsterPool::add_monster() {

}

Monster* MonsterPool::get_monsters() {
	return monsters;
}

MonsterPool::~MonsterPool()
{
}
