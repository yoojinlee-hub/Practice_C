//HW(동적할당을 이용한 조합출력)
//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int picked[],int m, int toPick) {
	int smallest, lastIndex, i;
	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d ", picked[i]);
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(n, picked, m, toPick - 1);
	}
}
int main(void) {
	int n, m;

	printf("Enter n and m:");
	scanf("%d %d", &n, &m);
	int *picked = (int*)malloc(sizeof(int) * m);

	pick(n, picked, m, m);
	free(picked);
}