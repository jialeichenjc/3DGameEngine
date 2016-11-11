#pragma once
#include "GameObject.h"
#include "IGameObjectController.h"
class Player : public IGameObjectController {
public:
	Player();
	void init_pos() override;
	void move(int input);
	~Player();
};

