#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int count = 0;
//중복조합
void pick(char* items, int itemSize, int* bucket, int bucketSize, int k, int goal) {
	int i, lastIndex, smallest, item;
	int answer = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			if (items[bucket[i]] == 1)
				answer += 1;
			else
				answer += 2;
		}

		if (answer == goal) count++;
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1, goal);
	}
}
int main(void) {
	int arr[2] = { 1,2 };
	int* bucket;
	int n;

	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		bucket = (int*)malloc(sizeof(int) * i);
		pick(arr, sizeof(arr) / sizeof(int), bucket, i, i, n);
	}
	printf("%d", count);
}