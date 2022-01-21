#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int size = 0;
	char* input = (char*)malloc(sizeof(char) * 100);
	char print[3] = "";
	int i, j = 0;

	scanf("%s", input);
	size = strlen(input);


	if (size % 2 == 0) { //Å©±â°¡ Â¦¼ö
		for (i = 0; i < size; i++) {
			if (i == size / 2 - 1){
				print[j] = *input;
				input++;
				print[j + 1] = *input;
				break;
			}
			input++;
		}
	}
	else {
		for (i = 0; i < size; i++) {
			if (i == size / 2) {
				print[j] = *input;
				break;
			}
			input++;
		}
	}
	
	strcat(print, "\0");
	printf("%s", print);
}