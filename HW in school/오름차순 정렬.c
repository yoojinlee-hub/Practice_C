#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int money[4];
	int set_money[4];
	int i, j;
	int temp;

	for (i = 0; i < 4; i++) {
		scanf("%d", &money[i]);
	}
	for (i = 0; i < 4; i++) {
		set_money[i] = money[i];
	}
	for (i = 0; i < 3; i++) { //오름차순 정렬
		for (j = 0; j < 3 - i; j++) {
			if (set_money[j] > set_money[j + 1]) {
				temp = set_money[j];
				set_money[j] = set_money[j + 1];
				set_money[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 4; i++) {
		printf("%d ", set_money[i]);
	}
	printf("\n");
	return 0;
}