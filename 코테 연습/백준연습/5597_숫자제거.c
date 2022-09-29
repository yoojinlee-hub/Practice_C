#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[30];
int value;
int i;

int main()
{
	for (i = 1; i <= 28; i++) { 
		scanf("%d", &value);
		arr[value] = 1;
	}

	for (i = 1; i <= 30; i++)
		if (!arr[i])
			printf("%d\n", i);
	return 0;
}