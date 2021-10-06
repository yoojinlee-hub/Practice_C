/*****************
* HW(지뢰찾기) 이유진 20191770 컴퓨터학과 3학년
*********************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define X_VALUE 5 //2차원 배열의 행의 수
#define Y_VALUE 5 //2차원 배열의 열의 수

void readBombInfo(char grid[][Y_VALUE + 1])
{
	int i;
	// grid 및 지뢰 정보 입력
	//printf("Input Grid\n");
	for (i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]); // 문자열 형식으로 읽음!
}
void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*') {
				//여기에 지뢰의 개수를 세어 numOfBombs에 넣는 코드 작성
				//나를 감싸고 있는 자리에 지뢰의 수 증가
				for (int y = i - 1; y <= i + 1; y++) {
					for (int x = j - 1; x <= j + 1; x++) {
						if (i - 1 < 0 || j - 1 < 0 || i + 1 > Y_VALUE || j + 1 > Y_VALUE)
							continue;
						
							numOfBombs[y][x] += 1;
					}
				}
			}
}
void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}
int main(void)
{
	char grid[X_VALUE][Y_VALUE + 1]; //문자열의 경우 마지막에 NULL이 들어가야 하므로
									// 5X5 배열이 아닌 5X6 배열이 되어야 한다.
	int numOfBombs[X_VALUE][Y_VALUE] = { 0 }; //지뢰의 개수를 넣는 정수형 5X5 배열
	
	readBombInfo(grid);

	countBomb(grid, numOfBombs);

	display_numOfBombs(grid, numOfBombs);
}