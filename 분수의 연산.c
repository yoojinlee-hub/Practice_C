#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int findMeasure(int n, int m) {
	int temp = 0, temp1 = 0;
	int small[100] = { 0 }, big[100] = { 0 }; //약수
	int i, j, k = 0;

	if (n >= m) { //n<=m인 상태를 만들기 위해(n=son,m=mother)
		temp = m;
		m = n;
		n = temp;
	}
	for (i = 1; i <= n; i++)
		if (n % i == 0) {
			small[k] = i;
			k += 1;
		}
	temp = k - 1; //작은 수의 약수 갯수
	k = 0;
	for (j = 1; j <= m; j++)
		if (m % j == 0) {
			big[k] = j;
			k += 1;
		}
	temp1 = k - 1;//큰 수의 약수 갯수

	for (i = temp; i >= 1; i--) //small[0]=big[0]=1
		for (j = temp1; j >= 1; j--)
			if (small[j] == big[i])
				return small[i];
	return 1;
		
}
void makeDevide(int sonNum, int motherNum) {
	int devide = 0;

	devide = findMeasure(sonNum, motherNum);
	motherNum /= devide;
	sonNum /= devide;

	printf("%d / %d", sonNum, motherNum);
}
int main(void) {
	int a, b, x, y;
	int sonNum = 0, motherNum = 0, devide = 0;
	char how;
	int i,j;

	scanf("%d", &a);
	printf("/");
	scanf("%d", &b);
	scanf(" %c", &how);
	scanf("%d", &x);
	printf("/");
	scanf("%d", &y);
	
	//계산
	if (how == '+') {
		motherNum = b * y;
		sonNum = a * y + x * b;
		
		makeDevide(sonNum, motherNum);
	}
	else if (how == '-') {
		motherNum = b * y;
		sonNum = a * y - x * b;

		makeDevide(sonNum, motherNum);
	}
	else if (how == '/') { //a/b * y/x
		motherNum = b * x;
		sonNum = a * y;

		makeDevide(sonNum, motherNum);
	}
	else if (how == '*') {
		motherNum = b * y;
		sonNum = a * x;

		makeDevide(sonNum, motherNum);
	}
	return 0;
}