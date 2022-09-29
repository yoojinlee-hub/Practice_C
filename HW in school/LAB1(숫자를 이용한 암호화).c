#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void makeEncodedAlpha(char* before, char* after, int distance) {
	int i, j = 0;

	for (i = 0; i < 26; i++)
		before[i] = 'A' + i;
	before[26] = '\0';

	for (i = 0; i < 26; i++) {
		if (i + distance < 26)
			after[i] = before[i + distance];
		else
			after[i] = 'A' + j++;
	}
	after[26] = '\0';
}
void makeInputToEncoded(char* encoded, char* input, char* output) {
	int i, encodedIndex;

	for (i = 0; i < strlen(input); i++) 
		if (input[i] == ' ')
			output[i] = ' ';
		else {
			encodedIndex = input[i] - 'A';
			output[i] = encoded[encodedIndex];
		}
	output[strlen(input)] = '\0';
}
int main(void) {
	int distance;
	char alpha[27], encoded[27], input[80], output[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	printf("-------------------------------\n");
	makeEncodedAlpha(alpha, encoded, distance);
	printf("%s\n", alpha);
	printf("%s\n", encoded);
	printf("-------------------------------\n\n");

	while (getchar() != '\n');
	printf("Enter a sentance to encode:");
	fgets(input, sizeof(input), stdin);

	makeInputToEncoded(encoded, input, output);
	printf("original sentence:\t%s", input);
	printf("encoded sentence:\t%s", output);
}