#pragma once
#include "GLib.h"
#include "GameObject.h"
#include "MemoryManager/MemoryAllocator.h"
#include "MemoryManager/FixedSizeAllocator.h"
namespace Graphics {

	void initialize(HINSTANCE i_hInstance, int i_nCmdShow);

	void render(GameObject *);

}