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

