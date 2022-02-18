#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isitPrime(int n) {
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0) return 0;
	return 1;
}
void RemoveFirst(char* buf)
{
	int i = 0;
	for (i = 1; buf[i]; i++)
		buf[i - 1] = buf[i]; 
	buf[i - 1] = '\0';
}
int main(void) {
	char input[100] = "", nums[100] = "";
	int i, j, count = 1;
	int k = 1;
	int ans = 0, num = 0;

	scanf("%s", input);

	//연속된 문자열
	for (i = 0; i<=strlen(input);) {
		strcpy(nums, "");
		strcat(nums, "\0");
		for (j = 0; j < strlen(input); j++) {
			strncpy(nums, input, k++);
			nums[k - 1] = '\0';
			num = isitPrime(atoi(nums));
			if (num == 1 && atoi(nums) >= ans && atoi(nums) > 1)
				ans = atoi(nums);
		}
		RemoveFirst(input);
		i = count++; k = 1;
	}
	printf("%d", ans);
}