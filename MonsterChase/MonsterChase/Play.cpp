#include "Play.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <crtdbg.h>
#include <vector>
#include <intrin.h>
#include "Monster.h"
#include "Player.h"
#include "MonsterController.h"
#include "Debug.h"
#include "MemoryManager/MemoryAllocator.h"
#include "Test/MemoryAllocatorTest.h"
#include "Test/EngineTestSuite.h"
#include "MemoryManager/BitArray.h"
#include "GameObject.h"
#include "Test/MemoryAllocatorUnitTest.h"
#include "MemoryManager/FixedSizeAllocator.h"
#include "time.h"
void play() {
	/*MemoryAllocator* allocator = MemoryAllocator::get_instance();
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();
	srand((unsigned int)time(NULL));
	size_t num_monsters;
	printf("Please enter the number of monsters you'd like to create:\n");
	scanf_s("%zu", &num_monsters);
	assert(num_monsters > 0, "Invalid number of monsters");
	MonsterController monster_controller;*/

	//std::vector<Monster*> monsters;
	//for (size_t i = 0; i < num_monsters; i++) {
	//	Monster *monster = new Monster();
	//	monster->init_pos();
	//	const char *monster_name = monster->get_name();
	//	printf("Please enter your name for monster number %zu: ", i);
	//	scanf_s("%s", monster_name, 20);
	//	monster->set_name(monster_name);
	//	monsters.push_back(monster);
	//}

	//Player *player = new Player();
	//player->init_pos();
	//char player_name[20];
	//printf("Please enter your name for the player: ");
	//scanf_s("%s", player_name, sizeof(player_name));
	//assert(sizeof(player_name) <= 30, "Your name is too long. Please choose another name.");
	//player->set_name(player_name);
	//printf("\nPlayer %s is at position [%.2f, %.2f]\n", player->get_name(), player->get_position().x(), player->get_position().y());
	//monster_controller.move_and_print_monsters(monsters, num_monsters);
	//printf("Press Enter to continue...\n");

	// Main game loop
	//int input;
	/*while (input = toupper(_getch()) != 'Q') {
		printf("Move your player. Left: A, Right: D, Up: W, Down: S\n");
		input = toupper(_getch());
		assert((input == 'A' || input == 'W' || input == 'S' || input == 'D'), "Invalid input");
		player->move_from_user_input(input);
		printf("\nPlayer %s is at position [%.2f, %.2f]\n", player->get_name(), player->get_position().x(), player->get_position().y());

		monster_controller.move_and_print_monsters(monsters, num_monsters);

		if (monster_controller.should_add_monster()) {
			printf("A monster has been added to the game...\n");
			monster_controller.add_monster(monsters, num_monsters);
		}

		if (monster_controller.should_delete_monster(num_monsters)) {
			printf("A monster has been deleted from the game...\n");
			monster_controller.destroy_monster(monsters, num_monsters);
		}
		printf("\nPress Enter to continue...\n");
		printf("Or press Q to quit game.\n");
	}*/
	/*delete player;

	for (size_t i = 0; i < num_monsters; i++)
	{
		delete monsters[i];
	}
	fsa_allocator->destroy_instance();
	allocator->destroy_instance();*/
}