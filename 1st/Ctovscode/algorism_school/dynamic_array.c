#include <stdio.h>
#include <stdlib.h>

void rand_array(int* A, int n) {
    for (int i =0; i < n; i++) {
        A[i] = rand() % 100;
    }
}
void print_array(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
double average(int* A, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return (double)sum / n;
}
void main() {
    int size;
    printf("배열의 크기: ");
    scanf("%d", &size);

    int* data = (int*)malloc(sizeof(int) * size);
    rand_array(data, size);
    print_array(data, size);
    double avg = average(data, size);
    printf("배열의 평균: %.2lf\n", avg);
    free(data);
}