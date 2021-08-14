#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	int i, j;
	int triList[3];
	int best = 0, normal = 0, normal2 = 0;


	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		for (j = 0; j < 3; j++)
			scanf("%d", &triList[j]);
		//sort
		if (triList[0] >= triList[1] && triList[0] >= triList[2]) {
			best = triList[0];
			normal = triList[1];
			normal2 = triList[2];
		}
		else if (triList[2] >= triList[1] && triList[2] >= triList[0]) {
			best = triList[2];
			normal = triList[0];
			normal2 = triList[1];
		}
		else {
			best = triList[1];
			normal = triList[0];
			normal2 = triList[2];
		}
			
		
		//피타고라스
		if ((best * best) == (normal2*normal2) + (normal * normal))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}