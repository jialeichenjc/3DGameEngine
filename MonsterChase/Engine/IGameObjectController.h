#pragma once
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
};

