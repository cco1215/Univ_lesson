#include <stdio.h>
#define min(a, b) a < b ? a : b

int arr[1000001];
int main() {
    int a;
    scanf("%d", &a);
    for (int i = 2; i <= a; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 3 ==0) {
            arr[i] = min(arr[i], arr[i / 3] + 1);
        }
        if (i % 2 == 0) {
            arr[i] = min(arr[i], arr[i / 2] + 1);
        }
    }
    printf("%d", arr[a]);
    return 0;
}