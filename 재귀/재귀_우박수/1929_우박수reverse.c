#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ubakNum(int n) {
	if (n == 1) {
		printf("1\n");
		return;
	}
	else if (n % 2 != 0)
		ubakNum(3 * n + 1);

	else 
		ubakNum(n / 2);
	printf("%d\n", n);
}
int main(void) {
	int n;
	scanf("%d", &n);

	ubakNum(n);
}