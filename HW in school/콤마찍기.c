#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char arr[20];
	int i;

	scanf("%s", arr);

	if (strlen(arr) > 4) {
		for (i = 0; arr[i] != '\0'; i++) {
			if ((strlen(arr) - i) % 3 == 0 && i != 0)
				printf(",");
			printf("%c", arr[i]);
		}
	}
	else
		printf("%s", arr);
}