/****************
* LABHW3_5 20191770 이유진 컴퓨터학과 3학년
************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <time.h>

void initArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		arr[i] = rand() % 100;
	return;
}
void selectionSort(int list[], int size) {
	int i, j, temp, minIndex;

	for (i = 0; i < size - 1; i++) {
		minIndex = i;
		for (j = i+1; j < size; j++) 
			if (list[j] < list[minIndex])
				minIndex = j;
		
		temp = list[i];
		list[i] = list[minIndex];
		list[minIndex] = temp;
	}
}
void printArray(int a[], int size) {
	int i;

	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main(void) {
	int i, a[10];
	srand(time(NULL));
	printf("발생된 난수:     ");
	initArray(a, 10);
	printArray(a, 10);

	printf("정렬 후:        ");
	selectionSort(a, 10);
	printArray(a, 10);
}