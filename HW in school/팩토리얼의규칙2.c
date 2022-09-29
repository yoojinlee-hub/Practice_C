#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//https://post.naver.com/viewer/postView.nhn?volumeNo=27799204
int main(void) {
	int n, count = 0;
	int fives[200];
	int i;
	scanf("%d", &n);

	for (i = 0; i < 200; i++) {
		fives[i] = 5 * (i + 1);
		if (fives[i] <= n) {
			if (fives[i] % 625 == 0) {
				count += 4;
				continue;
			}
			if (fives[i] % 125 == 0) {
				count += 3;
				continue;
			}	
			if (fives[i] % 25 == 0)
				count += 2;
			else count += 1;
		}
		if (fives[i] > n) break;
	}
		
	printf("%d", count);
}