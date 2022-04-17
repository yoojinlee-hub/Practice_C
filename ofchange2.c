//20191770¿Ã¿Ø¡¯
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int money) {
    int i, lastIndex, smallest, item;
    int sum = 0;
    int cnt = 0;

    /*if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            sum += items[bucket[i]];
        if (sum == money)
            return 1;
        if (sum > money)
            return 0;
    }*/

    lastIndex = bucketSize - k - 1;
   
    for (i = 0; i < lastIndex + 1; i++)
        sum += items[bucket[i]];
        
    if (sum == money)
        return 1;
    if (sum > money)
        return 0;

    if (bucketSize == k)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (item = smallest; item < itemSize; item++) {
        bucket[lastIndex + 1] = item;
        cnt += pick(items, itemSize, bucket, bucketSize, k - 1, money);
    }
    return cnt;
}

int main(void) {
	int bill[5] = { 10,50,100,500 };
	int* bucket;
	int money, n, i;

	scanf("%d", &money);
	n = money / 10;

	bucket = (int*)malloc(sizeof(int) * n);
	
	printf("%d", pick(bill, 4, bucket, n, n, money));
}