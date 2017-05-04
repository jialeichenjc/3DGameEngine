#pragma once
#include "IGameObjectController.h"
#include <stdint.h>
#include "GLib.h"

class GameObject;
class PaddleAI : public IGameObjectController
{
public:
	PaddleAI();
	void SetName(const char* name) override;
	const char* GetName() const override;
	Vector3D GetPosition() const override;
	void SetPosition(const Vector3D &vec) override;
	void SetInitPosition() override; // set the initial posiion for the character
	void SetGameObject(GameObject *game_object) override;
	GameObject * GetGameObject() const override;
	void MoveByAI(); // player controlled movement

	void SetSprite(const GLib::Sprites::Sprite *i_sprite) override;
	const GLib::Sprites::Sprite* GetSprite() const override;

	Vector3D GetVelocity() const override;
	void SetVelocity(const Vector3D & i_vec) override;
	void MoveWithVelocity() override;

	~PaddleAI();

private:
	GameObject * m_pGameObject;
	const GLib::Sprites::Sprite * m_pSprite;
};

