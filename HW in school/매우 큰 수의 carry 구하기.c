//carry¹®Á¦ Àç±Í
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char src_s[],char s[],int size) {
	int i;

	for (i = 0; i < size; i++) {
		s[i] = src_s[size - 1 - i];
		s[size - 1 - i] = src_s[i];
	}
	s[size] = '\0';
}
int countOperators(char numA[],char numB[]) {
	int Alength = strlen(numA), Blength = strlen(numB);
	int A, B;
	int longer, i;
	int carry = 0;

	if (Alength >= Blength) 
		longer = Alength;
	else
		longer = Blength;
	
		
	for (i = 0; i < longer; i++) {
		if (numA[i] != '\0' && i<Alength) A = numA[i] - '0';
		else A = 0;
		if (numB[i] != '\0' && i < Blength) B = numB[i] - '0';
		else B = 0;

		if ((A + B) > 9) {
			carry += 1;
			if (i + 1 < longer)
				numA[i + 1] += 1;
		}
	}
	return carry;
}
int main(void) {
	char numA[101], numB[101];
	char rA[101], rB[101];
	int Alength, Blength;

	scanf("%s %s", numA, numB);
	Alength = strlen(numA);
	Blength = strlen(numB);

	reverse(numA, rA, Alength);
	reverse(numB, rB, Blength);

	printf("%d\n", countOperators(rA, rB));
}