//LAB(최대값)순환
//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max2(int list[], int low, int high) {
	int i, middle, max = list[low];
	if (low <= high) {
		middle = (low + high) / 2;
		if (max <= list[middle]) max = list[middle];
		else if (max < list[middle])
			return max2(list, low, middle - 1);
		else
			return max2(list, middle + 1, high);
	}
}
int max1(int list[], int low, int high) {
	int i;
	int max = list[low];
	for (i = low; i <= high; i++)
		if (list[i] >= max)
			max = list[i];
	return max;
}
int main(void) {
	int list[] = { 10,20,100,4,5,45,3,99,11,22 }; //정렬되지 않은 배열

	printf("가장 큰 수는 %d\n", max1(list, 0, 9));
	printf("가장 큰 수는 %d\n", max1(list, 0, 9));

	printf("가장 큰 수는 %d\n", max1(list, 5, 9));
	printf("가장 큰 수는 %d\n", max1(list, 5, 9));

	printf("가장 큰 수는 %d\n", max1(list, 3, 6));
	printf("가장 큰 수는 %d\n", max1(list, 3, 6));
}