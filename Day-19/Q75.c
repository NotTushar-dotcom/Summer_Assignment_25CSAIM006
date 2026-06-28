// Write a program to Transpose matrix.

#include <stdio.h>

#define MAX 10

int main() {
	int rows, cols;
	int matrix[MAX][MAX], transpose[MAX][MAX];

	printf("Enter number of rows and columns: ");
	scanf("%d %d", &rows, &cols);

	if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
		printf("Invalid matrix size.\n");
		return 1;
	}

	printf("Enter elements of matrix:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transpose[j][i] = matrix[i][j];
		}
	}

	printf("Transpose of matrix:\n");
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			printf("%d ", transpose[i][j]);
		}
		printf("\n");
	}

	return 0;
}