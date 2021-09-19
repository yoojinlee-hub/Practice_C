#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int win(char board[][3],int rowSize) {
    //(2)게임종료 검사 
    int i, j;
    int cnt = 0;
    //가로 검사
    i = 0;
    while(i<3) {
        cnt = 0;
        for (j = 0; j < 2; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                if (board[i][j] == board[i][j + 1])
                    cnt++;
                if (cnt >= 2)
                    return 1;
            }
        }
        i++;
    }
    //세로검사 - j가 끝도 없이 늘어남(두번째 반복문에서)
    for (j = 0; j < 3; i++) {
        cnt = 0;
        for (i = 0; i < 2; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                if (board[i][j] == board[i + 1][j])
                    cnt++;
                if (cnt >= 2)
                    return 1;
                if (j > 3)
                    break;
            }
        }
    }
    //대각선 검사
    if (board[0][0] != ' ' || board[1][1] == ' ' || board[2][2] != ' ') {
        if (board[0][0] == board[1][1])
            if (board[0][0] == board[2][2])
                return 1;
    }
    if (board[0][2] != ' ' || board[1][1] == ' ' || board[2][0] != ' ') {
        if (board[0][2] == board[1][1])
            if (board[0][2] == board[2][0])
                return 1;
    }

    //기본
    return 0;
}
int main(void)
{
    char board[3][3];
    int x, y, k, i, j;

    for (x = 0; x < 3; x++)
        for (y = 0; y < 3; y++) board[x][y] = ' ';

    for (k = 0; k < 9; k++) {
        //board[x][y] = (k % 2 == 0) ? 'X' : 'O'; //돌아가면서 나오도록
                                               //컴퓨터가 O - 나머지가 1일 때
        if (k % 2 == 0) {
            printf("(x,y) 좌표(x,y<3):");
            scanf("%d%d", &x, &y);

            //(1)상대방이 놓은 곳에 다시 놓을 수 없도록 하는 코드
            if (board[x][y] == 'X' || board[x][y] == 'O') {
                printf("이미 놓은 자리입니다!\n");
                continue;
            }  
            else 
                board[x][y] == 'O';
            
        }
        //(3)컴퓨터가 자동으로 다음 수 결정하는 알고리즘-비어있는 첫번째 좌표에 넣기
        if (k % 2 == 1) {
            for(i=0;i<3;i++)
                for (j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] == 'O';
                        break;
                    }
                }
        }

        if (k > 0) {
            if (win(board, 3)) {
                printf("게임이 끝났습니다");
                break;
            }
        }

        for (i = 0; i < 3; i++) {
            printf("---l---l---\n");
            printf(" %c l %c l %c \n", board[i][0], board[i][1], board[i][2]);
        }
        printf("---l---l---\n");

    }
    if (k == 9) {
        printf("무승부로 게임이 끝났습니다\n");
    }
    return 0;
}