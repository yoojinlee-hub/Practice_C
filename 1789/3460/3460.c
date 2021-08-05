#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int T, i, j, n, cnt;

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d", &n);
		cnt = 0;
		while (n != 0) {
			if (n % 2 != 0) //이진수 구하는 방법
				printf("%d ", cnt);
			n = n / 2;
			cnt++;
		}
		printf("\n");
	}
	return 0;
}