//컴퓨터학과 4학년 20191770 이유진
//순환 palindrome 만들기 //배열추가x
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse_string(char* str, int s, int e) {
	//재귀 사용해야함 -> 점점 범위가 줄어드는 것
	if (s > e);
	else {
		printf("%c", str[e - s]);
		reverse_string(str, s + 1, e);
	}
}
int main() {
	char str[100];

	printf("Enter any string:");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;
}