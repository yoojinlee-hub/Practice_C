
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int state;
	FILE* fp;
	char ch;

	fp = fopen("hello.out", "wt");
	if (fp == NULL) {
		printf("file open error!\n");
		return 1;
	}

	fprintf(fp, "hello ");
	fprintf(fp, "world\n");

	state = fclose(fp);
	if (state != 0) {
		printf("file close error!\n");
		return 1;
	}
}