#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#define LE 1
#define UP 2

int matrixPath_memo(int** m, int r, int c, int i, int j, int** M, int** BP)
{
	if (i == 0 && j == 0)
		return m[0][0];
	else if (i == 0) {
		if (M[0][j - 1] == 0)
			M[0][j - 1] = matrixPath_memo(m, r, c, 0, j - 1, M, BP);
		BP[i][j] = LE;
		
		return M[0][j - 1] + m[i][j];
	}
	else if (j == 0) {
		if (M[i - 1][0] == 0)
			M[i - 1][0] = matrixPath_memo(m, r, c, i - 1, 0, M, BP);
		BP[i][j] = UP;
		
		return M[i - 1][0] + m[i][j];
	}
	else {
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath_memo(m, r, c, i, j - 1, M, BP);
		if (M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath_memo(m, r, c, i - 1, j, M, BP);
		
		if (M[i - 1][j] < M[i][j - 1]){
			BP[i][j] = UP;
			return M[i - 1][j] + m[i][j];
		}
		else {
			BP[i][j] = LE;
			return  M[i][j - 1] + m[i][j];
		}
	}
}
void printPath(int i, int j, int** BP) {
	if (i == 0 && j == 0) {
		printf("<%d %d>", i, j);
		return;
	}
	if (BP[i][j] == 2)
		printPath(i - 1, j, BP);
	else
		printPath(i , j- 1, BP);
	printf("<%d %d>", i, j);
}
int main(void)
{
	int** m, ** M, ** BP; // M은 메모
	int i, j, r, c;
	r = c = 4; // 4x4 matrix
	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	BP = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
		BP[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0; //메모 초기화
			BP[i][j] = 0;
		}
	printf("%d\n", matrixPath_memo(m, r, c, 3, 3, M, BP));
	printf("\n");
	// 메모 M 출력

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
	printf("\n");
	// backpointer BP 출력
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d ", BP[i][j]);
		printf("\n");
	}
	printPath(r - 1, c - 1, BP);
	printf("\n");
	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
		free(BP[i]);
	}
	free(m);
	free(M);
	free(BP);
}