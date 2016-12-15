#include "Player.h"
#include "GameObject.h"
#include <conio.h>
#include <ctype.h>

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


void Player::move_from_user_input(int input) {
	//int input = toupper(_getch());
	switch (input) {
	case 'W': // move up
		game_object->move_next(Vector2D(0.0, 1.0));
		break;
	case 'S': // move down
		game_object->move_next(Vector2D(0.0, -1.0));
		break;
	case 'A': // move left
		game_object->move_next(Vector2D(-1.0, 0.0));
		break;
	case 'D': // move right
		game_object->move_next(Vector2D(1.0, 0.0));
		break;
	default:
		break;
	}
}

Player::~Player() {
	delete game_object;
}
