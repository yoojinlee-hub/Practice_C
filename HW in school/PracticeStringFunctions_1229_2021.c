#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//문자열 처리 함수 라이브러리

int main(void) {
	int size1 = 0, size2 = 0;

	char* s1 = (char*)malloc(sizeof(char) * 50);
	scanf("%[^\n]s", s1);
	s1=strcat(s1,"\0"); //s1=s1+'\0'
	size1 = strlen(s1); 

	//버퍼지우기
	while (getchar() != '\n');

	char* s2 = (char*)malloc(sizeof(char) * 50);
	scanf("%[^\n]s", s2);
	s2 = strcat(s2, "\0");
	size2 = strlen(s2); 


	if (size1 == size2)
		printf("%s",strcat(s1, s2));
	else if (size1 > size2)
		printf("%d", size1);
	else
		printf("%d", size2);
	printf("\n");

	free(s1);
	free(s2);
}