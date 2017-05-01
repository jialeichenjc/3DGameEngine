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
	BeginRendering();
	Vector3D position = i_pGameObject->GetPosition();
	// convert 3D position to 2D offset for sprite rendering
	static GLib::Point2D CourtOffset = { position.x(), position.y() };
	GLib::Sprites::RenderSprite(*i_pGameObject->GetSprite(), CourtOffset, 0.0f);
}

