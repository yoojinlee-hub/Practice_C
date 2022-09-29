#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a[1000], b[1000];
	int i, aIndex = 0, bIndex = 0;
	int n, mother = 1, son = 1;
	int sum = 0;

	scanf("%d", &n);

	while (n >= aIndex) {
		for (i = 0; i <= sum; i++) {
			if (sum % 2 == 0) {
				a[aIndex++] = son + sum - i;
				b[bIndex++] = mother + i;
			}
			else {
				b[bIndex++] = son + sum - i;
				a[aIndex++] = mother + i;
			}
		}
		sum++;
	}
	if (n > 1)
		printf("%d/%d", a[n - 1], b[n - 1]);
	else
		printf("1/1");
}