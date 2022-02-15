#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int index = 100;
int arr[10][10] = { 0 };

int isitConnected(int r,int c,int arr[][10],int n) {
	int i, cnt = 0;
	if (index == c) return 1; //c°¡ µµÂøÁö
	else {
		for (i = 0; i < n; i++)
			if (arr[r][i] == 1) {
				index = i;
				cnt++;
			}
		if (cnt)return isitConnected(index, c, arr, n);
		else return 0;
	}
}
int main(void) {
	int n;
	int answer[10][10] = { 0 };
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (isitConnected(i, j, arr, n)) answer[i][j] = 1;
			else answer[i][j] = 0;

	printf("=====================\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", answer[i][j]);
		printf("\n");
	}
		
}