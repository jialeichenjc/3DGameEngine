#pragma once
#include "Monster.h"
class MonsterPool
{
public:
	MonsterPool() = default;
	MonsterPool(int num_monsters);

	// update the positions of all monsters
	void update_monster_pos();

	// destroy the monster randomly at index i
	void destroy_monster(int i);

	// add a monster to the monster pool
	void add_monster();

	// return the monsters in game
	Monster* get_monsters();
	
	~MonsterPool();
	
	int num_monsters;
	//Monster monsters[];
	Monster *monsters;
};

