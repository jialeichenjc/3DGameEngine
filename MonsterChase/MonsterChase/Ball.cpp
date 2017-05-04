#include "Ball.h"
#include "GameObject.h"
#include <ctype.h>
#define DEFAULT_BALL_NAME "Ball"

Ball::Ball() {
	m_pGameObject = new GameObject();
}

void Ball::SetName(const char * i_name) {
	m_pGameObject->SetName(DEFAULT_BALL_NAME);
}

const char* Ball::GetName() const {
	return m_pGameObject->GetName();
}

Vector3D Ball::GetPosition() const {
	return m_pGameObject->GetPosition();
}

void Ball::SetPosition(const Vector3D & i_vec) {
	m_pGameObject->SetPosition(i_vec);
}

void Ball::SetInitPosition() {
	m_pGameObject->SetPosition(Vector3D(0.0f, 0.0f, 0.0f));
}

void Ball::SetGameObject(GameObject *game_object) {
	m_pGameObject = game_object;
}

GameObject * Ball::GetGameObject() const {
	return m_pGameObject;
}

void Ball::SetSprite(const GLib::Sprites::Sprite *i_sprite) {
	m_pGameObject->SetSprite(i_sprite);
}
const GLib::Sprites::Sprite * Ball::GetSprite() const {
	return m_pGameObject->GetSprite();
}

void Ball::Move(Vector3D & i_vec) {
	m_pGameObject->Move(i_vec);
}

Vector3D Ball::GetVelocity() const {
	return m_pGameObject->GetVelocity();
}
void Ball::SetVelocity(const Vector3D & i_vec) {
	m_pGameObject->SetVelocity(i_vec);
}
void Ball::MoveWithVelocity() {
	m_pGameObject->MoveWithVelocity();
}

Ball::~Ball() {
	delete m_pGameObject;
}
