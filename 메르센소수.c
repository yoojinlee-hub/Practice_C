#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2의 n승을 반환하는 함수
long long twoToThePower(int n) {
	long long power=1, result;
	int i;

	for (i = 2; i <= n; i++)
		power = 2 * power;

	result = power - (long long)1;

	return result;
}
//x가 소수이면 1 아니면 0을 반환하는 함수
int isPrime(long long x) {
	int i, flag;

	for (i = 2; i < x; i++)
		if (x % i == 0)
			break;

	if (i == x)
		flag = 1;
	else
		flag = 0;

	return flag;
}

int main(void) {
	int num, j;

	printf("Enter a number: ");
	scanf("%d", &num);

	for (j = 1; j <= num; j++) {
		if (isPrime(twoToThePower(j)) == 1) {
			printf("(2^%d - 1) = %lld", j-1, twoToThePower(j));
			printf("은 메르센 소수이다.\n");
		}
	}
}