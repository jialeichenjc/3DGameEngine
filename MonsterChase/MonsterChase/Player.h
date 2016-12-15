#pragma once
#include "IGameObjectController.h"
class GameObject;

class Player : public IGameObjectController {
public:
	Player();
	void set_game_object(GameObject *object) override;
	void set_name(const char *name) override;
	const char* get_name() const override;
	Vector2D get_position() const override;
	void set_position(const Vector2D &vec) override;
	void init_pos() override;
	void move_from_user_input(int input);
	~Player();

private:
	GameObject *game_object;
};