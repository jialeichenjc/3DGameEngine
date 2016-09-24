#include "GameObject.h"


GameObject::GameObject() {
}

void GameObject::set_name(char* name) {
	this->name = name;
}

char* GameObject::get_name() {
	return name;
}

Vector2D GameObject::get_position() {
	return position;
}

void GameObject::init_pos() {
}

void GameObject::move() {

}

void GameObject::move_next(Vector2D delta_vec) {
	position = position + delta_vec;
}

GameObject::~GameObject() {
}