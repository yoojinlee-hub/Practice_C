/****************
20191770 이유진 컴퓨터학과 3학년 //////어렵다!!!!!!!!
****************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printFibo(int n);

int main(void) {
	int num, i;
	
	printf("몇개의 피보나치 수열값을 출력할까요?(3보다 큰 정수):");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
		printFibo(i);

	printf("\n");
	return 0;
}
void printFibo(int n)//(n+1)번째 값을 출력
{
	int f1=1,f2=1,f3,i;

	if (n < 2)
		printf("1 ");
	else if (n == 2)
		printf("2 ");
	else {
		for (i = 2; i <= n; i++) {
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		printf("%d ", f3);
	}

	return;
}