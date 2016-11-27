#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <crtdbg.h>
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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	printf("Testing Vector 2D class with const paramters\n");
	EngineTestSuite engine_test;
	engine_test.testVector2D();	
	
	/*
	srand((unsigned int)time(NULL));
	int num_monsters;
	printf("Please enter the number of monsters you'd like to create:\n");
	scanf_s("%d", &num_monsters);
	assert(num_monsters > 0, "Invalid number of monsters");
	MonsterController monster_controller;
	//GameObject::create_mem_allocator(4);
	GameObject *test_object = new GameObject();

	Monster *monsters = new Monster[num_monsters];
	for (int i = 0; i < num_monsters; i++) {
		Monster* monster = new Monster();
		//GameObject* monster_object = new GameObject();
		//monster->set_game_object(monster_object);
		monster->init_pos();
		char *monster_name = new char[30];
		printf("Please enter your name for monster number %d: ", i);
		scanf_s("%s", monster_name, sizeof(monster_name));
		monster->set_name(monster_name);
		monsters[i] = *monster;
	}

	Player *player = new Player();
	//GameObject player_object;
	//player.set_game_object(&player_object);
	player->init_pos();
	char player_name[30];
	printf("Please enter your name for the player: ");
	scanf_s("%s", player_name, sizeof(player_name));
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
			monsters = monster_controller.add_monster(monsters, num_monsters);
		}

		if (monster_controller.should_delete_monster(num_monsters)) {
			printf("A monster has been deleted from the game...\n");
			monster_controller.destroy_monster(monsters, num_monsters);
		}
		printf("\nPress Enter to continue...\n");
		printf("Or press Q to quit game.\n");
	}
	delete[] monsters;
	*/
	
	MemoryAllocator allocator(8);
	srand((unsigned int)time(NULL));
	printf("\n\n-------------TEST ALLOCATION-------------\n");
	for (int i = 0; i < 200; i++) {
	size_t requested_size = rand() % 100 + 1;
	printf("\nallocating %zu bytes of memory\n", requested_size);
	allocator.alloc_mem(requested_size);
	}

	printf("\n\n>>>>>>memory in use\n");
	printList(allocator.in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator.free_mem_bd_list);

	printf("\n\n-------------TEST FREE-------------\n");
	for (int i = 0; i < 5; i++) {
		size_t requested_size = rand() % 100 + 1;
		char *test_ptr = static_cast<char*> (allocator.alloc_mem(requested_size));
		allocator.free_mem(test_ptr);
	}
	printf("\n\n>>>>>>memory in use:\n");
	printList(allocator.in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator.free_mem_bd_list);
	
	printf("\n\n-------------TEST COALESCE-------------\n");
	allocator.coalesce_mem();
	printf("\n\n>>>>>>memory in use:\n");
	printList(allocator.in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator.free_mem_bd_list);
	//MemoryAllocatorTest allocator_test;
	//allocator_test.test_mem_alloc(50);
	//allocator_test.test_free_alloc(50);
	
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