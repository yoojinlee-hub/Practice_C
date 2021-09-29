#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(char* word) {
    int answer = 0;
    int i, temp = 0; //temp´Â ÀÚ¸´¼ö 
    int tens = 1; //tens = temp * 10
    int num = 0;

    //ex> 123
    for (i = 0; word[i] != '\0'; i++) {
        if (word[0] == 0);
        temp++; //3
    }
        

    for (i = temp; i > 0; i--)
        tens *= 10; //1000
    tens = tens / 10;
    for (i = 0; i <temp; i++) {
        num += (word[i]-'0') * tens;
        tens /= 10;
    }
    answer = num;
    return answer;
}
int main(void)
{
    char word[20];
    int answer;
    scanf("%s", word);
    answer = solution(word);
    printf("%d\n", answer);
}