// header.c
#include "header.h"


void LoadMaze(char num)
{
    char path[20] = "./Maze";
    strcat(path, &num);
    strcat(path, ".txt");

    char str_tmp[50] = { 0, };
    FILE* f = fopen(path, "r");

    for (int i = 0; i < SIZE; i++)
    {
        fgets(str_tmp, 50, f);
        char* ptr = strtok(str_tmp, "\t");
        for (int j = 0; j < SIZE; j++)
        {
            maze[i][j] = *ptr;
            ptr = strtok(NULL, "\t");
        }
    }
    fclose(f);
}

void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void PrintMazeGame()
{

    for (int i = 0; i < SIZE; i++)
    {
        GotoXY(XP, YP + i);
        for (int j = 0; j < SIZE; j++)
        {
            if (maze[i][j] == '1')
                printf("■");
            else if (maze[i][j] == 'y')
                printf("★");
            else if (maze[i][j] == '0')
                printf("□");
            else
                printf("●");
        }
        puts("");
    }
}

void CursorView(char show)
{
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void MoveMaze(int* row, int* col)
{
    int nkey;


    if (_kbhit())
    {
        nkey = _getch();

        if (nkey == 224)
        {
            nkey = _getch();
            switch (nkey)
            {
            case UP:
                if (!(IsBlock(*row - 1, *col)))
                {
                    maze[*row][*col] = '0';
                    maze[*row - 1][*col] = 'x';
                    *row -= 1;
                }
                else if (IsFinish(*row - 1, *col))
                {
                    exit(0);
                }
                break;

            case DOWN:
                if (!(IsBlock(*row + 1, *col)))
                {
                    maze[*row][*col] = '0';
                    maze[*row + 1][*col] = 'x';
                    *row += 1;
                }
                else if (IsFinish(*row + 1, *col))
                {
                    exit(0);
                }
                break;

            case LEFT:
                if (!(IsBlock(*row, *col - 1)))
                {
                    maze[*row][*col] = '0';
                    maze[*row][*col - 1] = 'x';
                    *col -= 1;
                }
                else if (IsFinish(*row, *col - 1))
                {
                    exit(0);
                }
                break;

            case RIGHT:
                if (!(IsBlock(*row, *col + 1)))
                {
                    maze[*row][*col] = '0';
                    maze[*row][*col + 1] = 'x';
                    *col += 1;
                }
                else if (IsFinish(*row, *col + 1))
                {
                    exit(0);
                }
                break;
            }
        }
    }
}

int IsBlock(int i, int j)
{

    if (maze[i][j] == '1' || maze[i][j] == 'y')
        return 1;
    else
        return 0;
}

int IsFinish(int i, int j)
{

    if (maze[i][j] == 'y')
        return 1;
    else
        return 0;
}
/*
void MoveMaze(현재 플레이어의 위치좌표 (x), (y) 포인터 )
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
                if (위쪽이 막히지 않았다면)
                                {
                                    미로의 *(x), *(y)를 길로 변경;
                                    미로의 *(x), *(y)-1을 플레이어로 변경;
                                  *(y)를 *(y)-1 로 변경
                                }
                                else if (위쪽이 도착지라면)
                                {
                                    미로의 *(x), *(y)를 길로 변경;
                                    미로의 *(x), *(y)-1을 플레이어로 변경;
                                    프로그램 종료;
                                }
                break;

            case DOWN:
                if (아래쪽이 막히지 않았다면)
                                {
                                    미로의 *(x), *(y)를 길로 변경;
                                    미로의 *(x), *(y)+1을 플레이어로 변경;
                                  *(y)를 *(y)+1 로 변경
                                }
                                else if (아래쪽이 도착지라면)
                                {
                                    미로의 *(x), *(y)를 길로 변경;
                                    미로의 *(x), *(y)-1을 플레이어로 변경;
                                    프로그램 종료;
                                }
                break;

            case LEFT:
                                if (왼쪽이 막히지 않았다면)
                                {
                                    미로의 *(x), *(y)를 길로 변경;
                                    미로의 *(x)-1, *(y)을 플레이어로 변경;
                                  *(x)를 *(x)-1 로 변경
                                }
                                else if (왼쪽이 도착지라면)
                                {
                                    미로의 *(x), *(y)를 길로 변경;
                                    미로의 *(x), *(y)-1을 플레이어로 변경;
                                    프로그램 종료;
                                }
                break;

            case RIGHT:
                if (오른쪽이 막히지 않았다면)
                                {
                                    미로의 *(x), *(y)를 길로 변경;
                                    미로의 *(x)+1, *(y)을 플레이어로 변경;
                                  *(x)를 *(x)+1 로 변경
                                }
                                else if (오른쪽이 도착지라면)
                                {
                                    미로의 *(x), *(y)를 길로 변경;
                                    미로의 *(x), *(y)-1을 플레이어로 변경;
                                    프로그램 종료;
                                }
                break;
            }
        }

    }

}*/