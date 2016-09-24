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