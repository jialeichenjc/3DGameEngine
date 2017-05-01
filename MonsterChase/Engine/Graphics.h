#pragma once
#include "GLib.h"
#include "GameObject.h"
#include "MemoryManager/MemoryAllocator.h"
#include "MemoryManager/FixedSizeAllocator.h"
namespace Graphics {

	void BeginRendering();

	void Render(GameObject *);

	void EndRendering();

}