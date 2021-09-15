#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int arr1[2][4] = { 1,2,3,4,5,6,7,8 };
	int arr2[4][2];
	int arr3[8];
	int i, j;

	/*이동(복사) A -> B */
	for (i = 0; i < 4; i++)
		for (j = 0; j < 2; j++)
			arr2[i][j] = arr1[j][i];

	/*이동(복사) A -> C */
	for (i = 0; i < 4; i++)
		arr3[i] = arr1[0][i];
	for (i = 4; i < 8; i++)
		arr3[i] = arr1[1][i - 4];

	/*A,B,C 출력*/
	printf("--배열 A \n");
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++) {
			if (j == 3)
				printf("%2d\n", arr1[i][j]);
			else
				printf("%2d", arr1[i][j]);
		}
			

	printf("--배열 B \n");
	for(i=0;i<4;i++)
		for (j = 0; j < 2; j++) {
			if (j == 1)
				printf("%2d\n", arr2[i][j]);
			else
				printf("%2d", arr2[i][j]);
		}

	printf("--배열 C\n");
	for (i = 0; i < 8; i++)
		printf("%2d", arr3[i]);
	printf("\n");
}