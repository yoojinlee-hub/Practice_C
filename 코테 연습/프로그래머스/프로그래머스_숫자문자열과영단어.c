#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int num = 0;
    char input[50] = "";
    char answer[50] = { " " };
    int i, size = 0;

    strcpy(input, s);
    for (i = 0; i < strlen(input); i++) {
        if (input[i] >= 48 && input[i] <= 57) {
            size = strlen(answer);
            answer[size] = input[i];
        }  
        else if (input[i] == 'z') {
            strcat(answer, "0");
            i += 3;
        }
        else if (input[i] == 'o') {
            strcat(answer, "1");
            i += 2;
        }
        else if (input[i] == 't') {
            if (input[i + 1] == 'w') {
                strcat(answer, "2");
                i += 2;
            }
            else if (input[i + 1] == 'h') {
                strcat(answer, "3");
                i +=4;
            }
        }
        else if (input[i] == 'f') {
            if (input[i + 1] == 'o') {
                strcat(answer, "4");
                i += 3;
            }
            else if (input[i + 1] == 'i') {
                strcat(answer, "5");
                i += 3;
            }
        }
        else if (input[i] == 's') {
            if (input[i + 1] == 'i') {
                strcat(answer, "6");
                i += 2;
            }
            else if (input[i + 1] == 'e') {
                strcat(answer, "7");
                i += 4;
            }
        }
        else if (input[i] == 'e') {
            strcat(answer, "8");
            i += 4;
        }
        else if (input[i] == 'n') {
            strcat(answer, "9");
            i += 3;
        }
    }
    size = strlen(answer);
    answer[size] = '\0';
    num = atoi(answer);
    return num;
}
int main(void) {
    char s[10] = "";
    strcpy(s, "one4seveneight");
    solution(s);
}