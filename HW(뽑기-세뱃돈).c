//20191770¿Ã¿Ø¡¯
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int k,int money) {
	int i, lastIndex, smallest, item;
	int sum = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) 
			sum += items[bucket[i]];
		if (sum == money) {
			for (i = 0; i < bucketSize; i++)
				printf("%d ", items[bucket[i]]);
			printf("\n");
		}
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1, money);
	}

}
int main(void) {
	int bill[3] = { 10000,5000,1000 };
	int* bucket;
	int money, n, i;

	scanf("%d", &money);
	n = money / bill[2];

	for (i = n; i > 0; i--) {
		bucket = (int*)malloc(sizeof(int) * i);
		pick(bill, sizeof(bill) / sizeof(int), bucket, i, i, money);
	}
}
		