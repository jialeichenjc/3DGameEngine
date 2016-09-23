#pragma once
#include <string.h>
class GameObject {
public:
	GameObject();
	void set_name(char* name);
	char* get_name();
	int* get_position();
	void move_next(int delta_x, int delta_y); // move game object by delta_x and delta_y
	virtual ~GameObject();
	virtual void init_pos(); // set the initial posiion for the character
	virtual void move();

protected:
	int position[2]; // array of 2 ints representing the position {x_coord, y_coord}
private:
	char *name;
};

/*
#pragma once
#include <string.h>
class Game_character
{
public:
void set_name(char* name);
char* get_name();
int* get_position();
void move_next(int delta_x, int delta_y);
Game_character();
virtual ~Game_character();
virtual void init_pos(); // set the initial posiion for the character
virtual void move();
protected:
int position[2]; // array of 2 ints representing the position {x_coord, y_coord}
private:
char *name;
};*/