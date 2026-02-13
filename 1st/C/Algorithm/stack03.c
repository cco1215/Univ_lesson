/*
##중위 표기식을 후위 표기식으로 바꾸는 알고리즘이다.
만약 입력받은 것이 숫자이면 출력을 하고 만약 연산자이면 마지막에 출력하는 것이다.
또한 곱셈이나 나눗셈이 있으면 그것을 먼저 처리하는 방식으로 출력한다.
하지만 교수님께서 주신 알고리즘으로 입력을 하면 띄어쓰기를 하지않고 해야하므로 띄어쓰기를 포함하여 입력하기 쉽게 [^\n]을 스캔에 추가했다.
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infix_to_postfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop(); // '(' 제거
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i]))
                printf("%c", pop());
            push(exp[i]);
        }
    }
    while (top != -1)
        printf("%c", pop());
    printf("\n");
}

int main() {
    char exp[MAX];
    printf("중위 표기식 입력: ");
    scanf_s("%[^\n]s", exp);
    printf("후위 표기식: ");
    infix_to_postfix(exp);
    return 0;
}
*/