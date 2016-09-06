#pragma once
#include <string.h>
class Game_character
{
public:
	void set_name(char* name);
	char* get_name();
	int position[2]; // array of 2 ints representing the position {x_coord, y_coord}
	void move_next(int delta_x, int delta_y);
	Game_character();
	~Game_character();
	// set the initial posiion for the character
	virtual void init_pos(); 
	virtual void move();

private:
	char* name;
};

