/*#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct CallInfo {
	char name[32];
	int param;
};
typedef struct CallInfo Element;
#include "ArrayStack.h"

void main() {
	Element calls[4] = {
		{"main()"},
		{"factorial()", 3},
		{"factorial()", 2},
		{"factorial()", 1}
	};

	init_stack();
	for (int i = 0; i < 4; i++) {
		push(calls[i]);
		printf("\n%s %d\n", calls[i].name, calls[i].param);
	}

	while (!is_empty()) {
		Element call = pop();
		printf("\t%s %d\n", call.name, call.param);
	}
}*/