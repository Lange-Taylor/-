#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int blank_count_already_show = 0;
int Menu() {
	printf("*****************************\n");
	printf("**********1.开始游戏*********\n");
	printf("**********0.结束游戏*********\n");
	printf("*****************************\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10
void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			mine_map[row][col] = '0';
		}
		srand((unsigned int)time(0));
	}
	int n = MINE_COUNT;
	while (n > 0)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			continue;
		}
		mine_map[row][col] = '1';
		n--;
	}
}
void PrintMap(char map[MAX_ROW][MAX_COL]) {
	printf("    ");
	for (int col = 0; col < MAX_COL; col++) {
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 0; col <= MAX_COL; col++) {
		printf("--");
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf(" %d| ", row);
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void Digui(int row, int col, 
	char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 &&
		row - 1 < MAX_ROW && col - 1 < MAX_COL
		&& mine_map[row - 1][col - 1] == '1') {
		count++;
	}
	if (row - 1 >= 0 && col >= 0 &&
		row - 1 < MAX_ROW && col < MAX_COL
		&& mine_map[row - 1][col] == '1') {
		count++;
	}if (row - 1 >= 0 && col + 1 >= 0 &&
		row - 1 < MAX_ROW && col + 1 < MAX_COL
		&& mine_map[row - 1][col + 1] == '1') {
		count++;
	}if (row >= 0 && col - 1 >= 0 &&
		row < MAX_ROW && col - 1 < MAX_COL
		&& mine_map[row][col - 1] == '1') {
		count++;
	}if (row >= 0 && col + 1 >= 0 &&
		row < MAX_ROW && col + 1 < MAX_COL
		&& mine_map[row][col + 1] == '1') {
		count++;
	}if (row + 1 >= 0 && col - 1 >= 0 &&
		row + 1 < MAX_ROW && col - 1 < MAX_COL
		&& mine_map[row + 1][col - 1] == '1') {
		count++;
	}if (row + 1 >= 0 && col >= 0 &&
		row + 1 < MAX_ROW && col < MAX_COL
		&& mine_map[row + 1][col] == '1') {
		count++;
	}if (row + 1 >= 0 && col + 1 >= 0 &&
		row + 1 < MAX_ROW && col + 1 < MAX_COL
		&& mine_map[row + 1][col + 1] == '1') {
		count++;
	}
	show_map[row][col] = '0' + count;
	blank_count_already_show++;
	if (count == 0) {
		show_map[row][col] = ' ';
		if (row - 1 >= 0 && col - 1 >= 0 &&
			row - 1 < MAX_ROW && col - 1 < MAX_COL
			&& show_map[row - 1][col - 1] == '*') {
			Digui(row - 1, col - 1, 
				show_map,
				mine_map);
		}
		if (row - 1 >= 0 && col >= 0 &&
			row - 1 < MAX_ROW && col < MAX_COL
			&& show_map[row - 1][col] == '*') {
			Digui(row - 1, col, 
				show_map,
				mine_map);
		}if (row - 1 >= 0 && col + 1 >= 0 &&
			row - 1 < MAX_ROW && col + 1 < MAX_COL
			&& show_map[row - 1][col + 1] == '*') {
			Digui(row - 1, col + 1, 
				show_map,
				mine_map);
		}if (row >= 0 && col - 1 >= 0 &&
			row < MAX_ROW && col - 1 < MAX_COL
			&& show_map[row][col - 1] == '*') {
			Digui(row, col - 1, 
				show_map,
				mine_map);
		}if (row >= 0 && col + 1 >= 0 &&
			row < MAX_ROW && col + 1 < MAX_COL
			&& show_map[row][col + 1] == '*') {
			Digui(row, col + 1, 
				show_map,
				mine_map);
		}if (row + 1 >= 0 && col - 1 >= 0 &&
			row + 1 < MAX_ROW && col - 1 < MAX_COL
			&& show_map[row + 1][col - 1] == '*') {
			Digui(row + 1, col - 1, 
				show_map,
				mine_map);
		}if (row + 1 >= 0 && col >= 0 &&
			row + 1 < MAX_ROW && col < MAX_COL
			&& show_map[row + 1][col] == '*') {
			Digui(row + 1, col, 
				show_map,
				mine_map);
		}if (row + 1 >= 0 && col + 1 >= 0 &&
			row + 1 < MAX_ROW && col + 1 < MAX_COL
			&& show_map[row + 1][col + 1] == '*') {
			Digui(row + 1, col + 1,
				show_map,
				mine_map);
		}

	}
}
void Game() {
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	
	Init(show_map, mine_map);
	while (1) {
		PrintMap(show_map);
		printf("请输入一组坐标:[row,col]");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("您输入的坐标非法,请重新输入:\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			printf("您输入的坐标已被翻开.请重新输入:\n");
			continue;
		}
		if (mine_map[row][col] == '1') {
			printf("您踩雷了,游戏结束!\n");
			PrintMap(mine_map);
			break;
		}
		Digui(row, col, show_map, mine_map);
		if (blank_count_already_show
			== ((MAX_ROW * MAX_COL) - MINE_COUNT)) {
			printf("恭喜你获得游戏胜利!\n");
			PrintMap(mine_map);
			break;
		}
	}
}
int main() {
	while (1)
	{

		int choise = Menu();
		if (choise == 1) {
			Game();
		}
		else if (choise == 0) {
			printf("goodbye!\n");
			break;
		}
		else {
			printf("您的输入有误,请重新输入.\n");
		}
	}
	system("pause");
	return 0;
}