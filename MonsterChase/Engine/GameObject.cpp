#include "GameObject.h"


GameObject::GameObject() {
}

void GameObject::set_name(char* name) {
	this->name = name;
}

char* GameObject::get_name() {
	return name;
}

int* GameObject::get_position() {
	return position;
}

void GameObject::init_pos() {

}

void GameObject::move() {

}

void GameObject::move_next(int delta_x, int delta_y) {
	position[0] += delta_x;
	position[1] += delta_y;
}
GameObject::~GameObject() {
}