#include "Player.h"
#include "MonsterController.h"
#include "Debug.h"
#include "MemoryManager/MemoryAllocator.h"
#include "Test/MemoryAllocatorTest.h"
#include "Test/EngineTestSuite.h"
//#include "BitArray.h"
//#include "GameObject.h"
//#include "MemoryAllocatorUnitTest.h"
//#include "FixedSizeAllocator.h"
//#include "time.h"
//#include "Game.h"
//using namespace Game;

//void Game::init() {
//	MemoryAllocator* allocator = MemoryAllocator::get_instance();
//	FixedSizeAllocator* fsa_allocator = FixedSizeAllocator::get_instance();
//	size_t monster_count = 10;
//	srand((unsigned int)time(NULL));
//	std::vector<Monster*> monsters;
//	for (size_t i = 0; i < DEFAULT_MONSTER_SIZE; i++) {
//		Monster *monster = new Monster();
//		monster->init_pos();
//		const char *monster_name = monster->get_name();
//		printf("Please enter your name for monster number %zu: ", i);
//		scanf_s("%s", monster_name, 20);
//		monster->set_name(monster_name);
//		monsters.push_back(monster);
//	}
//
//	Player* player = new Player();
//	player->init_pos();
//	char* player_name = DEFAULT_PLAYER_NAME;
//	player->set_name(player_name);
//}
//
//void Game::shut_down() {
//	delete player;
//
//	for (size_t i = 0; i < num_monsters; i++)
//	{
//		delete monsters[i];
//	}
//	fsa_allocator->destroy_instance();
//	allocator->destroy_instance();
//}