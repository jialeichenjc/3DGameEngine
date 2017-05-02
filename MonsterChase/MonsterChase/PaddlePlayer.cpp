#include "PaddlePlayer.h"
#include "GameObject.h"
#include <ctype.h>
#define DEFAULT_PLAYER_NAME "Player1"

const Vector3D UP = Vector3D(0.0, 0.1, 0.0);
const Vector3D DOWN = Vector3D(0.0, -0.1, 0.0);
const Vector3D LEFT = Vector3D(-0.1, 0.0, 0.0);
const Vector3D RIGHT = Vector3D(0.1, 0.0, 0.0);

PaddlePlayer::PaddlePlayer()
{
	m_pGameObject = new GameObject();
}

void PaddlePlayer::SetName(const char* i_name) {
	m_pGameObject->SetName(DEFAULT_PLAYER_NAME);
}

const char* PaddlePlayer::GetName() const {
	return m_pGameObject->GetName();
}

Vector3D PaddlePlayer::GetPosition() const {
	return m_pGameObject->GetPosition();
}

void PaddlePlayer::SetPosition(const Vector3D & i_vec) {
	m_pGameObject->SetPosition(i_vec);
}

void PaddlePlayer::SetInitPosition() {
	m_pGameObject->SetPosition(Vector3D(0.0f, 0.0f, 0.0f));
}

void PaddlePlayer::SetGameObject(GameObject *game_object) {
	m_pGameObject = game_object;
}

GameObject * PaddlePlayer::GetGameObject() const {
	return m_pGameObject;
}

void PaddlePlayer::MoveByPlayer(uint8_t input) {
	//int input = toupper(_getch());
	switch (input) {
	case 'W': // move up
		m_pGameObject->Move(UP);
		break;
	case 'S': // move down
		m_pGameObject->Move(DOWN);
		break;
	case 'A': // move left
		m_pGameObject->Move(LEFT);
		break;
	case 'D': // move right
		m_pGameObject->Move(RIGHT);
		break;
	default:
		break;
	}
}

void PaddlePlayer::SetSprite(const GLib::Sprites::Sprite *i_sprite) {
	m_pGameObject->SetSprite(i_sprite);
}
const GLib::Sprites::Sprite * PaddlePlayer::GetSprite() const {
	return m_pGameObject->GetSprite();
}

PaddlePlayer::~PaddlePlayer() {
	delete m_pGameObject;
}
