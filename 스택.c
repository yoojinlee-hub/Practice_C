#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int size[100];
	char in[50];
	int n = 0, i = 0;

	while (1) {
		scanf("%s", in);

		if (strcmp(in, "push") == 0) {
			scanf("%d", &n);
			size[i++] = n;
		}
		else if (strcmp(in, "pop") == 0) {
			printf("%d", size[i - 1]);
			size[i - 1] = NULL;
			i--;
		}
		else if (strcmp(in, "top") == 0)
			printf("%d", size[i-1]);
		else if (strcmp(in, "bottom") == 0)
			printf("%d", size[0]);
	}
	
}