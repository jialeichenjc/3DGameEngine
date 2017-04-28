//#include "Player.h"
//#include "GameObject.h"
//#include <conio.h>
//#include <ctype.h>
//const Vector3D UP = Vector3D(0.0, 1.0, 0.0);
//const Vector3D DOWN = Vector3D(0.0, -1.0, 0.0);
//const Vector3D LEFT = Vector3D(-1.0, 0.0, 0.0);
//const Vector3D RIGHT = Vector3D(1.0, 0.0, 0.0);
//
//Player::Player()
//{	
//	game_object = new GameObject();
//	set_init_pos();
//}
//
//// For the Player, the initial position is set to [0,0]
//void Player::set_init_pos() {
//	game_object->SetPosition(Vector3D(0.0, 0.0, 0.0));
//}
//
//void Player::set_game_object(GameObject *object) {
//	game_object = object;
//}
//
//void Player::set_name(const char *name) {
//	game_object->set_name(name);
//}
//
//const char* Player::get_name() const {
//	return game_object->get_name();
//}
//
//Vector3D Player::get_position() const {
//	return game_object->get_position();
//}
//
//void Player::set_position(const Vector3D &vec) {
//	game_object->set_position(vec);
//}
//
//void Player::set_sprite(const GLib::Sprites::Sprite *i_sprite) {
//	this->sprite = i_sprite;
//}
//
//const GLib::Sprites::Sprite* Player::get_sprite() const {
//	return this->sprite;
//}
//
//void Player::move_from_user_input(uint8_t input) {
//	//int input = toupper(_getch());
//	switch (input) {
//	case 'W': // move up
//		game_object->Move(UP);
//		break;
//	case 'S': // move down
//		game_object->Move(DOWN);
//		break;
//	case 'A': // move left
//		game_object->Move(LEFT);
//		break;
//	case 'D': // move right
//		game_object->Move(RIGHT);
//		break;
//	default:
//		break;
//	}
//}
//
//Player::~Player() {
//	delete game_object;
//}
