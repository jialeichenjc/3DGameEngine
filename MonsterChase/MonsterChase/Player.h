#pragma once
#include "GameObject.h"
#include "IGameObjectController.h"
class Player : public IGameObjectController {
public:
	Player();
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
	void init_pos() override;
	void move_from_user_input(int input);
	//void move_by_vector_2d(const Vector2D &delta_vec);
	~Player();

private:
	GameObject *game_object;
};

