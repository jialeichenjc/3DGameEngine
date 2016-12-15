#include "ChasingMonster.h"
#include "GameObject.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// a monster controller that moves monsters towards player
ChasingMonster::ChasingMonster()
{
}

void ChasingMonster::set_game_object(GameObject *object) {
	game_object = object;
}

void ChasingMonster::set_name(const char *name) {
	game_object->set_name(name);
}

const char* ChasingMonster::get_name() const {
	return game_object->get_name();
}

Vector2D ChasingMonster::get_position() const {
	return game_object->get_position();
}

void ChasingMonster::set_position(const Vector2D &vec) {
	game_object->set_position(vec);
}

void ChasingMonster::init_pos() {
	float x = static_cast<float>(rand() % 100 + 1);
	float y = static_cast<float>(rand() % 100 + 1);
	game_object->set_position(Vector2D(x, y));
}

void ChasingMonster::move_chasing(const Vector2D &target_pos) {
	float target_x = target_pos.x();
	float target_y = target_pos.y();
	float game_object_x = game_object->get_position().x();
	float game_object_y = game_object->get_position().y();
	if (game_object_x > target_x) {
		game_object->set_position(Vector2D(game_object_x - 1.0, game_object_y));
	}
	else if (game_object_x < target_x) {
		game_object->set_position(Vector2D(game_object_x + 1.0, game_object_y));
	}
	if (game_object_y > target_y) {
		game_object->set_position(Vector2D(game_object_x, game_object_y - 1.0));
	}
	else if (game_object_y < target_y) {
		game_object->set_position(Vector2D(game_object_x, game_object_y + 1.0));
	}
}

ChasingMonster::~ChasingMonster()
{
}
