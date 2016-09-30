#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Monster.h"
#include "Player.h"
#include "MonsterController.h"
#include "time.h"

int main() {
	srand((unsigned int)time(NULL));
	int num_monsters;
	printf("Please enter the number of monsters you'd like to create:\n");
	scanf_s("%d", &num_monsters);
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
	return 0;
}


