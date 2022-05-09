#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
int findOverlap(char* s, char* s2) {
	int i, j = 0, count = 1;
	int size;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == s[i + 1]) {
			count += 1;
		}
		else if (count != 1) {
			s2[j++] = count + '0';
			s2[j++] = s[i];
			count = 1;
		}
		else {
			s2[j++] = s[i];
			count = 1;
		}

	}
	s2[j] = '\0';
	size = strlen(s2);
	printf("%s\n", s2);
	return size;
}
int findOverlap2(char* s, char* s2) {
	int i, j = 0, count = 1, tmp = 0, cnt = 0;
	int size;

	for (i = 0; i < strlen(s);) {
		if (s[i] == s[i + 2] && s[i + 1] == s[i + 3]) {
			count += 1;
			i += 2;
			cnt = 1; //두 개 단위로 같은게 있음
		}
		else if (count != 1 && cnt == 1) { //두 개 단위로 같은거 확인하고 저장
			if (count > 9) {
				s2[j++] = (count / 10) + '0';
				s2[j++] = (count % 10) + '0';
			}
			else {
				s2[j++] = count + '0';
			}
			s2[j++] = s[i];
			s2[j++] = s[i + 1];
			count = 1;
			tmp = 1; //저장 한 적 있음
			cnt = 0;
			i++;
		}
		else if (cnt == 0 && tmp == 0) { //두 개 단위로 같은 것도 없고 저장 한 적도 없음
			s2[j++] = s[i];
			s2[j++] = s[i + 1];
			i += 2;
		}
		else if (tmp == 0) { //저장한 적이 있음
			s2[j++] = s[i];
			count = 1;
			i += 1;
		}
		else if (tmp == 1) {//두 개 단위로 같은게 있고 출력함
			tmp = 0;
			i += 1;
		}

	}
	s2[j] = '\0';
	printf("%s\n", s2);
	size = strlen(s2);
	return size;
}
int findOverlap3(char* s, char* s2) {
	int i, j = 0, count = 1, tmp = 0, cnt = 0;
	int size;

	for (i = 0; i < strlen(s);) {
		if (s[i] == s[i + 3] && s[i + 1] == s[i + 4] && s[i + 2] == s[i + 5]) {
			count += 1;
			i += 3;
			cnt = 1; //두 개 단위로 같은게 있음
		}
		else if (count != 1 && cnt == 1) { //두 개 단위로 같은거 확인하고 저장
			if (count > 9) {
				s2[j++] = (count / 10) + '0';
				s2[j++] = (count % 10) + '0';
			}
			else {
				s2[j++] = count + '0';
			}
			s2[j++] = s[i];
			s2[j++] = s[i + 1];
			s2[j++] = s[i + 2];
			count = 1;
			tmp = 1; //저장 한 적 있음
			cnt = 0;
			i++;
		}
		else if (cnt == 0 && tmp == 0) { //두 개 단위로 같은 것도 없고 저장 한 적도 없음
			s2[j++] = s[i];
			s2[j++] = s[i + 1];
			s2[j++] = s[i + 2];
			i += 3;
		}
		else if (tmp == 0) { //저장한 적이 있음
			s2[j++] = s[i];
			count = 1;
			i += 1;
		}
		else if (tmp == 1) {//두 개 단위로 같은게 있고 출력함
			tmp = 0;
			i += 2;
		}
	}
	s2[j] = '\0';
	printf("%s\n", s2);
	size = strlen(s2);
	return size;
}*/
int findOverlap(char* s, char* s2, int find) {
	int i, j = 0, count = 1, tmp = 0, cnt = 0, findSame = 0, countF = 0;
	int size;

	for (i = 0; i < strlen(s);) {
		for (int k = find; k < find*2; k++) {
			if (s[i] == s[i + k])
				findSame += 1;
		}
		if (findSame==find) {
			count += 1;
			i += find;
			cnt = 1; //두 개 단위로 같은게 있음
		}
		else if (count != 1 && cnt == 1) { //두 개 단위로 같은거 확인하고 저장
			if (count > 9) {
				s2[j++] = (count / 10) + '0';
				s2[j++] = (count % 10) + '0';
			}
			else {
				s2[j++] = count + '0';
			}
			countF = 0;
			while (countF<find) {
				s2[j++] = s[i + countF++];
			}
			count = 1;
			tmp = 1; //저장 한 적 있음
			cnt = 0;
			i++;
		}
		else if (cnt == 0 && tmp == 0) { //두 개 단위로 같은 것도 없고 저장 한 적도 없음
			countF = 0;
			while (countF < find) {
				s2[j++] = s[i + countF++];
			}
			i += find;
		}
		else if (tmp == 0) { //저장한 적이 있음
			s2[j++] = s[i];
			count = 1;
			i += 1;
		}
		else if (tmp == 1) {//두 개 단위로 같은게 있고 출력함
			tmp = 0;
			i += find - 1;
		}
	}
	s2[j] = '\0';
	printf("%s\n", s2);
	size = strlen(s2);
	return size;
}
int main(void) {
	char input[1000], output[1000];
	int min, newN;
	int i;

	scanf("%s", input);

	min = findOverlap(input, output, 1);
	for (i = 2; i < (strlen(input) / 2); i++) {
		char output2[1000];
		newN = findOverlap(input, output2, i);
		if (newN <= min) min = newN;
	}
	
	printf("%d\n", min);
	
}