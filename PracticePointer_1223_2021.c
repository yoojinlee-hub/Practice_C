#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputArr(int arr[][3],int size) {
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);
}
void printArr(int arr[][3], int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < 3; j++)
			printf("\t%d", arr[i][j]);
		printf("\n");
	}
}
void multiplyArr(int A[][3], int B[][3], int C[][3], int size) {
	int i, j, k;

	for(i=0;i<size;i++)
		for (j = 0; j < 3; j++) {
			C[i][j] = 0;
			for (k = 0; k < 3; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
}
int main(void) {
	int A[3][3];
	int B[3][3];
	int C[3][3];

	int* p = A;
	int** pp = &p;

	printf("[행렬 A]"); printf("\n");
	inputArr(A, 3);
	printf("[행렬 B]"); printf("\n");
	inputArr(B, 3);

	printf("\n");
	printf("[행렬 A]"); printf("\n");
	printArr(A, 3);

	printf("\n");
	printf("[행렬 B]"); printf("\n");
	printArr(B, 3);

	multiplyArr(A, B, C, 3);
	printf("\n");
	printf("[행렬 곱]"); printf("\n");
	printArr(C, 3);
}