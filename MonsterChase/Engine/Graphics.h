#pragma once
#include "GLib.h"
#include "GameObject.h"
#include "MemoryManager/MemoryAllocator.h"
#include "MemoryManager/FixedSizeAllocator.h"
namespace Graphics {

	void BeginRendering();

	void Render(GameObject *);
	void Render(GLib::Sprites::Sprite *, float i_x, float i_y);

	void EndRendering();

	GLib::Sprites::Sprite * CreateSprite(const char * i_pFilename);

	void * LoadFile(const char * i_pFilename, size_t & o_sizeFile);
}