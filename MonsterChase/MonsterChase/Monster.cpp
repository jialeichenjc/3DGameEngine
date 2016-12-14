#include "Monster.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


Monster::Monster() {
	game_object = new GameObject();
	//init_pos();
}

// copy constructor
Monster::Monster(const Monster &i_monster) {
	game_object = new GameObject();
	*game_object = *i_monster.game_object;
}

// move constructor
Monster::Monster(Monster &&i_monster) {
	game_object = i_monster.game_object;

	// release game object pointer from source
	i_monster.game_object = nullptr;
}

// For Monsters, the initial position is randomly generated
void Monster::init_pos() {
	float x = static_cast<float>(rand() % 100 + 1);
	float y = static_cast<float>(rand() % 100 + 1);
	game_object->set_position(Vector2D(x, y));
}

// Randomly move the monster in four directions
void Monster::move_random() {
	int direction = rand() % 4 + 1;
	switch (direction) {
	case 1: // move up
		game_object->move_next(Vector2D(0.0, 1.0));
		break;
	case 2: // move down
		game_object->move_next(Vector2D(0.0, -1.0));
		break;
	case 3: // move left
		game_object->move_next(Vector2D(-1.0, 0.0));
		break;
	case 4: // move right
		game_object->move_next(Vector2D(1.0, 0.0));
		break;
	default:
		break;
	}
}

// move assignment
Monster& Monster::operator=(const Monster&& i_monster) {
	if (this != &i_monster) {
		delete game_object;
		game_object = i_monster.game_object;
		printf("using move assignment operator");
		set_name(i_monster.get_name());
		set_position(i_monster.get_position());
	}
	return *this;
}

// copy assignment
Monster& Monster::operator=(const Monster& i_monster) {
	if (this != &i_monster) {
		delete game_object;
		game_object = new GameObject();
		set_name(i_monster.get_name());
		set_position(i_monster.get_position());
	}
	return *this;
}

Monster::~Monster() {
	delete game_object;
}
