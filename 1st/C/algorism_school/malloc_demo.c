#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("배열 크기 입력 : ");
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n); // 입력받은 값 만큼 배열의 크기를 할당
    if (arr == NULL) {
        printf("배열 크기가 없어진다. \n");
        return 1;
    }
    printf("%d개의 정수 입력 : \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("배열 :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}