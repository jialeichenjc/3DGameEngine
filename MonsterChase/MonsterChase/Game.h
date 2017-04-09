#pragma once
#define DEFAULT_MONSTER_SIZE 4
#define DEFAULT_PLAYER_NAME "Player1"
#include "MemoryManager/MemoryAllocator.h"
namespace Game {
	size_t num_monsters;
	MonsterController monster_controller;
	std::vector<Monster*> monsters;
	Player *player;

	MemoryAllocator* allocator;
	FixedSizeAllocator *fsa_allocator;
	// testing, to be deleted
	size_t monster_count;

	void init();
	void run();
	void shut_down();

	void init() {
		allocator = MemoryAllocator::get_instance();
		fsa_allocator = FixedSizeAllocator::get_instance();

		srand((unsigned int)time(NULL));
		for (size_t i = 0; i < DEFAULT_MONSTER_SIZE; i++) {
			Monster *monster = new Monster();
			monster->init_pos();
			const char *monster_name = monster->get_name();
			printf("Please enter your name for monster number %zu: ", i);
			scanf_s("%s", monster_name, 20);
			monster->set_name(monster_name);
			monsters.push_back(monster);
		}

		player = new Player();
		player->init_pos();
		char* player_name = DEFAULT_PLAYER_NAME;
		player->set_name(player_name);
	}

	void shut_down() {
		for (size_t i = 0; i < DEFAULT_MONSTER_SIZE; i++)
		{
			delete monsters[i];
		}


		delete player;
		//fsa_allocator->destroy_instance();
		//allocator->destroy_instance();
	}
}
