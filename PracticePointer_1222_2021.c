#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void findMax(int arr[5], int** p, int size) {
	int i;
	int* m; 
	m = &arr[0];
	for (i = 0; i < size; i++) 
		if (*m <= arr[i])
			m = &arr[i];
	*p = m;
}
int main(void) {
	int arr[5];
	int* max;
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	
	//이중포인터를 이용해서 최대값 찾기
	findMax(arr, &max, 5);
	printf("최대값 : %d\n", *max);

	return 0;
}