//20191770¿Ã¿Ø¡¯
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(char* items, int itemSize, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, item;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c", items[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}
int main(void) {
	char arr[7] = { 'A','B','C','D','E','F','G' };
	int bucket[3];
	pick(arr, sizeof(arr) / sizeof(char), bucket, 3, 3);
}
