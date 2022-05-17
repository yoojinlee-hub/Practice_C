#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int n, int* F) {

	if (n == 1 || n == 2) return 1;

	if (F[n - 1] == 0)
		F[n - 1] = fib(n - 1, F);
	if (F[n - 2] == 0)
		F[n - 2] = fib(n - 2, F);

	return F[n - 1] + F[n - 2];
}
int main(void) {
	int n, i;
	int* F; //memo

	printf("몇 번째 까지의 피보나치 수열:");
	scanf("%d", &n);//fn

	//memo 초기화
	F = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++)
		F[i] = 0;
	fib(n + 1, F);

	for (i = 1; F[i] > 0; i++)
		printf("%d ", F[i]);
	free(F);
}