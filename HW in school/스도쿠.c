#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void rowSort(int input[][9],int num) {
	int i, j;
	int minIndex = 0, temp = 0;
	for (i = 0; i < 8; i++) {
		minIndex = i;
		for (j = i + 1; j < 9; j++) 
			if (input[num][j] < input[num][minIndex])
				minIndex = j;
		temp = input[num][i];
		input[num][i] = input[num][minIndex];
		input[num][minIndex] = temp;
	}
}
void colSort(int input[][9], int num) {
	int i, j;
	int minIndex = 0, temp = 0;
	for (i = 0; i < 8; i++) {
		minIndex = i;
		for (j = i + 1; j < 9; j++)
			if (input[j][num] < input[minIndex][num])
				minIndex = j;
		temp = input[i][num];
		input[i][num] = input[minIndex][num];
		input[minIndex][num] = temp;
	}
}
int rowRight(int answer[9], int input[][9],int num) {
	int i;
	for (i = 0; i < 9; i++)
		if (answer[i] != input[num][i])
			return 0;
	return 1;
}
int colRight(int answer[9], int input[][9], int num) {
	int i;
	for (i = 0; i < 9; i++)
		if (answer[i] != input[i][num])
			return 0;
	return 1;
}
int right(int answer[9], int square[9]) {
	int i;
	for (i = 0; i < 9; i++)
		if (answer[i] != square[i])
			return 0;
	return 1;
}
void sort(int input[9]) {
	int i, j;
	int minIndex = 0, temp = 0;
	for (i = 0; i < 8; i++) {
		minIndex = i;
		for (j = i + 1; j < 9; j++)
			if (input[j] < input[minIndex])
				minIndex = j;
		temp = input[i];
		input[i] = input[minIndex];
		input[minIndex] = temp;
	}
}
int main(void) {
	int answer[9] = { 1,2,3,4,5,6,7,8,9 };
	int s1[9];
	int input[9][9], rowTemp[9][9],colTemp[9][9];
	int i, j;
	int sum = 0;
	int m = 0, n = 0, k = 0, p = 0;

	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			scanf("%d", &input[i][j]);
	
	//복사본 만들기 - row
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			rowTemp[i][j] = input[i][j];
	//복사본 만들기 - col
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			colTemp[i][j] = input[i][j];


	//맞는 숫자 세기- row
	for (i = 0; i < 9; i++) {
		rowSort(rowTemp, i);
		if (rowRight(answer, rowTemp, i) == 1)
			sum++;
	}
	//맞는 숫자 세기- col
	for (i = 0; i < 9; i++) {
		colSort(colTemp, i);
		if (colRight(answer, colTemp, i) == 1)
			sum++;
	}
	
	//사각형 세기
	while (m<5) {
		k = 0; n = p*3; 
		if (p % 3 == 0&& p !=0)m += 2;
		for (i = m; i <= m + 2;i++) 
			for (j = n; j <= n + 2; j++)
				s1[k++] = input[i][j];
		n += 1;
		sort(s1);
		if (right(answer, s1) == 1) sum++;
		p++;
	}

	if (sum == 27) printf("입력하신 스도쿠는 정답입니다.");
	else printf("입력하신 스도쿠는 오답입니다.");
}