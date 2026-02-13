/*#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef double Element;
#include "ArrayStack.h"

double eval_postfix(char expr[]) {
	int i = 0;
	init_stack();
	while (expr[i] != '\0') {
		char c = expr[i++];
		if (c >= '0' && c <= '9') {
			double num = (double)c - '0';
			push(num);
		}
		else if (c =='+' || c == '-' || c == '*' || c== '/') {
			double val2 = pop();
			double val1 = pop();
			switch (c) {
			case '+': push(val1 + val2);
				break;
			case '-': push(val1 - val2);
				break;
			case '*': push(val1 * val2);
				break;
			case '/': push(val1 / val2);
				break;
			}
		}
	}
	return pop();
}

int main() {
	int a;
	char expr[100][100];
	printf("문제 수 :");
	scanf_s("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf_s("%s", expr[i], (unsigned)_countof(expr[i]));
	}
	for (int i = 0; i < a; i++) {
		printf("수식: %s = %lf\n", expr[i], eval_postfix(expr[i]));
	}
	return 0;
}*/