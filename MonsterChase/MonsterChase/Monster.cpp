#include "Monster.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


Monster::Monster() {
	init_pos();
}

// For Monsters, the initial position is randomly generated
void Monster::init_pos() {
	float x = (float)(rand() % 100 + 1);
	float y = (float)(rand() % 100 + 1);
	set_position(Vector2D(x, y));
}

// Randomly move the monster in four directions
void Monster::move() {
	int direction = rand() % 4 + 1;
	switch (direction) {
	case 1: // move up
		move_next(Vector2D(0.0, 1.0));
		break;
	case 2: // move down
		move_next(Vector2D(0.0, -1.0));
		break;
	case 3: // move left
		move_next(Vector2D(-1.0, 0.0));
		break;
	case 4: // move right
		move_next(Vector2D(1.0, 0.0));
		break;
	default:
		break;
	}
}


Monster::~Monster() {
}
