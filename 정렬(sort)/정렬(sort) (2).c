#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];
	int isit[26] ;
	int* isitP = { 0 };
	char* strP;
	int i, j, sizeS;
	int count = 0;

	scanf("%s", str); //단어 입력
	sizeS = strlen(str);

	isitP = isit;
	for (i = 0; i < 26; i++)
		*isitP++ = -1;

	for(i='a';i<='z';i++)
		for(j=0;j<sizeS;j++)
			if (i == str[j]) {
				isit[str[j] - 'a'] = j;
				break;
			}

	for (i = 0; i < 26; i++)
		printf("%d ", isit[i]);
}