#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("행과 열의 수 입력하세요. : ");
    scanf("%d %d", &rows, &cols);
    int **matrix = (int**)calloc(rows, sizeof(int*)); //입력 받은 수 만큼 매트릭스의 행 할당
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)calloc(cols, sizeof(int)); //입력 받은 수 만큼 메트릭스의 열 할당
    }
    printf("%d x %d 행렬의 요소 입력: \n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("메트릭스[%d][%d] 입력 : ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        int row_sum = 0;
        for (int j = 0; j < cols; j++) {
            row_sum += matrix[i][j];
        }
        printf("%d행의 값: %d \n", i + 1, row_sum);
    }
    for (int i = 0; i < cols; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}