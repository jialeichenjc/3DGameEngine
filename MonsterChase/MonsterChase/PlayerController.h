#pragma once
#include "IGameObjectController.h"
class PlayerController : public IGameObjectController {
public:
	void set_name(const char* name) override;
	const char* get_name() const override {
		return m_pObject->get_name();
	}
	
	Vector2D get_position() const {
		return m_pObject->get_position;
	}

	void set_position(const Vector2D &vec) override;
	virtual void move_next(const Vector2D &delta_vec) = 0; // move game object by delta_x and delta_y
	virtual void init_pos() = 0; // set the initial posiion for the character
	virtual void move() = 0;
	virtual void SetGameObject(GameObject *pObject) = 0;
	virtual void UpdateGameObject() = 0;
	PlayerController();
	~PlayerController();

private:
	GameObject *m_pObject;
};


inline void PlayerController::set_name(const char* name) {
	m_pObject->set_name(name);
}

inline const char* PlayerController::get_name() const {
	return m_pObject->get_name();
}

inline Vector2D PlayerController::get_position() const {
	return m_pObject->get_position();
}

inline void PlayerController::set_position(const Vector2D &vec) {
	m_pObject->set_position(vec);
}

inline void GameObject::move_next(const Vector2D &delta_vec) {
	position = position + delta_vec;
}