
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
int whoWin(char b[][3]) {
	int i, j;
	

	//가로 세가지 경우
	
	if (b[0][0] == b[0][1] && b[0][1] == b[0][2] && b[0][0] != '\0' && b[0][1] != '\0' && b[0][2] != '\0') {
		if (b[0][0] == 'X') 
			return 1;
		else if(b[0][0]=='O')
			return 2;
	}
		
	if (b[1][0] == b[1][1] && b[1][1] == b[1][2] && b[1][0] != '\0' && b[1][1] != '\0' && b[1][2] != '\0') {
		if (b[1][0] == 'X')
			return 1;
		else if (b[1][0] == 'O')
			return 2;
	}

	if (b[2][0] == b[2][1] && b[2][1] == b[2][2] && b[2][0] != '\0' && b[2][1] != '\0' && b[2][2] != '\0') {
		if (b[2][0] == 'X')
			return 1;
		else if (b[2][0] == 'O')
			return 2;
	}
	
	
	//세로 세가지 경우
	if (b[0][0] == b[1][0] && b[1][0] == b[2][0] && b[0][0] != '\0' && b[1][0] != '\0' && b[2][0] != '\0') {
		if (b[0][0] == 'X')
			return 1;
		else if (b[0][0] == 'O')
			return 2;
	}
	if (b[0][1] == b[1][1] && b[1][1] == b[2][1] && b[0][1] != '\0' && b[1][1] != '\0' && b[2][1] != '\0') {
		if (b[0][1] == 'X')
			return 1;
		else if (b[0][1] == 'O')
			return 2;
	}

	if (b[0][2] == b[1][2] && b[1][2] == b[2][2] && b[0][2] != '\0' && b[1][2] != '\0' && b[2][2] != '\0') {
		if (b[0][2] == 'X')
			return 1;
		else if (b[0][2] == 'O')
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
	int i, j, count = 0, win;
	char b[3][3] = { ' ' };
	char x = 'X', o = 'O';
	char player = ' ';
	
	display(b);
	while (1) {
		if (count % 2 == 0)
			player = x;
		else player = o;

		printf("Player %c<행 열>:", player);
		scanf("%d %d", &i, &j);
		if (b[i][j] == 'X' || b[i][j] == 'O') 
			continue;
		
		else
			b[i][j] = player;
		count++;
		display(b);
		win = whoWin(b);

		if (win == 1) {
			printf("Player X wins!");
			break;
		}
		else if (win == 2) { 
			printf("Player O wins!"); 
			break;
		}
		else if (win == 3) {
			printf("Nobody wins!");
			break;
		}
	} 

}