
/*

공백을 무시하고 대소문자를 구분하지 않고 앞에서 읽으나 뒤에서 읽으나 동일한 단어나 구

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int solution(char s[]) {
    // 코드 작성
    int i, size = 0, cnt = 0, j;
    char s1[50],s2[50];

    for (i = 0; ; i++) {
        if (s[i] == ' ') {
            cnt++;
            size++;
        }
        else if (s[i] != '\0')
            size++;
        else if (s[i] == '\0')
            break;
    }
    
    j = 0;
    for (i = 0; i < size; i++) {//소문자로만 구성된 함수로 바꾸기,
        if (s[i] != ' ') {
            if (isalpha(s[i]))
                s1[j] = tolower(s[i]);
            else
                s1[j] = s[i];
            j++;
        }
        else 
            continue;
    }
    s1[j] = '\0';
    for (i = 0; i < j; i++)//거꾸로 된 함수 만들기
        s2[j - 1 - i] = s1[i];
    s2[j] = '\0';

    for (i = 0; i < j; i++) 
        if (s1[i] != s2[i])
            return 0;

    return 1;
}
int main(void) {
    char s[50];

    gets(s);
    printf("%d\n",solution(s));
}