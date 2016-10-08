#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Monster.h"
#include "Player.h"
#include "MonsterController.h"
#include "Debug.h"
#include "MemoryAllocator.h"
#include "time.h"

void printList(BlockDescriptorList);
int main() {
	/*
	srand((unsigned int)time(NULL));
	int num_monsters;
	printf("Please enter the number of monsters you'd like to create:\n");
	scanf_s("%d", &num_monsters);
	assert(num_monsters > 0, "Invalid number of monsters");
	MonsterController monster_controller;

	Monster *monsters = new Monster[num_monsters];
	for (int i = 0; i < num_monsters; i++) {
		Monster monster;
		char *monster_name = new char[30];
		printf("Please enter your name for monster number %d: ", i);
		scanf_s("%s", monster_name, sizeof(monster_name));
		monsters[i].set_name(monster_name);
	}
	Player player;
	char player_name[30];
	printf("Please enter your name for the player: ");
	scanf_s("%s", player_name, sizeof(player_name));
	player.set_name(player_name);
	printf("\nPlayer %s is at position [%.2f, %.2f]\n", player.get_name(), player.get_position().x(), player.get_position().y());
	monster_controller.print_monsters(monsters, num_monsters);
	printf("Press Enter to continue...\n");

	// Main game loop
	int input;
	while (input = toupper(_getch()) != 'Q') {
		printf("Move your player. Left: A, Right: D, Up: W, Down: S\n");
		input = toupper(_getch());
		assert((input == 'A' || input == 'W' || input == 'S' || input == 'D'), "Invalid input");
		player.move(input);
		printf("\nPlayer %s is at position [%.2f, %.2f]\n", player.get_name(), player.get_position().x(), player.get_position().y());

		monster_controller.print_monsters(monsters, num_monsters);

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
	*/
	/*
	printf("Allocating Memory...\n");
	MemoryAllocator mem_alloc;
	printf("Now total number of bytes in memory is: %d \n", (int)mem_alloc.mem_free.head->block_size);
	printf("Requesting 12 bytes of memory...\n");
	mem_alloc.alloc_mem((size_t)12);
	printf("Now total number of bytes available is: %d \n", (int)mem_alloc.mem_free.head->block_size);
	printf("\n");
	*/
	BlockDescriptorList test_list = BlockDescriptorList(10);
	printList(test_list);
	return 0;
}

// TODO: delete this later
void printList(BlockDescriptorList list) {
	if (list.head == NULL) {
		return;
	}
	else {
		BlockDescriptor *curr = list.head;
		while (curr != NULL) {
			printf("size of block descriptor is %d and the memory pointer is %p", curr->block_size, curr->block_base_ptr);
			curr = curr->next_bd;
		}
	}
}