#pragma once
#include "Game_character.h"
class Player : public Game_character {
public:
	Player();
	void init_pos() override;
	void move(int input);
	~Player();
};

