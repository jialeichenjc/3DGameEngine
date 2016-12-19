#include "Player.h"
#include "GameObject.h"
#include <conio.h>
#include <ctype.h>
const Vector2D UP = Vector2D(0.0, 1.0);
const Vector2D DOWN = Vector2D(0.0, -1.0);
const Vector2D LEFT = Vector2D(-1.0, 0.0);
const Vector2D RIGHT = Vector2D(1.0, 0.0);

Player::Player()
{
	game_object = new GameObject();
	//init_pos();
}

// For the Player, the initial position is set to [0,0]
void Player::init_pos() {
	game_object->set_position(Vector2D(0.0, 0.0));
}

void Player::set_game_object(GameObject *object) {
	game_object = object;
}

void Player::set_name(const char *name) {
	game_object->set_name(name);
}

const char* Player::get_name() const {
	return game_object->get_name();
}

Vector2D Player::get_position() const {
	return game_object->get_position();
}

void Player::set_position(const Vector2D &vec) {
	game_object->set_position(vec);
}


void Player::move_from_user_input(uint8_t input) {
	//int input = toupper(_getch());
	switch (input) {
	case 'W': // move up
		game_object->move_next(UP);
		break;
	case 'S': // move down
		game_object->move_next(DOWN);
		break;
	case 'A': // move left
		game_object->move_next(LEFT);
		break;
	case 'D': // move right
		game_object->move_next(RIGHT);
		break;
	default:
		break;
	}
}

Player::~Player() {
	delete game_object;
}
