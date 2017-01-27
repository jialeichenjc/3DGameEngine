#pragma once
#define DEFAULT_MONSTER_SIZE 4
#define DEFAULT_PLAYER_NAME "Player1"
namespace Game {
	void init();
	void run();
	void shut_down();

	extern size_t num_monsters;
	extern MonsterController monster_controller;
	extern std::vector<Monster*> monsters;
	extern Player *player;

	extern MemoryAllocator* allocator;
	extern FixedSizeAllocator *fsa_allocator;
}
