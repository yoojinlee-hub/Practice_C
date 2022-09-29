#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int makeMulti(int* arr, int size) {
	int i, mult = 1;
	for (i = 0; i < size; i++)
		mult *= arr[i];
	return mult;
}
int main(void) {
	int N, max = -100000, plusNum=0;
	int* arr;
	int i, j;

	scanf("%d", &N);
	
	arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < N; i++) {
		 arr[i] = arr[i] + 1;
		 plusNum = makeMulti(arr, N);
		if (plusNum >= max)
			max = plusNum;
		arr[i] -= 1;
	}

	free(arr);
	printf("%d", max);
}