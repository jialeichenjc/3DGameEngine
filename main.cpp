#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Monster.h"
#include "Player.h"
#include "MonsterPool.h"

int main() {
	//cout << "Please enter the number of monsters you'd like to create: \n";
	int num_monsters;
	//cin >> num_monsters;
	printf("Please enter the number of monsters you'd like to create:\n");
	scanf_s("%d", &num_monsters);
	//constexpr int num_monsters = num_monsters_input;
	Monster *monsters = new Monster[num_monsters]; 

	for (int i = 0; i < num_monsters; i++) {
		Monster monster;
		char monster_name[30];
		printf("Please enter your name for monster number %d: ", i);
		scanf_s("%s", monster_name, sizeof(monster_name));
		monster.set_name(monster_name);
		monsters[i] = monster;
		//printf("\nmonsters array size is %d", monsters.length());
		printf("monster %s is at position [%d, %d]\n", monster.get_name(), monster.position[0], monster.position[1]);
	} 
	/*
	MonsterPool monster_pool(num_monsters);
	for (int i = 0; i < num_monsters; i++) {
		Monster monster;
		char monster_name[30];
		printf("Please enter your name for monster number %d: ", i);
		scanf_s("%s", monster_name, sizeof(monster_name));
		monster_pool.get_monsters[i].set_name(monster_name);
		//printf("\nmonsters array size is %d", monsters.length());
		printf("monster %s is at position [%d, %d]\n", monster.get_name(), monster.position[0], monster.position[1]);
	}
	*/
	Player player;
	char player_name[30];
	printf("Please enter your name for the player: \n");
	scanf_s("%s", player_name, sizeof(player_name));
	player.set_name(player_name);
	printf("\n");
	printf("Player %s is at position [%d, %d]\n", player.get_name(), player.position[0], player.position[1]);

	// main game loop
	int input;
	while (input = toupper(_getch()) != 'Q') {
		printf("Move your player. Left: A, Right: D, Up: W, Down: S\n");
		input = toupper(_getch());
		player.move(input);
		printf("\nPlayer %s is at position [%d, %d]\n", player.get_name(), player.position[0], player.position[1]);
		// TODO: other ways to get size of dynamic array besides hard-coding?
		for (int i = 0; i < num_monsters; i++) {
			monsters[i].move();
			printf("monster %s is at position [%d, %d]\n", monsters[i].get_name(), monsters[i].position[0], monsters[i].position[1]);
		}
	}
	
	// cout << num_monsters;
	return 0;
}