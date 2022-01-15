#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char input[50], * result;
	int num[10] = { 0 };
	int i = 0;
	int sum = 0;
	gets(input);

	result = strtok(input, "+");
	while (result) {
		num[i] = atoi(result);
		i++;
		result = strtok(NULL, "+"); //이전에 자기가 기억한 곳으로부터 분리 시도
	}
	for (i = 0; i < 10; i++)
		sum += num[i];
	

	printf("%d\n",sum);
}