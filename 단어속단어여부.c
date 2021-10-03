/*************
단어속단어여부
*************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//문자열 w2가  w1의 start위치에 있으면 1, 아니면 0 반환
int is_word_in_word(char w1[], int start, char w2[]) {
	int i, j = 0;
	int w2Size = 0;
	int count = 0, flag = 0;

	for (i = 0; w2[i] != '\0'; i++)
		w2Size = i + 1;

	//w1[i]=w2[0] && w1[i+1]=w2[1] && ~ && w1[w2Size-1]= w2[w2Size-1]
	for (i = start; w1[i]!='\0';) {
		count = 0;
		for (j = 0; j < w2Size; j++) {
			if (w1[i] == w2[j])
				count++;
			i++;
		}
		if (i >= w2Size)
			break;
	}
		

	if (count == w2Size)
		return 1;

	return 0;
}
int main(void) {
	char s1[20], s2[20];
	int i, j;

	scanf("%s", s1);
	scanf("%s", s2);

	for (i = 0; s1[i] != '\0'; i++)
		printf("%d", is_word_in_word(s1, i, s2));
}