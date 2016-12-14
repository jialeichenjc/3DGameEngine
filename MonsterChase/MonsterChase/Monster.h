#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdint>

#include "GameObject.h"
#include "IGameObjectController.h"
class Monster : public IGameObjectController {
public:
	Monster(); // create a new monster with a random initial position

	// copy constructor
	Monster(const Monster &i_monster);
	// move constructor
	Monster(Monster &&i_monster);

	void init_pos() override;
	void set_game_object(GameObject *object) override {
		game_object = object;
	}

	void set_name(const char *name) override {
		game_object->set_name(name);
	}

	const char* get_name() const override {
		return game_object->get_name();
	}

	Vector2D get_position() const override {
		return game_object->get_position();
	}

	void set_position(const Vector2D &vec) override {
		game_object->set_position(vec);
	}

	void move_random();

	// move assignment operator
	Monster& operator=(const Monster&& i_monster);

	// copy assignment operator
	Monster& operator=(const Monster& i_monster);

	~Monster();

private:
	GameObject *game_object;
};
