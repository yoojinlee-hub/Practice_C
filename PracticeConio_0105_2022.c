#define _CRT_SECURE_NO_WARNINGS
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224


#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorView(char show) //커서없애기
{
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = show; //커서의 노출여부
    ConsoleCursor.dwSize = 1; //커서의 두께
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}
int MoveMaze(int x,int y)
{
    int nkey;

    if (_kbhit())
    {
        nkey = _getch();

        if (nkey == ARROW)
        {
            nkey = _getch();
            switch (nkey)
            {
            case UP:
                GotoXY(x, y - 1);
                return UP;
                break;

            case DOWN:
                GotoXY(x, y + 1);
                return DOWN;
                break;

            case LEFT:
                GotoXY(x - 1, y);
                return LEFT;
                break;

            case RIGHT:
                GotoXY(x + 1, y);
                return RIGHT;
                break;
            }
        }

    }
    return 0;
}
int main(void) {
    int whereIs = 0;
    int XP = 10, YP = 10;
    int i = 0;
    CursorView(0);

    while (1) {
        if (i == 0)
            GotoXY(XP, YP);
        whereIs = MoveMaze(XP, YP);

        if (whereIs == UP) YP--;
        else if (whereIs == DOWN) YP++;
        else if (whereIs == LEFT) XP--;
        else if (whereIs == RIGHT) XP++;
        printf("ㅁ");

        Sleep(100);
        system("cls");
    }
}
/*
int main(void)
{

    int nkey;
    while (1)
    {
        if (_kbhit())
        {
            nkey = _getch();
            printf("%d\n", nkey);
        }
    }
}
// 실행결과 : 입력한 키의 아스키 코드 값
//아스키 코드 값은 2바이트 크기를 가지는 확장키
//_getch함수를 두번 호출하면 된다
*/