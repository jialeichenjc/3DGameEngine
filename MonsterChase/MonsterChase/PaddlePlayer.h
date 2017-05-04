#pragma once
#include "IGameObjectController.h"
#include <stdint.h>
#include "GLib.h"
#include "GamePhysics.h"

class GameObject;

class PaddlePlayer : public IGameObjectController
{
public:
	PaddlePlayer();
	void SetName(const char* name) override;
	const char* GetName() const override;
	Vector3D GetPosition() const override;
	void SetPosition(const Vector3D &vec) override;
	void SetInitPosition() override; // set the initial posiion for the character
	void SetGameObject(GameObject *game_object) override;
	GameObject * GetGameObject() const override;
	void MoveByPlayer(uint8_t input); // player controlled movement

	void SetSprite(const GLib::Sprites::Sprite *i_sprite) override;
	const GLib::Sprites::Sprite* GetSprite() const override;

	void InitCollidable();

	void SetSpriteSize(float i_SizeX, float i_SizeY, float i_SizeZ);

	~PaddlePlayer();

protected:
	Collidable m_Collidable;
	Vector3D m_SpriteSize;

private:
	GameObject * m_pGameObject;
	const GLib::Sprites::Sprite * m_pSprite;
	float m_SizeX = 0.0f;
	float m_SizeY = 0.0f;
	float m_SizeZ = 0.0f;
};

