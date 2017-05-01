#include "Graphics.h"
#include "GLib.h"
void Graphics::BeginRendering() {
	GLib::BeginRendering();
	GLib::Sprites::BeginRendering();
}

void Graphics::EndRendering() {
	GLib::Sprites::EndRendering();
	GLib::EndRendering();
}

void Graphics::Render(GameObject * i_pGameObject) {
	//BeginRendering();
	Vector3D position = i_pGameObject->GetPosition();
	// convert 3D position to 2D offset for sprite rendering
	float OffsetX = position.x();
	float OffsetY = position.y();
	GLib::Point2D Offset = { OffsetX, OffsetY };
	GLib::Sprites::RenderSprite(*i_pGameObject->GetSprite(), Offset, 0.0f);
}

