#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void makeMarch(int arr[31]) {
	int i;
	for (i = 0; i < 31; i++)
		arr[i] = i + 1;
}
void printArr(int arr[31]) {
	int i;
	printf("\t");
	for (i = 0; i < 31; i++) {
		printf("\t%d", arr[i]);
		if (arr[i] % 7 == 6 && i != 0)
			printf("\n");
	}
	printf("\n");
}
int main(void) {
	int month[31];
	int i;

	makeMarch(month);

	printf("\t\t\t\t\t\t<3월 달력>\n");
	printf("\t일\t월\t화\t수\t목\t금\t토\n");
	printArr(month);
}