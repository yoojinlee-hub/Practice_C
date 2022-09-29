#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

void readMatrix(int** a, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}
void matrixMulti(int** a, int** b, int** x, int r1, int c1, int r2, int c2) {
	int i, j, k;
	for (i = 0; i < r1; i++)
		for (j = 0; j < c2; j++) {
			x[i][j] = 0;
			for (k = 0; k < c1; k++)
				x[i][j] += a[i][k] * b[k][j];
		}

}
void moveMatrix(int** a, int** b, int r, int c) {
	int i, j;
	for (i = 0; i < c; i++)
		for (j = 0; j < r; j++)
			b[i][j] = a[j][i];
}
void printMatrix(int** a,int r,int c) {
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("\t%d ", a[i][j]);
		printf("\n");
	}

}
int main(void) {
	int** a, ** b, ** x, ** y;
	int r, c, i;
	int r2, c2;

	printf("Enter 행렬 A의 row,col 입력:");
	scanf("%d %d", &r, &c);
	printf("Enter 행렬 B의 row,col 입력(B의 행은 %d여야 함):", c);
	scanf("%d %d", &r2, &c2);
	//동적할당
	a = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++)
		a[i] = (int*)malloc(sizeof(int) * c);
	y = (int**)malloc(sizeof(int*) * c);
	for (i = 0; i < c; i++)
		y[i] = (int*)malloc(sizeof(int) * r);
	b = (int**)malloc(sizeof(int*) * r2);
	for (i = 0; i < r2; i++)
		b[i] = (int*)malloc(sizeof(int) * c2);
	x = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++)
		x[i] = (int*)malloc(sizeof(int) * c2);

	printf("<%d*%d>행렬 A입력:\n", r, c);
	readMatrix(a, r, c);
	printf("<%d*%d>행렬 B입력:\n", r2, c2);
	readMatrix(b, r2, c2);

	matrixMulti(a, b, x, r, c, r2, c2);
	
	printf("행렬곱\n");
	printMatrix(x, r, c2);
	printf("전치행렬\n");
	moveMatrix(a, y, r, c);
	printMatrix(y, c, r);

	for (i = 0; i < r; i++)
		free(a[i]);
	free(a);
	for (i = 0; i < r; i++)
		free(b[i]);
	free(b);
	for (i = 0; i < r; i++)
		free(x[i]);
	free(x);
}