#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int sum = 0;
int isSequence(int* a, int size)
{
	// 코드 작성
	int i, temp = 0;
	temp = a[1] - a[0];
	for (i = 0; i < size; i++) 
		if (i - 1 > 0) 
			if (a[i] - a[i - 1] != temp)
				return 0;
		
	
	return 1;
}
//중복순열
void pick(int* items,int itemSize, int* bucket, int bucketSize, int k,int* num1,int* num2) {
	int i, lastIndex, smallest, item;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			if (items[bucket[i]] == -1)
				num2[i] = num1[i]-1;
			else if(items[bucket[i]] == 0)
				num2[i] = num1[i];
			else if (items[bucket[i]] == 1)
				num2[i] = num1[i]+1;
		}
		sum += isSequence(num2, bucketSize);
		return;
	}

	lastIndex = bucketSize - k - 1;


	smallest = 0;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1, num1, num2);
	}

}
int main(void) // 이 main함수를 그대로 사용해도 좋고, 변경하여도 좋다
{
	int items[3] = { -1, 0, 1 };
	int n;
	int* bucket;
	int* num1;
	int* num2;

	//printf("개수 입력");
	scanf("%d", &n);

	bucket = (int*)malloc(sizeof(int) * n);
	num1 = (int*)malloc(sizeof(int) * n);
	num2 = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num1[i]);
	pick(items, 3, bucket, n, n, num1, num2);
	//pick(int* items,int itemSize, int* bucket, int bucketSize, int k,int* num1,int* num2)
	printf("%d\n", sum);
}