#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Monster.h"
#include "Player.h"

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
		printf("monster %s is at position [%d, %d]\n", monster.get_name(), monster.position[0], monster.position[1]);
	}
	printf("\n");
	//cout << num_monsters;
	return 0;
}