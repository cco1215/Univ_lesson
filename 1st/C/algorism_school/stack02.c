/*
##입력받은 문자열에 소괄호가 열리면 스택을 쌓고 닫히면 스택을 지운다.
만약 스택이 쌓여있는 상태로 입력하면 짝이 맞지 않다고 나오고 만약 스택이 없다면 짝이 맞다고 출력된다.
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int is_balanced(char* expr) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(') {
            push('(');
        } else if (expr[i] == ')') {
            if (pop() == -1) {
                return 0; // 짝이 맞지 않음
            }
        }
    }
    return top == -1;
}

int main() {
    char expr[MAX];
    printf("괄호 문자열 입력: ");
    scanf_s("%s", &expr);

    if (is_balanced(expr))
        printf("괄호 짝이 맞습니다.\n");
    else
        printf("괄호 짝이 맞지 않습니다.\n");

    return 0;
}
*/