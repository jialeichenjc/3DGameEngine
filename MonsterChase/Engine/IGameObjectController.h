#pragma once
class GameObject;
class Vector3D;
class IGameObjectController
{
public:
	virtual void set_name(const char* name) = 0;
	virtual const char* get_name() const = 0;
	virtual Vector3D get_position() const = 0;
	virtual void set_position(const Vector3D &vec) = 0;
	virtual void init_pos() = 0; // set the initial posiion for the character
	virtual void set_game_object(GameObject *game_object) = 0;
};

