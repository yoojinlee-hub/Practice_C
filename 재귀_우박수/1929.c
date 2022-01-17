#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ubakNum(int n) {
	if (n == 1) return;
	else if (n % 2 != 0) {
		printf("%d\n", 3 * n + 1);
		return ubakNum(3 * n + 1);
	}
	else {
		printf("%d\n", n / 2);
		return ubakNum(n / 2);
	}	
}
int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	ubakNum(n);
}