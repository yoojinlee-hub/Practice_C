#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int N = 0; //단어의 개수
	int i, j, k, l;
	int count = 0, size, cnt = 0;
	int nums[26]; //알파벳의 개수
	char str[100], alpha[27];

	for (i = 0; i < 26; i++)
		alpha[i] = 'a' + i;
	alpha[26] = '\0';

	scanf("%d", &N);
	for (i = N; i > 0; i--) {
		scanf("%s", str);
		size = strlen(str);

		//초기화
		for (j = 0; j < 26; j++)
			nums[j] = 0;
		cnt = 0;
		/*같은 알파벳이 두 번 다시 나오면 안됨
		for (j = 0; j < 26; j++)
			for (k = 0; k < size; k++)
				if (str[k] == alpha[j])
					nums[k]++;//알파벳이 있다
		for (j = 0; j < 26; j++)
			if (nums[j] > 1)
				cnt = 1;
		if (!cnt)
			count++;
		*/

		//같은 알파벳이 연속해서 나오는 것은 됨, 나왔던 알파벳이 두 번 다시 나오면 안됨
		for (j = 0; j < 26; j++){
			for (k = 0; k < size; k++){
				if (str[k] == alpha[j]) {
					if (str[k] == str[k + 1]) 
						continue;
					nums[j]++;//알파벳이 있다
				}
			}
		}		
		for (l = 0; l < 26; l++)
			if (nums[l] > 1) 
				cnt += 1; //2이상이면 cnt값이 1
				
		if (!cnt) //cnt가 0
			count++;
	}
	printf("%d", count);
}