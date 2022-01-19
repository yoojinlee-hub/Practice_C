#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int findOdd(int a, int b) {
	if (b == a) {
		if (b % 2 != 0) printf("%d ", b);
		return;
	}
	else if (b % 2 != 0) {
		findOdd(a, b - 1);
		printf("%d ", b);
	}
	else
		findOdd(a, b - 1);
} 
int main(void) {
	int a, b;

	scanf("%d %d", &a, &b);
	findOdd(a, b);
	printf("\n");
}