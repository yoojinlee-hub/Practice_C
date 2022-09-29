#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void findingPathinFantasia(int* input, int* left, int* right) {
	int temp[2] = { left[0] + right[0],left[1] + right[1] };
	double d1 = 0, d2 = 0; //divided

	while (temp[0] != input[0] && temp[1] != input[1]) {
		d1 = (double)temp[0] / (double)temp[1];
		d2 = (double)input[0] / (double)input[1];
		if (d1 > d2) {
			printf("L");
			right[0] = temp[0];
			right[1] = temp[1];
			temp[0] = left[0] + temp[0];
			temp[1] = left[1] + temp[1];
			//left[0] = temp[0];
			//left[1] = temp[1];
		}
		else if (d1 < d2) {
			printf("R");
			left[0] = temp[0];
			left[1] = temp[1];
			temp[0] = right[0] + temp[0];
			temp[1] = right[1] + temp[1];
			//right[0] = temp[0];
			//right[1] = temp[1];
		}
	}
}
int main(void) {
	int s, m; //son(분자), mom(분모)
	int input[2], left[2] = { 0,1 }, right[2] = { 1,0 };
	
	scanf("%d %d", &s, &m);
	input[0] = s;
	input[1] = m;

	findingPathinFantasia(input, left, right);
}