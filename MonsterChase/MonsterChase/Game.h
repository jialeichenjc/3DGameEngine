#pragma once
#define DEFAULT_MONSTER_SIZE 4
#define DEFAULT_PLAYER_NAME "Player1"
#define DEFAULT_COLLIDABLE_SIZE 10
#include "MemoryManager/MemoryAllocator.h"
#include "Physics\Collidable.h"
#include "PaddleAI.h"
#include "PaddlePlayer.h"

namespace Game {
	/*size_t num_monsters;
	MonsterController monster_controller;
	std::vector<Monster*> monsters;
	Player *player;*/
/*
	MemoryAllocator* allocator;
	FixedSizeAllocator *fsa_allocator;*/
	// testing, to be deleted
	/*size_t monster_count;*/

	void init();
	void render(GameObject *);
	void run();
	void shut_down();
}
