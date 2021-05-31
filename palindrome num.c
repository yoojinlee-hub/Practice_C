/*************
20191770 이유진 컴퓨터학과 3학년
**************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STRING 81
#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL isPalindrome(char str[]);

int main(void) {
	char str[MAX_STRING];

	printf("* Palindrome 체크\n\n");
	printf("문자열 입력(문자수 %d 이하):", MAX_STRING);
	scanf("%s", str);

	if (isPalindrome(str))
		printf("\"%s\" is a Palindrome\n\n", str);
	else
		printf("\"%s\" isn't a Palindrome\n\n", str);

	return 0;
}
isPalindrome(char str[]) {
	char str2[MAX_STRING];
	int i, len;

	for (i = 0; str[i] != '\0'; i++);
	len = i;
	for (i = len - 1; i >= 0; i--)
		str2[(len-1) - i] = str[i];
	str2[len] = '\0'; //중요!
	
	for (i = 0; i < len; i++) {
		if (str[i] != str2[i]) 
			return FALSE;	
	}
	if (i == len)
		return TRUE;
}