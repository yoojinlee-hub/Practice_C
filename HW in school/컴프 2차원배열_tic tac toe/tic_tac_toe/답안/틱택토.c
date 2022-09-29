#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char board[3][3];
	int x, y, k, i, l, m, flag = 0;

	// 보드를 초기화한다. 
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++) board[x][y] = ' ';

	// 사용자로부터 위치를 받아서 보드에 표시한다. 
	for (k = 0; k < 9; k++) {
		if (k % 2 == 0) { // 컴퓨터 차례
			for (l = 0; l < 3; l++) {
				for (m = 0; m < 3; m++) {
					if (board[l][m] == ' ') {
						x = l;
						y = m;
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					printf("[컴퓨터 차례](x, y) 좌표: (%d, %d)\n", x, y);
					flag = 0;
					break;
				}
			}
		}
		else {
			printf("[플레이어 차례](x, y) 좌표: ");
			scanf("%d %d", &x, &y);
		}
		if (board[x][y] != ' ') {
			printf("위치를 다시 입력하세요\n");
			k--;
		}
		else
			board[x][y] = (k % 2 == 0) ? 'X' : 'O';	// 현재의 순번에 따라 'X', 'O'중 선택

												// 보드를 화면에 그린다. 
		for (i = 0; i < 3; i++) {
			printf("---|---|---\n");
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		}
		printf("---|---|---\n");
	}

	return 0;
}