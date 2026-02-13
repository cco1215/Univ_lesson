#include <stdio.h>
#include <stdlib.h>
/*int main() {
	int a[6] = { 1, -2, 3,0,4,5 };
	int b[6] = { 4,6,8,1,-3,-7 };
	
	int c[6] = 2a - 3b;

	printf(c);
}*/

/*int main() {
	int A[2][3] = { {1,2,3},{4,5,6} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", A[i][j]);
		}
		printf("\n");
	}
}*/

/*int main() {
	int a[2][3] = { {1,2,3},{4,5,6} };
	int b[3][2] = { {-1,2},{2,-1},{4,3} };
	int c[2][2] = { 0 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				c[i][j] = a[j][k] * b[k][j];
			}
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}*/

/*typedef struct {
	char name[50];
	int age;
	int students_id;
	int average_score;
} Students;

int main() {
	Students students[3];
	
	for (int i = 0; i < 3; i++) {
		printf("Name:  ");
		scanf_s("%s", students[i].name);
		printf("Age:  ");
		scanf_s("%d", &students[i].age);
		printf("Stdents_id:  ");
		scanf_s("%d", &students[i].students_id);
		printf("Average_score:  ");
		scanf_s("%d", &students[i].average_score);
	}
	for (int i = 0; i < 3; i++) {
		printf("Name: %s\n", students[i].name);
		printf("Name: %d\n", students[i].age);
		printf("Name: %d\n", students[i].students_id);
		printf("Name: %.2f\n", students[i].average_score);
		printf("\n");
	}
}*/
