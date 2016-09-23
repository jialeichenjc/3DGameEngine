#include "Game_character.h"

Game_character::Game_character()
{
}

void Game_character::set_name(char* name) {
	this->name = name;
}

char* Game_character::get_name() {
	return name;
}

int* Game_character::get_position() {
	return position;
}

void Game_character::init_pos() {

}

void Game_character::move() {

}

void Game_character::move_next(int delta_x, int delta_y) {
	position[0] += delta_x;
	position[1] += delta_y;
}

Game_character::~Game_character()
{
}

