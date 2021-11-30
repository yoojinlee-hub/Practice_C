/***********
오목완성 20191770 이유진 컴퓨터학과 3학년
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
    int i;
    char player = b[r][c];
    int cnt = 0;

    //가로체크
    for (i = c - 1; i < BOARD_SIZE; i++)//왼쪽
        if (b[r][i] != player)
            break;
        else
            cnt++;
    for (i = c + 1; i < BOARD_SIZE; i++)//오른쪽
        if (b[r][i] != player)
            break;
        else
            cnt++;
    if (cnt == 5)
        return 1;
    //세로체크
    cnt = 0;
    for (i = r - 1; i < BOARD_SIZE; i++)//위
        if (b[i][c] != player)
            break;
        else
            cnt++;
    for (i = r + 1; i < BOARD_SIZE; i++)//아래
        if (b[i][c] != player)
            break;
        else
            cnt++;
    if (cnt == 5)
        return 1;
    // \ 대각선 체크
    cnt = 0;
    for (i = 0; i < BOARD_SIZE; i++)//위
        if (b[r-i][c-i] != player)
            break;
        else
            cnt++;
    for (i = 0; i < BOARD_SIZE; i++)//아래
        if (b[r+i][c+i] != player)
            break;
        else
            cnt++;
    if (cnt == 6)
        return 1;
    // / 대각선 체크
    cnt = 0;
    for (i = 0; i < BOARD_SIZE; i++)//위
        if (b[r - i][c + i] != player)
            break;
        else
            cnt++;
    for (i = 0; i < BOARD_SIZE; i++)//아래
        if (b[r + i][c - i] != player)
            break;
        else
            cnt++;
    if (cnt == 6)
        return 1;
    return 0; // i이기지 않았을 때
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
    } while (count <= BOARD_SIZE * BOARD_SIZE);
}