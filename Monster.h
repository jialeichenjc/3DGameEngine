#pragma once
#include "Game_character.h"
class Monster :
	public Game_character
{
public:
	Monster();
	void init_pos() override;
	void move() override;
	~Monster();
};

