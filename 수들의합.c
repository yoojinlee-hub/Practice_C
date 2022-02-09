#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, M;
	int arr[100] = { 0 };
	int i, j;
	int sum = 0, count = 0;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", &arr[i]);

	for (i = 0; i < N; i++) {
		sum = arr[i];
		if (sum == M) count++;
		for (j = i + 1; j < N; j++) {
			sum += arr[j];
			if (sum == M) count++;
		}
	}
	printf("%d", count);
}