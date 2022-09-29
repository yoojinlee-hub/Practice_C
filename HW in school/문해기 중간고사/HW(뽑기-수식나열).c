#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//중복순열
void pick(char* items, int itemSize, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, item;
	int answer = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			printf("%c%d", items[bucket[i]], i + 1);
			if (items[bucket[i]] == '-')
				answer += -(i + 1);
			else
				answer += i + 1;
		}
			
		printf("=%d\n", answer);
		return;
	}

	lastIndex = bucketSize - k - 1;

	smallest = 0;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}
int main(void) {
	char arr[2] = { '+','-' };
	int* bucket;
	int n;
	
	scanf("%d", &n);
	bucket = (char*)malloc(sizeof(char) * n);

	pick(arr, sizeof(arr) / sizeof(char), bucket, n, n);
}