#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char after[27];
void makeCode(char* before, int distance) {
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
void encode(char* coded, char* sentence, char* encodedSentence) {
	int i, encodedIndex;

	for (i = 0; i < strlen(sentence); i++)
		if (sentence[i] == ' ')
			encodedSentence[i] = ' ';
		else {
			encodedIndex = sentence[i] - 'A';
			encodedSentence[i] = after[encodedIndex];
		}
	encodedSentence[strlen(encodedSentence)] = '\0';
}
void decode(char* code, char* encodedSentence, char* decodedSentence) {
	int i, decodedIndex;

	for (i = 0; i < strlen(encodedSentence); i++)
		if (encodedSentence[i] == ' ')
			decodedSentence[i] = ' ';
		else {
			decodedIndex = encodedSentence[i] - after[0];
			decodedSentence[i] = code[decodedIndex];
		}
	decodedSentence[strlen(encodedSentence)] = '\0';
}
void printCode(char* code) {
	printf("-------------------------------\n");
	printf("alphabet:\t%s\n", code);
	printf("encoded:\t%s\n", after);
	printf("-------------------------------\n\n");
}
int main(void)
{
	char code[27]; // code[0]부터 'A'의 암호화문자를 넣음
	int distance;
	char sentence[80];
	char encodedSentence[80];
	char decodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	makeCode(code, distance);
	printCode(code);
	while (getchar() != '\n');

	printf("Enter a sentence to encode:");
	fgets(sentence, sizeof(sentence), stdin);
	encode(code, sentence, encodedSentence);

	printf("original sentence:\t");
	puts(sentence);

	printf("encoded sentence:\t");
	puts(encodedSentence);

	decode(code, encodedSentence, decodedSentence);
	printf("decoded sentence:\t");
	puts(decodedSentence);
}