#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int arr[100][100] = { 0 };
void inputArr(int N, int M, int arr[][100]) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);
}
int isBlock(int i, int j)
{
	if (arr[i][j] == 1) return 1;
	else return 0;
}
int isFinish(int i, int j)
{
	if (i == N && j == M) return 1;
	else return 0;
}
int findWay(int N, int M, int arr[][100],int r, int c) {
	if (isFinish(r,c)) return 0;
	else if (r+1<N) {
		if (isBlock(r, c))return findWay(N, M, arr, r + 1, c);
		if (isBlock(r + 1, c)) return findWay(N, M, arr, r + 1, c);
		if (isBlock(r, c + 1))return findWay(N, M, arr, r, c + 1);
		if (isBlock(r - 1, c))return findWay(N, M, arr, r - 1, c);
		if (isBlock(r, c - 1))return findWay(N, M, arr, r, c - 1);
	}
	else if ( c + 1 < M) {
		if (isBlock(r, c))return findWay(N, M, arr, r, c+1);
		if (isBlock(r, c + 1))return findWay(N, M, arr, r, c + 1);
		if (isBlock(r - 1, c))return findWay(N, M, arr, r - 1, c);
		if (isBlock(r, c - 1))return findWay(N, M, arr, r, c - 1);
	}
}
int main(void) {
	int i, j;

	scanf("%d %d", &N, &M);
	inputArr(N, M, arr);

	if (arr[0][0] != 1 || arr[N - 1][M - 1] != 1) printf("해결불가미로");
	else {
		findWay(N, M, arr, 0, 0);
	}
}