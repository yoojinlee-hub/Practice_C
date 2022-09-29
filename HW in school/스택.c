#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void) {
	int size[10000];
	char in[50];
	int n = 0, i = 0, count = 0;

	scanf("%d", &count);

	while (count) {
		scanf("%s", in);


		if (strcmp(in, "push") == 0) {
			scanf("%d", &n);
			size[i++] = n;
		}

		else if (strcmp(in, "pop") == 0) {
			if (i > 0) {
				printf("%d\n", size[i - 1]);
				size[i - 1] = NULL;
				i--;
			}
			else
				printf("-1\n");
		}

		else if (strcmp(in, "size") == 0)
			printf("%d\n", i);

		else if (strcmp(in, "top") == 0) 
			if (i > 0)
				printf("%d\n", size[i - 1]);
			else
				printf("-1\n");
			
		else if (strcmp(in, "empty") == 0)
			if (i > 0) 
				printf("0\n");
			else 
				printf("1\n");
		
		count--;
	}
	return 0;
}