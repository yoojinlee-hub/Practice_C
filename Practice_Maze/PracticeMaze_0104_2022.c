#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define XP 40
#define YP 5

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
int main(void) {
    int i = 0;
    int operator=1;
    CursorView(0);

    while (1) {
        if (i == 0) operator=1;
        if (i == 20) operator=-1;
            
        if (operator==1) GotoXY(XP, i++);
        if (operator==-1)GotoXY(XP, i--);

        printf("ㅁ");

        Sleep(100);
        system("cls"); //콘솔화면 지우기
    }
}
