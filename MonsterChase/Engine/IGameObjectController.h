#pragma once
#include "GLib.h"
class GameObject;
class Vector3D;
class IGameObjectController
{
public:
	virtual void SetName(const char* name) = 0;
	virtual const char* GetName() const = 0;
	virtual Vector3D GetPosition() const = 0;
	virtual void SetPosition(const Vector3D &vec) = 0;
	virtual void SetInitPosition() = 0; // set the initial posiion for the character
	virtual void SetGameObject(GameObject *game_object) = 0;
	virtual GameObject * GetGameObject() const = 0;
	virtual void SetSprite(const GLib::Sprites::Sprite *i_sprite) = 0;
	virtual const GLib::Sprites::Sprite * GetSprite() const = 0;
	virtual Vector3D GetVelocity() const = 0;
	virtual void SetVelocity(const Vector3D & i_vec) = 0;
	virtual void MoveWithVelocity() = 0;
};

