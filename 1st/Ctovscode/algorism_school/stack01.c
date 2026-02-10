/*
## push로 스택을 쌓은 뒤에 pop으로 위에 있는 스택을 지움
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1) {
        printf("스택 오버플로우!\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("스택 언더플로우!\n");
        return -1;
    }
    return stack[top--];
}

void print_stack() {
    if (top == -1) {
        printf("스택이 비어 있습니다.\n");
        return;
    }
    printf("스택 상태: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    print_stack();
    printf("pop: %d\n", pop());
    print_stack();
    return 0;
}
*/