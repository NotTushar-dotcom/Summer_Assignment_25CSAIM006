// Write a program to Find diagonal sum.

#include <stdio.h>

#define MAX 10

int main() {
	int n;
	int matrix[MAX][MAX];
	int diagonalSum = 0;

	printf("Enter order of square matrix: ");
	scanf("%d", &n);

	if (n <= 0 || n > MAX) {
		printf("Invalid Matrix size.\n");
		return 1;
	}

	printf("Enter elements of matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		diagonalSum += matrix[i][i];
		if (i != n - i - 1) {
			diagonalSum += matrix[i][n - i - 1];
		}
	}

	printf("Diagonal sum: %d\n", diagonalSum);

	return 0;
}