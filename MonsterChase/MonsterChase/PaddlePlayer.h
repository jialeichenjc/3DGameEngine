#pragma once
#include "IGameObjectController.h"
#include <stdint.h>
#include "GLib.h"
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
	void MoveByPlayer(uint8_t input); // player controlled movement

	void SetSprite(const GLib::Sprites::Sprite *i_sprite);
	const GLib::Sprites::Sprite* GetSprite() const;

	~PaddlePlayer();

private:
	GameObject * m_pGameObject;
	const GLib::Sprites::Sprite * m_pSprite;
};

