/*#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef int Element;
#include "ArrayStack.h"

void main() {
	int a;
	scanf_s("%d", &a);
	int A[100];
	for (int i = 0; i < a; i++) {
		scanf_s("%d", &A[i]);
	}
	init_stack();
	for (int i = 0; i < a; i++) {
		printf("%d", A[i]);
		push(A[i]);
	}
	for (int i = 0; i < a; i++) {
		printf("%d", pop());
	}
}*/