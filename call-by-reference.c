
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void add_two(int x, int y, int* s) {
	*s = x + y;
}
void main() {
	int a = 20, b = 30;
	int sum = 0;

	add_two(a, b, &sum);
	printf("a = %d b = %d sum = %d\n", a, b, sum);
}