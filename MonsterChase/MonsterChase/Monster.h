#pragma once
#include "Game_character.h"
class Monster :
	public Game_character
{
public:
	Monster(); // create a new monster with a random initial position
	void init_pos() override;
	void move() override;

	~Monster();
};
