#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 0;
long long factorial(long long n) {
	if (n == 1) return 1;
	else return n * factorial(n - 1);
}
int main(void) {
	int n;
	long long f = 0;

	scanf("%d", &n);

	f = factorial(n);
	while (f > 0) {
		if (f % 10 == 0) count++;
		f /= 10;
	}
	printf("%d", count);
}