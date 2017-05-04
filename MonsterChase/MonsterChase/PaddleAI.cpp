#include "PaddleAI.h"
#include "GameObject.h"
#include <ctype.h>
#define DEFAULT_COMPUTER_NAME "Computer Player"
const Vector3D UP = Vector3D(0.0, 1.0, 0.0);
const Vector3D DOWN = Vector3D(0.0, -1.0, 0.0);
const Vector3D LEFT = Vector3D(-1.0, 0.0, 0.0);
const Vector3D RIGHT = Vector3D(1.0, 0.0, 0.0);

PaddleAI::PaddleAI()
{
	m_pGameObject = new GameObject();
}

void PaddleAI::SetName(const char* i_name) {
	m_pGameObject->SetName(DEFAULT_COMPUTER_NAME);
}

const char* PaddleAI::GetName() const {
	return m_pGameObject->GetName();
}

Vector3D PaddleAI::GetPosition() const {
	return m_pGameObject->GetPosition();
}

void PaddleAI::SetPosition(const Vector3D & i_vec) {
	m_pGameObject->SetPosition(i_vec);
}

void PaddleAI::SetInitPosition() {
	m_pGameObject->SetPosition(Vector3D(0.0f, 0.0f, 0.0f));
}

void PaddleAI::SetGameObject(GameObject *game_object) {
	m_pGameObject = game_object;
}

GameObject * PaddleAI::GetGameObject() const {
	return m_pGameObject;
}

void PaddleAI::MoveByAI() {

}

Vector3D PaddleAI::GetVelocity() const {
	return m_pGameObject->GetVelocity();
}
void PaddleAI::SetVelocity(const Vector3D & i_vec) {
	m_pGameObject->SetVelocity(i_vec);
}
void PaddleAI::MoveWithVelocity() {
	m_pGameObject->MoveWithVelocity();
}


void PaddleAI::SetSprite(const GLib::Sprites::Sprite *i_sprite) {
	m_pGameObject->SetSprite(i_sprite);
}
const GLib::Sprites::Sprite * PaddleAI::GetSprite() const {
	return m_pGameObject->GetSprite();
}

PaddleAI::~PaddleAI() {
	delete m_pGameObject;
}
