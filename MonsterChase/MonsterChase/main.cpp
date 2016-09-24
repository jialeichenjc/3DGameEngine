#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Monster.h"
#include "Player.h"
#include "time.h"
Monster* add_monster(Monster *monsters, int& num_monsters);
void destroy_monster(Monster *monsters, int& num_monsters);
bool should_add_monster();
bool should_delete_monster(int& num_monsters);
void print_monsters(Monster *monsters, int& num_monsters);

int main() {
	srand((unsigned int)time(NULL));
	int num_monsters;
	printf("Please enter the number of monsters you'd like to create:\n");
	scanf_s("%d", &num_monsters);

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
	print_monsters(monsters, num_monsters);
	printf("Press Enter to continue...\n");

	// Main game loop
	int input;
	while (input = toupper(_getch()) != 'Q') {
		printf("Move your player. Left: A, Right: D, Up: W, Down: S\n");
		input = toupper(_getch());
		player.move(input);
		printf("\nPlayer %s is at position [%.2f, %.2f]\n", player.get_name(), player.get_position().x(), player.get_position().y());
		print_monsters(monsters, num_monsters);

		if (should_add_monster()) {
			printf("A monster has been added to the game...\n");
			monsters = add_monster(monsters, num_monsters);
		}

		if (should_delete_monster(num_monsters)) {
			printf("A monster has been deleted from the game...\n");
			destroy_monster(monsters, num_monsters);
		}
		printf("\nPress Enter to continue...\n");
		printf("Or press Q to quit game.\n");
	}
	return 0;
}

Monster* add_monster(Monster *monsters, int& num_monsters) {
	Monster *new_monsters = new Monster[++num_monsters];

	for (int i = 0; i < num_monsters - 1; i++) {
		new_monsters[i] = monsters[i];
	}
	Monster added_monster;
	added_monster.set_name("Machine Added");
	new_monsters[num_monsters - 1] = added_monster;

	return new_monsters;
}

bool should_add_monster() {
	int chance = rand() % 5 + 1;
	if (chance == 1) {
		return true;
	}
	else
		return false;
}

void destroy_monster(Monster *monsters, int& num_monsters) {
	monsters[num_monsters - 1].~Monster();
	num_monsters--;
}

bool should_delete_monster(int& num_monsters) {
	int chance = rand() % 8 + 1;
	if (chance == 4 && num_monsters > 1) {
		return true;
	}
	else
		return false;
}

void print_monsters(Monster *monsters, int& num_monsters) {
	for (int i = 0; i < num_monsters; i++) {
		Vector2D monster_pos = monsters[i].get_position();
		monsters[i].move();
		printf("monster %s is at position [%.2f, %.2f]\n", monsters[i].get_name(), monster_pos.x(), monster_pos.y());
	}
}


