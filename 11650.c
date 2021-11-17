#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int x;
	int y;
}St;

int main(void) {
	St s[100000];
	int num, i, temp, j;
	int xMin = 0, yMin = 0;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &s[i].x);
		scanf("%d", &s[i].y);
	}
	
	//sort의 정렬(선택정렬사용)
	for (i = 0; i < num - 1; i++) {
		xMin = i;
		yMin = i;
		for (j = i + 1; j < num; j++) {
			if (s[j].x < s[xMin].x)
				xMin = j;
			if (s[j].y < s[xMin].y)
				yMin = j;
		}
		temp = s[i].x;
		s[i].x = s[xMin].x;
		s[xMin].x = temp;

		temp = s[i].y;
		s[i].y = s[yMin].y;
		s[yMin].y = temp;
	}

	for (i = 0; i < num; i++) 
		printf("%d %d\n", s[i].x, s[i].y);
	
}