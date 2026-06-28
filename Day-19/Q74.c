// Write a program to Subtract matrices.

#include <stdio.h>

#define MAX 10

int main() {
	int rows, cols;
	int first[MAX][MAX], second[MAX][MAX], difference[MAX][MAX];

	printf("Enter number of rows and columns: ");
	scanf("%d %d", &rows, &cols);

	if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
		printf("Invalid matrix size.\n");
		return 1;
	}

	printf("Enter elements of first matrix:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf("%d", &first[i][j]);
		}
	}

	printf("Enter elements of second matrix:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf("%d", &second[i][j]);
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			difference[i][j] = first[i][j] - second[i][j];
		}
	}

	printf("Difference of matrices:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", difference[i][j]);
		}
		printf("\n");
	}

	return 0;
}