//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id;
	int korean, english, math;
};
int randomNum(){
	int num;
	num = rand() % 101;
	return num;
}
void printArr(struct Student* arr, int size) {
	int i;
	for (i = 0; i < size; i++) 
		printf("학번: %d\t국어:%d\t영어:%d\t수학:%d\n", arr[i].id, arr[i].korean, arr[i].english, arr[i].math);	
}
void selectionSort(struct Student* arr, int size) {
	int min_idx, min;
	int i, j;
	struct Student temp;
	for (i = 0; i < size - 1; i++) {
		min = arr[0].korean; min_idx = 0;
		for (j = 1; j < size - i; j++) {
			if (min > arr[j].korean) {
				min = arr[j].korean;
				min_idx = j;
			}
		}
		temp = arr[size - 1 - i];
		arr[size - 1 - i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}
int main(void) {
	struct Student* arr;
	int n;
	int i;
	scanf("%d", &n);
	arr = (struct Student*)malloc(sizeof(struct Student) * n);

	for (i = 0; i < n; i++) {
		arr[i].id = i + 1;
		arr[i].korean = randomNum();
		arr[i].english = randomNum();
		arr[i].math = randomNum();
	}
	selectionSort(arr, n);
	printArr(arr, n);
	free(arr);
}