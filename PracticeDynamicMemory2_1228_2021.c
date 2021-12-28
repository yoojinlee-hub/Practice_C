#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free 함수가 선언된 헤더 파일

int findPrime(int num) {
	int i;
	for (i = 2; i < num; i++) 
		if (num % i == 0)
			break;
	if (i == num) //소수이다
		return 1;
	else         //소수가 아니다
		return 0;
	
}
int main(void) {
	int num, i, j;
	int find = 0;

	printf("숫자의 개수 : ");
	scanf("%d", &num);

	int* arr = (int*)malloc(sizeof(int) * num);
	int count = 0;

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
		//소수의 개수 세기
		if (findPrime(arr[i]) == 1)
			count++;
	}

	free(arr);

	printf("소수의 개수는 %d입니다.\n", count);

	return 0;
}