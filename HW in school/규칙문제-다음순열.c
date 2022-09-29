#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find = 0;
int count = 0;
int arrToNum(int* arr, int size) {
	int i = 0, tens = 1;
	int answer = 0;

	for (i = 0; i < size; i++) 
		tens *= 10;
	tens /= 10;
	for (i = 0; i < size; i++) {
		answer += ((arr[i] + 1) * tens);
		tens /= 10;
	}
	return answer;
}
int pick(int n, int* bucket, int bucketSize, int k, int input) {//순열
	int i, j, lastIndex, smallest, item, m;
	int chosen = 0; //없음
	static int cnt = 0;

	if (k == 0) {
		m = arrToNum(bucket, bucketSize);
		
		if (cnt == 1) {
			for (i = 0; i < bucketSize; i++)
				printf("%d ", bucket[i] + 1);
			printf("\n");
			count += 1;
			cnt += 1;
		}
		if (m == input)
			cnt += 1;

		return cnt;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;

	for (item = smallest; item < n; item++) {
		chosen = 0;
		for (i = 0; i <= lastIndex; i++) {
			if (bucket[i] == item) {
				chosen = 1; //이미 있음
				break;
			}
		}
		//if (chosen == 1) continue;
		if (chosen == 0) {
			bucket[lastIndex + 1] = item;
			pick(n, bucket, bucketSize, k - 1, input);
		}
	}
}
int main(void) {
	int n, pickedReturn, i, k = 0;
	char input[100]="", str[100]= "";
	int inputNum;
	int* picked;

	scanf("%d", &n);
	picked = (int*)malloc(sizeof(int) * n);

	getchar();
	for (i = 0; i < 2 * n; i++)
		scanf("%c", &input[i]);
	
	for (i = 0; input[i]!='\0'; i++) {
		if (input[i] != ' ' && input[i] != '\n')
			str[k++] = input[i];
	}
	str[k] = '\0';
	inputNum = atoi(str);

	
	pickedReturn = pick(n, picked, n, n, inputNum);
	if (count == 0)
		printf("-1");
	free(picked);
}