#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, i;
	int count = 0;

	scanf("%d", &n);

	while (n > 0) {
		if (n >= 5) {
			n -= 5;
			count += 1;
		}
		else if (n >= 3) {
			n -= 3;
			count += 1;
		}
		else if (n < 3) {
			count = -1;
			break;
		}
	}
	printf("%d", count);
}