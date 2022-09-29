#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isitPalindrome(char* s) {
	int size = strlen(s);
	int i;

	for (i = 0; i < size / 2; i++)
		if (s[i] != s[size - 1 - i])
			return 0;
	return 1;
}
int makingPalindrome(char* s, char* s2) {
	//s의 거꾸로된 배열=s3;
	int min = strlen(s) * 2, temp = 0;
	int size = strlen(s);
	int i, j, k;


	while (getchar() != '\n');
	k = 0;
	while (k < size - 1) {
		strncpy(s2, s, size);

		j = 1;
		for (i = (size - 1) + 1; i <= 2 * (size - 1) - k; i++)
			s2[i] = s[size - 1 - k - j++];

		s2[2 * (size - 1) - k + 1] = '\0';
		k += 1;

		if (isitPalindrome(s2) == 1) {
			temp = strlen(s2);
			if (temp <= min)
				min = temp;
		}
	}

	return min;
}
int main(void) {
	char s[100], s2[100];

	scanf("%s", s);

	printf("%d", makingPalindrome(s, s2));
}