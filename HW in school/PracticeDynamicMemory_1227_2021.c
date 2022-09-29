#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free 함수가 선언된 헤더 파일

int main(void) {
	int n;
	int i, sum = 0;
	
	printf("학생의 수:");
	scanf("%d", &n);
	printf("\n");

	//(int크기*입력받은 크기)만큼 동적 메모리 할당
	int* size = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		printf("학생%d :", i+1);
		scanf("%d", &size[i]);
		sum += (int)size[i];
	}
	printf("\n");
	printf("평균: %f\n", (double)(sum / n));

	free(size); //동적으로 할당한 메모리 해제
}