//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quickSort(int A[], int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int partition(int A[], int p, int r)
{
	// 배열 A[p..r]의 원소들을 A[r]을 기준으로
	// 양쪽으로 재배치하고
	// A[r]이 자리한 위치를 return한다.
	int  i = p - 1, j = p, temp;
	while (j <= r) {
		if (A[j] > A[r]) {
			j++;
		}
		else {
			temp = A[i + 1];
			A[i + 1] = A[j];
			A[j] = temp;
			i++; j++;
		}
	}
	return i;
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
	quickSort(arr, 0, n - 1);
	printArray(arr, n);

	free(arr);
}