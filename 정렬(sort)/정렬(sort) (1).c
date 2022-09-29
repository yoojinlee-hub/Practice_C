#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//알파벳 대소문자로 된 단어가 주어지면, 
//이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
//단, 대문자와 소문자를 구분하지 않는다.
int main(void) {
	char str[100];
	char alphaS[27], alphaB[27];
	int strN[26] = { 0 };
	int sizeStr, max, count = 1;
	int i, j;

	scanf("%s", str);
	sizeStr = strlen(str);

	for (i = 0; i < 26; i++) { //같은 글자면 인덱스가 같음
		alphaB[i] = 'A' + i; //대문자
		alphaS[i] = 'a' + i; //소문자
	}
	alphaB[26] = '\0';
	alphaS[26] = '\0';

	for (i = 0; i < sizeStr; i++) 
		for(j=0;j<26;j++)
			if (str[i] == alphaB[j] || str[i] == alphaS[j])
				strN[j]++;
	
		
	max = strN[0];
	for (i = 0; i < 26; i++)
		if (max <= strN[i]) 
			max = strN[i];
	
	for (i = 0; i < 26; i++)
		if (max == strN[i]) { //같은 단어가 2개 이상이면 count가 2 이상
			count++; //기본 2
			j = i;
		}

	if (count > 2)
		printf("?");
	else //가장 큰 값이 든 인덱스?
		printf("%c", alphaB[j]);
	
		
}