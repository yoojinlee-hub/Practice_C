#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
첫째 줄에는 카드의 개수 N과 목표 값 X가 주어지며, 
두번째 줄에는 카드에 쓰여있는 수가 입력으로 주어질 때
X에 가장 가까우면서 X를 넘지 않는 
카드 세장의 합을 구해서 출력하세요.
*/
int main(void) {
	int size, target;
	int arr[100] = { 0 };
	int i, j, k;
	int sum = 0, newgap = 0, gap = 10000;

	scanf("%d %d", &size, &target);

	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	for(i=0;i<size;i++)
		for(j=i+1;j<size;j++)
			for (k = j + 1; k < size; k++) {
				sum = arr[i] + arr[j] + arr[k];
				newgap = target - sum;
				if (newgap <= gap && newgap > 0)
					gap = newgap;
			}
	printf("%d", target - gap);
}