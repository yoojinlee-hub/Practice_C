#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
전체 종이가 모두 같은 색으로 칠해져 있지 않으면 가로와 세로로 중간 부분을 잘라서 
<그림 2>의 I, II, III, IV와 같이 똑같은 크기의 네 개의 N/2 × N/2색종이로 나눈다.
나누어진 종이 I, II, III, IV 각각에 대해서도 앞에서와 마찬가지로 모두 같은 색으로 칠해져 있지 않으면 같은 방법으로 똑같은 크기의 네 개의 색종이로 나눈다. 
이와 같은 과정을 잘라진 종이가 모두 하얀색(0) 또는 모두 파란색(1)으로 칠해져 있거나, 
하나의 정사각형 칸이 되어 더 이상 자를 수 없을 때까지 반복한다.
*/

int sameColor(int i, int j, int len) {
	if (len == 1)return 1;

	int temp=
}
int main(void) {
	int paper[128][128];
	int n, m, i, j;
	int zeros = 0, ones = 0;
	scanf("%d", &n); //한 변의 길이 //2, 4, 8, 16, 32, 64, 128 중 하나
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", paper[i][j]);

	//한 변의 크기를 넘으면 값이 2
	if (n < 128) {
		for (i = n; i < 128; i++)
			for (j = n; j < 128; j++)
				paper[i][j] = 2;
	}
	//종이 자르기
	m = n;
	while (m > 1) {
		m /= 2;
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				if(paper[i][j]!=paper[i+1][j])

	}
}