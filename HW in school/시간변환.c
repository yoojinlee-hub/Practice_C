#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input;
	int days = 0, hours = 0, min = 0, sec = 0;

	printf("초 단위의 시간을 입력해주세요: ");
	scanf("%d", &input);

	printf("%d초=", input);
	if (input >= 86400) {
		days = input / 86400;
		printf("%d일 ", days);
		input -= 86400 * days;
	}
	if (input >= 3600) {
		hours = input / 3600;
		printf("%d시간 ", hours);
		input -= 3600 * hours;
	}
	if (input >= 60) {
		min = input / 60;
		printf("%d분 ", min);
		input -= 60 * min;
	}
	if (input >= 0) {
		printf("%d초 ", input);
	}
	printf("\n");
}