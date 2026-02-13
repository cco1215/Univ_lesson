#include <stdio.h>

int main() {
    int var = 10;
    int *ptr = &var;
    
    printf("var의 값: %d\n", var);
    printf("var의 주소: %d\n", &var);
    printf("ptr이 가르키는 주소: %p\n", ptr);
    printf("ptr을 통해 접근한 var의 값: %d\n", *ptr);

    return 0;
}