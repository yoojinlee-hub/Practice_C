#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int data[100];
	int count[10] = { 0 };
	int num = 0, i, j;

	srand(time(NULL));

	printf("Enter the number of random numbers:<<=100>>:");
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		data[i] = rand() % 10;
		count[data[i]]++;
	}

	for (i = 0; i < 10; i++) {
		printf("%d의 개수는 %d\n", i, count[i]);
	}
	printf("----------------------------\n");

	printf("발생된 난수는 \n");
	for (i = 0; i < num; i++) {
		if ((i != 0) && (i % 5 == 0))
			printf("\n");
		printf("%5d", data[i]);
	}
	printf("\n");
	return 0;
}