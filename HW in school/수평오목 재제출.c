/***********
HW(수평오목재제출) 20191770 이유진 컴퓨터학과 3학년
************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 10

void display(char b[][BOARD_SIZE])
{
    char ch;
    int i, j;
    printf("     ");
    for (i = 0; i < BOARD_SIZE; i++)
        printf("%2d", i);
    printf("\n     ---------------------\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%3d |", i);
        for (j = 0; j < BOARD_SIZE; j++)
            printf(" %c", b[i][j]);
        printf("\n");
    }
}

int winCheck(char b[][BOARD_SIZE], int r, int c)
{
    int i, cnt1 = 1, cnt2 = 1;
    char player = b[r][c];
    
    for (i = c - 1; i >= 0; i--)//현재 나의 기준 왼쪽
        if (b[r][i] != player)
            break;
        else //어디에 걸리는 else? {}없어도 되나??
            cnt1++;
    for (i = c + 1; i < BOARD_SIZE; i++) //현재 나의 기준 오른쪽
        if (b[r][i] != player)
            break;
        else
            cnt1++;
    if (cnt1 == 5)
        return 1;
    
    for (i = r - 1; i >= 0; i--)
        if (b[i][c] != player)
            break;
        else
            cnt2++;
    for (i = r + 1; i < BOARD_SIZE; i++)
        if (b[i][c] != player)
            break;
        else
            cnt2++;
    if (cnt2 == 5)
        return 1;
}

void main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
    int r, c;
    int i, j;
    int count;

    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            board[i][j] = ' ';

    count = 1;
    display(board);

    do
    {
        turn = 'X'; // 다시 초기화 필요

        if (count % 2 != 1)
            turn = 'O';

        printf("Player %c(행 열):", turn);
        scanf("%d %d", &r, &c);

        if (board[r][c] == ' ') {
            board[r][c] = turn;
            display(board);

            if (winCheck(board, r, c) == 1) {
                printf("Player %c wins!\n", turn);
                break;
            }

            count++;
        }
    } while (!winCheck(board, r, c)&&count <= BOARD_SIZE * BOARD_SIZE);

    if (!winCheck(board, r, c) && count <= BOARD_SIZE * BOARD_SIZE)
        printf("Nobody win\n");
}