#pragma once
#include "IGameObjectController.h"
#include <stdint.h>
#include "GLib.h"
class GameObject;

class Player : public IGameObjectController {
public:
	Player();
	void set_game_object(GameObject *object) override;
	void set_name(const char *name) override;
	const char* get_name() const override;
	Vector3D get_position() const override;
	void set_position(const Vector3D &vec) override;
	void init_pos() override;
	void move_from_user_input(uint8_t input);

	void set_sprite(const GLib::Sprites::Sprite *i_sprite);
	const GLib::Sprites::Sprite* get_sprite() const;
	~Player();

private:
	GameObject *game_object;
	const GLib::Sprites::Sprite *sprite;
};