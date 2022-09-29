
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char str[50];
	char birthY[3], gend[2];
	char* birthday, * gender, * age;

	printf("주민등록번호 입력<'-'포함>:");
	gets(str);

	strncpy(birthY, str, 2);
	birthY[2] = '\0';

	printf("당신은 ");
	printf(birthY);
	printf("년도 생이군요\n");
	
	birthday = strtok(str, "-");
	gender = strtok(NULL, "\0");
	strncpy(gend, gender, 1);
	gend[1] = '\0';
	
	if (gend[0] == '1') {
		printf("남자분이시군요.\n");
		printf("평균 수명 77을 더하면 %d까지 산다고 계산됩니다.\n", (1900+atoi(birthY) + 77));
	}
	else if (gend[0] == '2') {
		printf("여자분이시군요.\n");
		printf("평균 수명 84을 더하면 %d까지 산다고 계산됩니다.\n", (1900+atoi(birthY) + 84));
	}
}