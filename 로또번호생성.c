#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortArr(int arr[6]) {
	int i, j, minIndex = 0;
	int temp = 0;
	for (i = 0; i < 5; i++) {
		minIndex = i;
		for (j = i + 1; j < 6; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}
int isin(int arr[6], int newN, int size) {
	int i;
	for (i = 0; i < size; i++)
		if (arr[i] == newN)
			return 0;
	return 1;
}
int main(void) {
	int lotto[6];
	int i, newN = 0;
	char input;
	srand(time(NULL));

	while (1) {
		printf("*** 로또 번호 생성기 ***\n");
		printf("생성번호:");

		for (i = 0; i < 6; i++) {
			newN= rand() % 45 + 1;
			lotto[i] = newN;
			if (i != 0) {
				while (1) {
					if (isin(lotto, newN, i) == 1) {
						lotto[i] = newN;
						break;
					}else
						newN= rand() % 45 + 1;
				}
			}
		}
			
		sortArr(lotto);
		for (i = 0; i < 6; i++)
			printf("%d ", lotto[i]);
		
		printf("\n");
		printf("다시 생성하겠습니까?(y/n):");
		scanf("%c", &input);

		if (input == 'n') break;
		
		while (getchar() != '\n');//버퍼지우기
	}
}