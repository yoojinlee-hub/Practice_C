
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int* arr, int size) {
	int max_idx, max;
	int i, j;
	int temp;
	for (i = 0; i < size - 1; i++) {
		max = arr[0]; max_idx = 0;
		for (j = 1; j < size - i; j++) {
			if (max < arr[j]) {
				max = arr[j];
				max_idx = j;
			}
		}
		temp = arr[size - 1 - i];
		arr[size - 1 - i] = arr[max_idx];
		arr[max_idx] = temp;
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
}