#include "Monster.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


Monster::Monster() {
	init_pos();
}

// For Monsters, the initial position is randomly generated
void Monster::init_pos() {
	int x = rand() % 100 + 1;
	int y = rand() % 100 + 1;
	position[0] = x;
	position[1] = y;
}

// Randomly move the monster in four directions
void Monster::move() {
	int direction = rand() % 4 + 1;
	switch (direction) {
	case 1: // move up
		move_next(0, 1);
		break;
	case 2: // move down
		move_next(0, -1);
		break;
	case 3: // move left
		move_next(-1, 0);
		break;
	case 4: // move right
		move_next(1, 0);
		break;
	default:
		break;
	}
}


Monster::~Monster() {
}
