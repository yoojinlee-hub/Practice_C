#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initTable(int table[][5], int rowSize) {
	int i, j;

	for (i = 0; i < rowSize; i++) 
		for (j = 0; j < 5; j++)
			table[i][j] = rand() % 100;
	
}
int totalTable(int table[][5], int rowSize) {
	int total = 0;
	int i, j;

	for (i = 0; i < rowSize; i++)
		for (j = 0; j < 5; j++)
			total += table[i][j];

	return total;
}
void printTable(int table[][5], int rowSize) {
	int i, j;

	for (i = 0; i < rowSize; i++) {
		for (j = 0; j < 5; j++) {
			if (j == 0)
				printf("%5d", table[i][j]);
			else
				printf("%5d", table[i][j]);
		}
		printf("\n");
	}
}
int main(void) {
	int table[3][5];
	int i, j;
	int total = 0;

	srand(time(NULL));

	initTable(table, 3);
	printf("발생된 난수의 평균은 %d입니다\n", totalTable(table, 3) / 15);

	printTable(table, 3);

	printf("----각 열의 합----\n");
	for (j = 0; j < 5; j++) {
		total = 0;
		for (i = 0; i < 3; i++)
			total += table[i][j];
		printf("%5d", total);
	}
	printf("\n");
	
	return 0;
}