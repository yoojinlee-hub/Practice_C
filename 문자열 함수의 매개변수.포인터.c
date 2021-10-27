
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stringCompare(const char* s1, const char* s2)
{
	int count = 0;
	while (*s1 != '\0' || *s2 != '\0')
		if (*s1++ != *s2++) {
			if (*s1 > *s2)
				return -1; //정렬안되는 순간 빠져나옴
			return 1; //정렬됨
		}

	return 0; //같으면 0 전달
}
void stringCat(char* s1, const char* s2)
{
	//접합하는 함수(s1에다가)
	int i, size = 0;

	while (*s1 != '\0') 
		s1++; //s1의 크기만큼 이동함
	while (*s2 != '\0')
		*s1++ = *s2++; //이동 한 후 다음부터 s2를 집어넣음
	*s1 = '\0';
}
void stringChange(char* s, char ch, char newCh)
{
	// s문자열 안의 ch 문자를 newCh로 바꾸는 함수
	while (*s != '\0') {
		if (*s == ch) {
			*s = newCh;
			s++;
		}
		else
			s++;
	}

}
int main(void)
{
	char name1[20];
	char name2[20];

	printf("Enter the first name: ");
	scanf("%s", name1);
	printf("Enter the second name: ");
	scanf("%s", name2);

	if (stringCompare(name1, name2) == 0)
		printf("두개의 이름은 같다\n");
	else if (stringCompare(name1, name2) == 1)
		printf("두개의 이름은 다르며 정렬되어있다\n");
	else
		printf("두개의 이름은 다르며 정렬되어있지않다\n");

	stringCat(name1, name2);
	printf("The concatenated name is %s\n", name1);

	stringChange(name1, 'u', 'x');
	printf("The changed name is %s\n", name1);
}