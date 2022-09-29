//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int* arr, int size) {
	int i, j, k;
	int temp = 0;
	for (i = 1; i < size ; i++) {
		for (j = 0; j < i; j++) 
			if (arr[j] > arr[i]) break;

		temp = arr[i];
		for (k = i - 1; k >= 0; k--) 
			if (arr[k] > temp) arr[k + 1] = arr[k];
		arr[j] = temp;
	}
}
void initArray(int* arr, int size) {
	int i;
	for (i = 0; i < size; i++)
		arr[i] = rand() % 999;
}
void printArray(int* arr, int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}
int main(void) {
	int n;
	srand(time(NULL));

	printf("Enter a number:");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	initArray(arr, n);
	printArray(arr, n);

	printf("\n정렬된 후:\n");
	selectionSort(arr, n);
	printArray(arr, n);

	free(arr);
}