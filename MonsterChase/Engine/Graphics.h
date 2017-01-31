#pragma once
#include "GLib.h"
#include "MemoryAllocator.h"
#include "FixedSizeAllocator.h"
namespace Graphics {
	void render();

	void render() {
		MemoryAllocator* test_allocator = MemoryAllocator::get_instance();
		FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();
	}
}