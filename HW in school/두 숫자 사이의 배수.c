#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char input[100]=" ";
	int num, numA, numB;
	int i;

	printf("숫자 두 개를 입력해주세요(ex. '3 5'):");
	gets(input);
	printf("배수를 알고 싶은 숫자를 입력해주세요:");
	scanf("%d", &num);

	numA = atoi(strtok(input, " "));
	numB = atoi(strtok(NULL, "\0"));

	for (i = numA; i <= numB; i++)
		if (i % num == 0)
			printf("%d ", i);
	printf("\n");
}