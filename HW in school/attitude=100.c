/*************
20191770 이유진 컴퓨터학과 3학년
**************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calculatePoint(char s[]);
int main(void) {
	char str[20];

	printf("단어를 입력하세요(빈칸없이):");
	scanf("%s", str);

	printf("점수는 %d\n", calculatePoint(str));
}
int calculatePoint(char s[]) {
	int i;
	int point[20];
	int pointNum = 0, sum = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			point[pointNum] = s[i] - 64;
			pointNum++;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			point[pointNum] = s[i] - 96;
			pointNum++;
		}
	}
	for (i = 0; i < pointNum; i++)
		sum += point[i];

	return sum;
}