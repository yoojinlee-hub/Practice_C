#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
2차원 배열이 주어졌을 때 (i, j) 위치부터 
(x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 
프로그램을 작성하시오.
배열의 (i, j) 위치는 i행 j열을 나타낸다.
*/

int main(void) {
	int N, M, K; //동적할당 이용X
	int arr[300][300] = { 0 };
	int i, j, k;
	int minRows,minCols,maxRows,maxCols;
	int sum[10000] = { 0 };

	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);

	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		scanf("%d", &minRows);
		scanf("%d", &minCols);
		scanf("%d", &maxRows);
		scanf("%d", &maxCols);

		for (j = minRows-1; j < maxRows; j++) //-1한 이유: 1,1 처럼 보이지만 사실은 0,0이다!
			for (k = minCols-1; k < maxCols; k++)
				sum[i] += arr[j][k];
	}
	
	for (i = 0; i < K; i++)
		printf("%d ", sum[i]);
	printf("\n");

}