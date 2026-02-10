/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef char Element;
#include "ArrayStack.h"

int precedence(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char expr[]) {
    init_stack();

    int i = 0;
    while (expr[i] != '\0') {
        char c = expr[i++];
        if ((c >= '0' && c <= '9')) {
            printf("%c ", c);
        }
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (is_empty() == 0) {
                char op = pop();
                if (op == '(') break;
                else printf("%c ", op);
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (is_empty() == 0) {
                char op = peek();
                if (precedence(c) <= precedence(op)) {
                    printf("%c ", op);
                    pop();
                }
                else break;
            }
            push(c);
        }
    }
    while (is_empty() == 0)
        printf("%c ", pop());
    printf("\n");
}


int main() {
    char expr[100];
    printf("중위식을 입력하세요: ");
    scanf_s("%[^\n]s", expr, 100);

    printf("중위수식: %s ==> 후위수식: ", expr);
    infix_to_postfix(expr);

    return 0;
}*/