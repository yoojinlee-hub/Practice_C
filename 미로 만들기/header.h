// header.h
#ifndef HEADER
#define HEADER

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define SIZE 19


void LoadMaze(char num);
void GotoXY(int x, int y);
char maze[SIZE][SIZE];

#endif