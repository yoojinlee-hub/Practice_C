#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanArr(int arr[][4],int size) {
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", &arr[i][j]);
}
void printArr(int arr[][4], int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < 4; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
void change(int arr[][4], int change[][4], int size) {
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < 4; j++)
			change[i][j] = arr[j][i];
}
int main(void) {
	int arr[4][4];
	int changeArr[4][4];

	scanArr(arr,4);
	change(arr, changeArr, 4);

	printf("\n[변경 전]\n");
	printArr(arr, 4);
	printf("\n[변경 후]\n");
	printArr(changeArr, 4);
}