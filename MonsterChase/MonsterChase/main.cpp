#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <crtdbg.h>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "MonsterController.h"
#include "Debug.h"
#include "MemoryAllocator.h"
#include "MemoryAllocatorTest.h"
#include "EngineTestSuite.h"
#include "time.h"

void printList(BlockDescriptorList);
int main() {
	//_crtBreakAlloc = 160;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	/*
	printf("Testing Vector 2D class with const paramters\n");
	EngineTestSuite engine_test;
	engine_test.testVector2D();	
	*/

	MemoryAllocator* allocator = MemoryAllocator::get_instance();
	srand((unsigned int)time(NULL));
	int num_monsters;
	printf("Please enter the number of monsters you'd like to create:\n");
	scanf_s("%d", &num_monsters);
	assert(num_monsters > 0, "Invalid number of monsters");
	MonsterController monster_controller;

	std::vector<Monster*> monsters;
	for (int i = 0; i < num_monsters; i++) {
		Monster *monster = new Monster();
		monster->init_pos();
		const char *monster_name = monster->get_name();
		printf("Please enter your name for monster number %d: ", i);
		scanf_s("%s", monster_name, 20);
		monster->set_name(monster_name);
		monsters.push_back(monster);
	}

	Player *player = new Player();
	player->init_pos();
	char player_name[20];
	printf("Please enter your name for the player: ");
	scanf_s("%s", player_name, sizeof(player_name));
	assert(sizeof(player_name) <= 30, "Your name is too long. Please choose another name.");
	player->set_name(player_name);
	printf("\nPlayer %s is at position [%.2f, %.2f]\n", player->get_name(), player->get_position().x(), player->get_position().y());
	monster_controller.move_and_print_monsters(monsters, num_monsters);
	printf("Press Enter to continue...\n");

	// Main game loop
	int input;
	while (input = toupper(_getch()) != 'Q') {
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
	}
	delete player;
	
	for (size_t i = 0; i < num_monsters; i++)
	{
		delete monsters[i];
	}
	
	//MemoryAllocator* allocator = MemoryAllocator::get_instance();
	printf("size of memory allocator is %zu", sizeof(*allocator));

	srand((unsigned int)time(NULL));
	printf("\n\n-------------TEST ALLOCATION-------------\n");
	for (int i = 0; i < 100; i++) {
	size_t requested_size = rand() % 100 + 1;
	printf("\nallocating %zu bytes of memory\n", requested_size);
	allocator->alloc_mem(requested_size);
	}

	printf("\n\n>>>>>>memory in use\n");
	printList(allocator->in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator->free_mem_bd_list);

	printf("\n\n-------------TEST FREE-------------\n");
	for (int i = 0; i < 50; i++) {
		size_t requested_size = rand() % 100 + 1;
		char *test_ptr = static_cast<char*> (allocator->alloc_mem(requested_size));
		allocator->free_mem(test_ptr);
	}
	printf("\n\n>>>>>>memory in use:\n");
	printList(allocator->in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator->free_mem_bd_list);
	
	printf("\n\n-------------TEST COALESCE-------------\n");
	allocator->coalesce_mem();
	printf("\n\n>>>>>>memory in use:\n");
	printList(allocator->in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator->free_mem_bd_list);

	allocator->destroy_instance();
	return 0;
}

void printList(BlockDescriptorList list) {
	if (list.head == NULL) {
		return;
	}
	else {
		BlockDescriptor *curr = list.head;
		while (curr != NULL) {
			printf("\nsize of block descriptor is %zu and the memory pointer is %p\n", 
				curr->block_size, curr->block_base_ptr);
			curr = curr->next_bd;
		}
		printf("size of block list is %zu", list.size);
	}
}