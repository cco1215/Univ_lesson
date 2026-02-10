/*#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char Element;
#include "ArrayStack.h"

int checking_matching(char expr[]) {
	int i = 0, prev;

	init_stack();
	while (expr[i] != '\0') {
		char ch = expr[i++];
		if (ch == '[' || ch == '(' || ch == '{') {
			push(ch);
		}
		else if (ch == ']' || ch == ')' || ch == '}') {
			if (is_empty()) {
				return 2;
			}	
			prev = pop();
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) {
				return 3;
			}
		}
		if (!is_empty()) {
			return 0;
		}
	}
}

void main() {
	char a[1][80] = 0;
	scanf_s(%c, a[i])
}*/