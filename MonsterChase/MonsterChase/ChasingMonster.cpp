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

Vector3D ChasingMonster::get_position() const {
	return game_object->get_position();
}

void ChasingMonster::set_position(const Vector3D &vec) {
	game_object->set_position(vec);
}

void ChasingMonster::init_pos() {
	float x = static_cast<float>(rand() % 100 + 1);
	float y = static_cast<float>(rand() % 100 + 1);
	game_object->set_position(Vector3D(x, y, 0.0));
}

void ChasingMonster::move_chasing(const Vector3D &target_pos) {
	float target_x = target_pos.x();
	float target_y = target_pos.y();
	float game_object_x = game_object->get_position().x();
	float game_object_y = game_object->get_position().y();
	if (game_object_x > target_x) {
		game_object->set_position(Vector3D(game_object_x - static_cast<float>(1.0), game_object_y, 0.0));
	}
	else if (game_object_x < target_x) {
		game_object->set_position(Vector3D(game_object_x + static_cast<float>(1.0), game_object_y, 0.0));
	}
	if (game_object_y > target_y) {
		game_object->set_position(Vector3D(game_object_x, game_object_y - static_cast<float>(1.0), 0.0));
	}
	else if (game_object_y < target_y) {
		game_object->set_position(Vector3D(game_object_x, game_object_y + static_cast<float>(1.0), 0.0));
	}
}

ChasingMonster::~ChasingMonster()
{
}
