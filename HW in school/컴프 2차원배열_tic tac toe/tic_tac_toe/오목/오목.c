/*https://devyul.tistory.com/entry/C-3X3-%EA%B2%8C%EC%9E%84%ED%8C%90%EC%9D%98-Tic-Tac-Toe*/
#include <stdio.h>
#define WIDTH 3
#define HEIGHT 3

int winCheck(int sum)
{
	if (sum == 3)
	{
		printf("Player X wins!\n");
		return 1;
	}
	else if (sum == -3)
	{
		printf("Player O wins!\n");
		return 1;
	}

	return 0; //아무도 안이김
}

int win(int b[][HEIGHT])
{
	int i, j;
	int sum;
	// 가로로 세개씩 체크
	for (i = 0; i < WIDTH; i++)
	{
		sum = 0; //각각 체크해야하므로 매번 초기화
		for (j = 0; j < HEIGHT; j++)
			sum += b[i][j];

		if (winCheck(sum)) return 1;
	}

	// 세로로 세개씩 체크
	for (j = 0; j < HEIGHT; j++)
	{
		sum = 0;
		for (i = 0; i < WIDTH; i++)
			sum += b[i][j];
		if (winCheck(sum)) return 1;
	}
	// 대각선 체크
	sum = 0;
	for (i = 0; i < WIDTH; i++)
	{
		sum += b[i][i];
	}
	if (winCheck(sum)) return 1;

	// 역대각선 체크
	sum = 0;
	for (i = 0; i < WIDTH; i++)
	{
		sum += b[i][WIDTH - 1 - i];
	}
	if (winCheck(sum)) return 1;

	return 0;
}

void display(int b[][HEIGHT])
{
	char ch;
	int i, j;

	printf("    0 1 2\n");
	printf("   ------\n");
	for (i = 0; i < WIDTH; i++)
	{
		printf("%d |", i);
		for (j = 0; j < HEIGHT; j++)
		{
			if (b[i][j] == 1)
				ch = 'X';
			else if (b[i][j] == -1)
				ch = 'O';
			else
				ch = ' ';
			printf(" %c", ch);
		}
		printf("\n");
	}
}

int main(void)
{
	int board[3][3];
	char turn = 'X'; //처음 turn을 X로 시작

	int r, c;
	int i, j;
	int count;
	int lose;

	for (i = 0; i < WIDTH; i++)
		for (j = 0; j < HEIGHT; j++)
			board[i][j] = 0;

	count = 0;
	display(board);

	do
	{
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &r, &c);
		printf("\n");

		if (board[r][c]) //이미 채워져있으면 다시 입력 프롬프트 실행
			continue;		//코드 이전부분으로 돌아감

		count++; //심볼이 입력된 횟수 증가

		if (turn == 'X') {

			board[r][c] = 1;
			turn = 'O'; //턴을 바꿔줌
		}
		else {
			board[r][c] = -1;
			turn = 'X';
		}
		display(board);

	} while ((lose = !win(board)) && count < 9); //count가 9 미만이면 3x3 판 기준으로 다 채워지지 않은 상태

	if (lose && count == 9)
		printf("Nobody wins!\n");
}