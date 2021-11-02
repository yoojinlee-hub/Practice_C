
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<ctype.h>
int main(void)
{
	char string[50]; // 입력되는 문자열을 저장
	char alphaString1[50]; // 입력문자열에서 알파벳만 저장
	char alphaString2[50]; // 대소문자를 바꿈
	char digitString[50];
	char convertedString[50]; // 문자들과 숫자들로 재배열한 문자열
	
	printf("문자열을 입력하세요:");
	fgets(string, sizeof(string), stdin);

	char* p = string;
	char* p1 = alphaString1;
	char* p2 = digitString;

	while (*p != '\n') {
		if (isalpha(*p)) // 입력문자열에서 알파벳만 저장
			*p1++ = *p;
		if (isdigit(*p))// 입력문자열에서 숫자만 저장
			*p2++ = *p;
		p++;
	}
	*p1 = '\0';
	*p2 = '\0';

	printf("문자들은 %s\n", alphaString1);
	printf("숫자들은 %s\n", digitString);

	int i;
	for (i = 0; i < (int)strlen(alphaString1); i++) {
		if (alphaString1[i] == tolower(alphaString1[i]))
			alphaString2[i] = toupper(alphaString1[i]);
		if (alphaString1[i] == toupper(alphaString1[i]))
			alphaString2[i] = tolower(alphaString1[i]);
	}
	alphaString2[i] = '\0';

	strcpy(convertedString, alphaString1);
	strcat(convertedString, digitString,(int)strlen(digitString));

	printf("대소문자를 바꾼 문자들은 %s\n", alphaString2);
	printf("문자들과 숫자들로 재배열한 문자열은 %s\n", convertedString);
}