//20191770이유진 //수정후
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int money) {
	int i, lastIndex, smallest, item;
	int sum = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			sum += items[bucket[i]];
		if (sum == money) {
			for (i = 0; i < bucketSize; i++)
				if (bucket[i] > 0) 
					printf("%d ", items[bucket[i]]);
			
			printf("\n");
		}
		return;
	}

	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; // 중복 조합

	for (i = smallest; i < itemsize; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, itemsize, bucket, bucketSize, k - 1, money);
	}
	return;

}
int main(void)
{
	int items[] = { 0, 1000, 5000, 10000 };
	int* bucket;
	int money, n;

	scanf("%d", &money);
	n = money / 1000;
	bucket = (int*)malloc(sizeof(int) * n);

	pick(items, 4, bucket, n, n, money);
}