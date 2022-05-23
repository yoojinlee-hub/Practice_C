#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int min = 10000;
void pick(int* items, int itemSize, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, item;
	int sum, sum2, sub;
	int* isin;

	if (k == 0) {
		isin = (int*)malloc(sizeof(int) * itemSize);
		for (i = 0; i < itemSize; i++)		//매번 초기화 해 줘야 함
			isin[i] = 0;

		sum = 0; sum2 = 0;
		for (i = 0; i < bucketSize; i++) {
			isin[bucket[i]] = 1;
			sum += items[bucket[i]];
		}
		//printf("%d\n", sum)
		for (i = 0; i < itemSize; i++) 
			if (isin[i] == 0) 
				sum2 += items[i];	
		
		//printf("%d\n", sum2);
		sub = (sum < sum2 ? sum2 : sum) - (sum < sum2 ? sum : sum2);
		if (min >= sub)
			min = sub;
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
	int* arr;
	int* bucket;
	int num = 0, i;

	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int) * num);
	for (i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	bucket = (int*)malloc(sizeof(int) * 3);

	pick(arr, num, bucket, 3, 3);

	printf("%d\n", min);
}