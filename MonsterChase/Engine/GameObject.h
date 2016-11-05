#pragma once
#include <string.h>
#include "Vector2D.h"
class GameObject {
public:
	GameObject();
	void set_name(char* name);
	char* get_name();
	Vector2D get_position();
	void set_position(Vector2D vec);
	void move_next(Vector2D); // move game object by delta_x and delta_y
	virtual ~GameObject();
	virtual void init_pos(); // set the initial posiion for the character
	virtual void move();

protected:
	Vector2D position; // a 2D vector representing the position {x_coord, y_coord}
private:
	char *name;
};

inline void GameObject::set_name(char* name) {
	this->name = name;
}

inline char* GameObject::get_name() {
	return name;
}

inline Vector2D GameObject::get_position() {
	return position;
}

inline void GameObject::set_position(Vector2D vec) {
	this->position = vec;
}

inline void GameObject::move_next(Vector2D delta_vec) {
	position = position + delta_vec;
}