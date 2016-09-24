#pragma once
#include "GameObject.h"
class Monster :
	public GameObject
{
public:
	Monster(); // create a new monster with a random initial position
	void init_pos() override;
	void move() override;

	~Monster();
};
