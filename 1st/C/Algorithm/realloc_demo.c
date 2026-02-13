#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr = NULL;
    int count = 0;
    int input;
    printf("정수를 입력하세요. (-1을 입력시 종료) :\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        int *temp = (int*)realloc(arr, (count + 1) * sizeof(int)); //할당되어있는 배열의 크기를 카운터 만큼 늘리며 정수를 삽입
        if (temp == NULL) {
            printf("메모리 재할당 실패\n");
            free(arr);
            return 1;
        }
        arr = temp;
        arr[count++] = input;
        count++;
    }
    printf("입력한 배열: \n");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}