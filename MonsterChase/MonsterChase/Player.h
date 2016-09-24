#pragma once
#include "GameObject.h"
class Player : public GameObject {
public:
	Player();
	void init_pos() override;
	void move(int input);
	~Player();
};

