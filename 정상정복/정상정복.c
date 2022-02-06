#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int A, B, N;
	int oneday = 0, total = 0;

	scanf("%d %d %d", &A, &B, &N);

	oneday = A - B;

	if (oneday < 0) printf("-1\n");
	else {
		while (N > 0) {
			N -= A;total++;
			if (N == 0) break;
			N += B;
		}
		printf("%d\n", total);
	}
}