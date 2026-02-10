#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int a = 10, b = 20;
    printf("교환전: x = %d, y = %d\n", a, b);
    swap(&a, &b);
    printf("교환후: x = %d, y = %d\n", a, b);
    return 0;
}