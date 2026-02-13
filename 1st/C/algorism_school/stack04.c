/*
##이 프로그램은 입력받은 문자열 (영문) 을 반대로 돌려서 출력하는 알고리즘이다.
하지만 방금 stack03.c 의 파일처럼 띄어쓰기를 포함하지 않아야하므로 [^\n]을 추가하여 띄어쓰기를 하더라도 역으로 돌리는 파일로 변환했다.
또한 띄어쓰기 또한 문자열이기 때문에 띄어쓰기를 입력한다면 띄어쓰기 또한 반대로 돌려서 출력해주는 알고리즘이다.
len을 이용하여 입력받은 문자열의 길이 만큼 반복하여 스택에 저장한 뒤에 차례대로 팝을 이용해 반대로 돌려준다.
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

void reverse_string(char* str) {
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];
    printf("문자열 입력: ");
    scanf_s("%[^\n]s", str);
    
    reverse_string(str);
    printf("뒤집힌 문자열: %s\n", str);
    
    return 0;
}
*/