#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];

	int strLength, i, count = 0;

	scanf("%s", str);
	strLength = strlen(str);

	
	for (i = 0; i < strLength; ) {
		if (str[i] == 'c') {
			if (str[i + 1] == '=') {
				count++;
				i = i + 2;
				continue;
			}	
			if (str[i + 1] == '-') {
				count++;
				i = i + 2;
				continue;
			}	
		}if (str[i] == 'd') {
			if (str[i + 1] == '-') {
				count++;
				i = i + 2;
				continue;
			}
			if (str[i + 1] == 'z' && str[i + 2] == '=') {
				count++;
				i = i + 3;
				continue;
			}
		}
		if (str[i] == 'l'|| str[i] == 'n')
			if (str[i + 1] == 'j') {
				count++;
				i = i + 2;
				continue;
			}
		if (str[i] == 's'|| str[i] == 'z')
			if (str[i + 1] == '=') {
				count++;
				i = i + 2;
				continue;
			}
		//세지 않는 경우 제외하기
		if (str[i] == '='||str[i]=='-')
			continue;
		if (str[i] == 'z') {
			if (i - 1 < 0)
				count++;
			if (str[i - 1] == 'd' && str[i + 1] == '=')
				continue;
			else
				count++;
			i++;
		}
		if (str[i] == 'j') {
			if (i - 1 < 0)
				count++;
			if (str[i - 1] == 'l' || str[i - 1] == 'j')
				continue;
			else
				count++;
			i++;
		}
		else {
			count++;
			i++;
		}
	}

	printf("%d", count);
}