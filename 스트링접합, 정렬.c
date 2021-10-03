/*************
스트링접합 , 정렬
*************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mergeString(char c[], char a[], char b[]) {
	int i, j;
	int sizeA = 0, sizeB = 0, sizeC = 0;
	char temp;
	int minIndex;

	for (i = 0; a[i] != '\0'; i++) sizeA = i;
	for (i = 0; b[i] != '\0'; i++) sizeB = i;
	sizeC = (sizeA + 1) + (sizeB + 1);

	//단순 합치기
	for (i = 0; a[i] != '\0'; i++)
		c[i] = a[i];
	for (i = 0; b[i] != '\0'; i++)
		c[sizeA + 1 + i] = b[i];
	c[sizeC] = '\0';

	//정렬하기
	for (i = 0; i < sizeC - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < sizeC; j++)
			if (c[j] <= c[minIndex])
				minIndex = j;
		temp = c[i];
		c[i] = c[minIndex];
		c[minIndex] = temp;
	}

	return 0;	
}
int main(void) {
	char word1[10], word2[10];
	char mergeWord[20];

	scanf("%s", word1);
	scanf("%s", word2);
	mergeString(mergeWord, word1, word2);
	printf("%s\n", mergeWord);
}