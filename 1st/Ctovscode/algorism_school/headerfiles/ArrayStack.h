#pragma once
Element data[MAX_SIZE];
int top;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_stack() {
	top = -1;
}
int is_empty() {
	if (top == -1) return 1;
	else return 0;
}
int is_full() {
	return (top == (MAX_SIZE - 1));
}
void push(Element e) {
	if (is_full()) {
		error("오버플로우 에러");
	}
	else {
		data[++top] = e;
	}
}
Element pop() {
	if (is_empty()) {
		error("언더플로우 에러");
	} return data[top--];
}
Element peek() {
	if (is_empty()) {
		error("언더플로우 에러");
	} return data[top];
}