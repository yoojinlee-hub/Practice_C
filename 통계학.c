#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, count, newNum;
	int max = 0, min = 100, range = 0;
	int sum = 0, middle = 0;

	scanf("%d", &n);
	count = n;

	while (count) {
		scanf("%d", &newNum);

		if (max <= newNum) max = newNum;
		if (min >= newNum) min = newNum;

		sum += newNum;

		if (n / 2 == count) middle = newNum;
		count--;
	}
	range = max - min;

	printf("»ê¼úÆò±Õ :%d\n", sum / n);
	printf("Áß¾Ó°ª : %d\n", middle);
	printf("¹üÀ§ : %d\n", range);
}