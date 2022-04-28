#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;
void pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int m) { //중복순열
	int i, lastIndex, smallest, item;
	int answer = 0, cnt = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			if (items[bucket[i]] == 1) {
				answer += -(i + 1);
				cnt += 1;
			}
			else {
				answer += i + 1;
				cnt += -1;
			}
		}

		if (cnt != bucketSize && cnt != -bucketSize && count == 0) {
			if (answer == m) {
				for (i = 0; i < bucketSize; i++)
					if (items[bucket[i]] == 1)
						printf("-%d", i + 1);
					else
						printf("+%d", i + 1);
				printf("=%d", answer);
				printf("\n");
				count = 1;
			}
		}
		return count;
	}

	lastIndex = bucketSize - k - 1;

	smallest = 0;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1, m);
	}
}
int main(void) {
	int arr[2] = { 1,-1 };
	int* bucket;
	int n = 0, m, print;

	scanf("%d",&m);

	while (count != 1) {
		n += 1;
		bucket = (int*)malloc(sizeof(int) * n);
		pick(arr, sizeof(arr) / sizeof(int), bucket, n, n, m);
	}

}