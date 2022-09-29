/****************
* LABHW3_4_2 20191770 이유진 컴퓨터학과 3학년
************/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <stdio.h>

void printSet(int a[], int size) {
	int i;

	printf("{ ");
	for (i = 0; i < size; i++) {
		if (i < size - 1)
			printf("%d, ", a[i]);
		else
			printf("%d ", a[i]);
	}
	printf("}\n");
}
int findSet(int b[], int size, int key) {
	int i;

	for (i = 0; i < size; i++) 
		if (b[i] == key)
			return 1;
	return 0;
}

int main(void) {
	int data[SIZE];
	int i, is_in, content;

	for (i = 0; i < SIZE; i++) {
		printf("집합에 추가할 원소: ");
		scanf("%d", &content);

		is_in=findSet(data, i, content);
		if (is_in) {
			printf("%d는 이미 집합에 있음\n", content);
			i--;
		}
			
		else {
			data[i] = content;
			printSet(data, i + 1);
		}
			
	}
}