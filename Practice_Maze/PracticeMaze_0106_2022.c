#define _CRT_SECURE_NO_WARNINGS
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int XP = 40;
int YP = 5;

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
void MoveSquare()
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
                YP--;
                break;

            case DOWN:
                YP++;
                break;

            case LEFT:
                XP--;
                break;

            case RIGHT:
                XP++;
                break;
            }
        }
    }
}
int IsFinish(int x, int y) {
    if (x == 60)
        return 1;
    else
        return 0;
}
int main(void) {
    CursorView(0);
    int finish = 0;
    while (1) {
        //선긋기 
        int i = 0; 
        while (i < 30) { //i가 30이 넘는 순간부터 깜박거림
            GotoXY(60, i++);
            printf("|");
        }

        GotoXY(XP, YP);
        printf("0");
        if (_kbhit()) {
            if (IsFinish(XP, YP) == 1) {
                printf("|");
                finish = 1;
                break;
            }
            else
                MoveSquare();
            system("cls");
        }
    }
    if (finish) {
        system("cls");
        printf("선에 닿아 프로그램을 끝냅니다.");
    }
}