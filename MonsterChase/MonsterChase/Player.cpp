#include "Player.h"
#include <conio.h>
#include <ctype.h>

Player::Player()
{
	init_pos();
}

// For the Player, the initial position is set to [0,0]
void Player::init_pos() {
	set_position(Vector2D(0.0, 0.0));
}

void Player::move(int input) {
	//int input = toupper(_getch());
	switch (input) {
	case 'W': // move up
		move_next(Vector2D(0.0, 1.0));
		break;
	case 'S': // move down
		move_next(Vector2D(0.0, -1.0));
		break;
	case 'A': // move left
		move_next(Vector2D(-1.0, 0.0));
		break;
	case 'D': // move right
		move_next(Vector2D(1.0, 0.0));
		break;
	default:
		break;
	}
}

Player::~Player() {
}
