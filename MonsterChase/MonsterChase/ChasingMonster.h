#pragma once
#include "IGameObjectController.h"
class GameObject;

class ChasingMonster : public IGameObjectController {
public:
	ChasingMonster(); // create a new monster with a random initial position
	void init_pos() override;
	void set_game_object(GameObject *object) override;
	void set_name(const char *name) override;
	const char* get_name() const override;
	Vector3D get_position() const override;
	void set_position(const Vector3D &vec) override;
	void move_chasing(const Vector3D &target_pos);

	~ChasingMonster();

private:
	GameObject *game_object;
};