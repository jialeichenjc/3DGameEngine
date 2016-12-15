#pragma once
#include "IGameObjectController.h"
class GameObject;

class Monster : public IGameObjectController {
public:
	Monster(); // create a new monster with a random initial position

	// copy constructor
	Monster(const Monster &i_monster);
	// move constructor
	Monster(Monster &&i_monster);

	void init_pos() override;
	void set_game_object(GameObject *object) override;
	void set_name(const char *name) override;
	const char* get_name() const override;
	Vector2D get_position() const override;
	void set_position(const Vector2D &vec) override;
	void move_random();

	// move assignment operator
	Monster& operator=(const Monster&& i_monster);

	// copy assignment operator
	Monster& operator=(const Monster& i_monster);

	~Monster();

private:
	GameObject *game_object;
};
