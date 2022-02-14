#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binaryFind(int* arr, int key, int size) {
	int lindex = 0, rindex = size - 1, mindex = (lindex + rindex) / 2;

	while (arr[lindex] < arr[rindex]) {
		mindex = (lindex + rindex) / 2;
		if (key == arr[mindex]) return mindex;
		else if (key < arr[mindex]) rindex = mindex - 1;
		else if (key > arr[mindex]) lindex = mindex + 1;
	}
	return -1;
}
int main(void) {
	int n, key;
	int arr[100] = { 0 };
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &key);

	if (binaryFind(arr, key, n) != -1)printf("1");
	else printf("0");
}