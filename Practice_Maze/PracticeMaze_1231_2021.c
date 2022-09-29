#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int main(void) {
    int num;
    int i;

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        GotoXY(i*2, i);
        printf("¤¡");
        printf("\n");
    }
    

    return 0;
}