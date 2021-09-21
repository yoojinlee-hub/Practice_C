/*****************
* LAB4_3 이유진 20191770 컴퓨터학과 2학년
*******************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n);
int main(void) {
	int n, idx;

	printf("몇개의 피보나치 수열값을 출력할까요?(3보다 큰 정수):");
	scanf("%d", &n);

	for (idx = 0; idx < n; idx++) {
		printf("%10d ", fibo(idx));
		if ((idx + 1) % 5 == 0) //한 줄에 5개씩 출력
			printf("\n");
	}
}

int fibo(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}