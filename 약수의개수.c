#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int findMeasure(int n) {
	int i, count = 0;
	for (i = 1; i <= n; i++)
		if (n % i == 0)
			count++;
	if (count % 2 == 0)
		return 1;
	else
		return 0;
}
int main(void) {
	int a, b;
	int i;
	int count = 0;

	scanf("%d %d", &a, &b);

	for (i = a; i <= b; i++)
		count += findMeasure(i);

	printf("%d\n", count);
}