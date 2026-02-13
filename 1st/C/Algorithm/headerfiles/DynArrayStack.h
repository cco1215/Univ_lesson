#pragma once
int MAX_SIZE = 10;
Element* data = NULL;
int top;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

int is_empty() {
	return (top == -1);
}


int is_full() {
	return (top == (MAX_SIZE - 1));
}

Element pop() {
	if (is_empty()) {
		error("언더플로우 에러");
	}
	return data[top--];
}

Element peek() {
	if (is_empty()) {
		error("언더플로우 에러");
	}
	return data[top];
}

void init_stack() {
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
	if (data == NULL) {
            error("메모리 재할당 실패");
    }
    top = -1;
}

void push(Element e) {
    if (is_full()) {
        MAX_SIZE *= 2;
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
		if (data == NULL) {
            error("메모리 재할당 실패");
        }
        printf("realloc(%d)\n", MAX_SIZE);
    }
    data[++top] = e;
}
