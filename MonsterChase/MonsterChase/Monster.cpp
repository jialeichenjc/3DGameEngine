//#include <stdlib.h>
//#include <stdio.h>
//#include <time.h>
//#include <cstdint>
//#include "Monster.h"
//#include "GameObject.h"
//const Vector3D UP = Vector3D(0.0, 1.0, 0.0);
//const Vector3D DOWN = Vector3D(0.0, -1.0, 0.0);
//const Vector3D LEFT = Vector3D(-1.0, 0.0, 0.0);
//const Vector3D RIGHT = Vector3D(1.0, 0.0, 0.0);
//
//Monster::Monster() {
//	game_object = new GameObject();
//}
//
//// copy constructor
//Monster::Monster(const Monster &i_monster) {
//	game_object = new GameObject();
//	*game_object = *i_monster.game_object;
//}
//
//// move constructor
//Monster::Monster(Monster &&i_monster) {
//	game_object = i_monster.game_object;
//
//	// release game object pointer from source
//	i_monster.game_object = nullptr;
//}
//
//// For Monsters, the initial position is randomly generated
//void Monster::init_pos() {
//	float x = static_cast<float>(rand() % 100 + 1);
//	float y = static_cast<float>(rand() % 100 + 1);
//	game_object->set_position(Vector3D(x, y, 0.0));
//}
//
//void Monster::set_game_object(GameObject *object) {
//	game_object = object;
//}
//
//void Monster::set_name(const char *name) {
//	game_object->set_name(name);
//}
//
//const char* Monster::get_name() const {
//	return game_object->get_name();
//}
//
//Vector3D Monster::get_position() const {
//	return game_object->get_position();
//}
//
//void Monster::set_position(const Vector3D &vec) {
//	game_object->set_position(vec);
//}
//
//void Monster::set_sprite(const GLib::Sprites::Sprite *i_sprite) {
//	this->sprite = i_sprite;
//}
//
//const GLib::Sprites::Sprite* Monster::get_sprite() const {
//	return this->sprite;
//}
//
//// Randomly move the monster in four directions
//void Monster::move_random() {
//	uint8_t direction = rand() % 4 + 1;
//	switch (direction) {
//	case 1: // move up
//		game_object->move_next(UP);
//		break;
//	case 2: // move down
//		game_object->move_next(DOWN);
//		break;
//	case 3: // move left
//		game_object->move_next(LEFT);
//		break;
//	case 4: // move right
//		game_object->move_next(RIGHT);
//		break;
//	default:
//		break;
//	}
//}
//
//// move assignment
//Monster& Monster::operator=(const Monster&& i_monster) {
//	if (this != &i_monster) {
//		delete game_object;
//		game_object = i_monster.game_object;
//		printf("using move assignment operator");
//		set_name(i_monster.get_name());
//		set_position(i_monster.get_position());
//	}
//	return *this;
//}
//
//// copy assignment
//Monster& Monster::operator=(const Monster& i_monster) {
//	if (this != &i_monster) {
//		delete game_object;
//		game_object = new GameObject();
//		set_name(i_monster.get_name());
//		set_position(i_monster.get_position());
//	}
//	return *this;
//}
//
//Monster::~Monster() {
//	delete game_object;
//}
