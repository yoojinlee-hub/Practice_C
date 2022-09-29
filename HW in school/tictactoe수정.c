#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char b[][3]) {
	int i, j;

	printf("   0 1 2\n");
	printf("   ------\n");
	for (i = 0; i < 3; i++) {
		printf("%d : ", i);
		for (j = 0; j < 3; j++)
			printf("%c ", b[i][j]);
		printf("\n");
	}
}
int whoWin(char b[][3], int size) {
	int i, j;

	//가로 세가지 경우
	for (i = 0; i < size; i++){
		if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != '\0' && b[i][1] != '\0' && b[i][2] != '\0')
			if (b[i][0] == 'X')
				return 1;
			else if (b[i][0] == 'O')
				return 2;
	}

	//세로 세가지 경우
	for (i = 0; i < size; i++) {
		if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != '\0' && b[1][i] != '\0' && b[2][i] != '\0')
			if (b[0][i] == 'X')
				return 1;
			else if (b[0][i] == 'O')
				return 2;
	}

	//대각선 - 1
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != '\0' && b[1][1] != '\0' && b[2][2] != '\0') {
		if (b[0][0] == 'X')
			return 1;
		else if (b[0][0] == 'O')
			return 2;
	}

	//대각선 - 2
	if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != '\0' && b[1][1] != '\0' && b[2][0] != '\0') {
		if (b[0][2] == 'X')
			return 1;
		else if (b[0][2] == 'O')
			return 2;
	}

	//모두 꽉 찼을 때
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (b[i][j] == '\0')
				return 0;
	return 3;
}
int main(void) {
	int i, j, count = 0, win = 0;
	char b[3][3] = { ' ' };
	char x = 'X', o = 'O';
	char player = ' ';

	display(b);
	while (!win) {
		player = (player == x ? o : x);

		printf("Player %c<행 열>:", player);
		scanf("%d %d", &i, &j);
		if (b[i][j] == 'X' || b[i][j] == 'O')
			continue;
		else
			b[i][j] = player;
		count++;
		display(b);
		win = whoWin(b, 3);
	}

	if (win == 1) 
		printf("Player X wins!");
	else if (win == 2) 
		printf("Player O wins!");
	else if (win == 3) 
		printf("Nobody wins!");

}