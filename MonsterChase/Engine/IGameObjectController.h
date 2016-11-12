#pragma once
#include "GameObject.h"
class IGameObjectController
{
public:
	virtual void set_name(const char* name) = 0;
	virtual const char* get_name() const = 0;
	virtual Vector2D get_position() const = 0;
	virtual void set_position(const Vector2D &vec) = 0;
	virtual void init_pos() = 0; // set the initial posiion for the character
	virtual void set_game_object(GameObject *game_object) = 0;
};

