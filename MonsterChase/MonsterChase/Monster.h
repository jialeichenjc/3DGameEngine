#pragma once
#include "GameObject.h"
#include "IGameObjectController.h"
#include "Allocators.h"
class Monster : public IGameObjectController {
public:
	Monster(); // create a new monster with a random initial position
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

	~Monster();

private:
	GameObject *game_object;
};
