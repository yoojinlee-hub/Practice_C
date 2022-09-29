#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//중복순열
void pick(int* items, int itemSize, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, item;
	int answer = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			if (items[bucket[i]] == 1) {
				printf("+%d",  i + 1);
				answer += -(i + 1);
			}
			else {
				printf("-%d", i + 1);
				answer += i + 1;
			}
		}

		printf("=%d\n", answer);
		return;
	}
	wg
	lastIndex = bucketSize - k - 1;

	smallest = 0;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}
int main(void) {
	int arr[2] = { 1,-1 };
	int* bucket;
	int n;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);

	pick(arr, sizeof(arr) / sizeof(int), bucket, n, n);
}