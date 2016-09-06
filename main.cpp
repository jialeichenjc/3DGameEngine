#include <stdio.h>
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
	char *test_str = "";
	for (int i = 0; i < num_monsters; i++) {
		Monster monster;
		char monster_name[30];
		printf("Please enter your name for monster number %d: ", i);
		scanf_s("%s", test_str);
		monster.set_name(monster_name);
	}
	printf("\n");
	//cout << num_monsters;
	return 0;
}