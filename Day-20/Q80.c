#include <stdio.h>

int main(void) {
	int rows, cols, i, j;
	int matrix[10][10];

	printf("Enter the number of rows and columns: ");
	if (scanf("%d %d", &rows, &cols) != 2) {
		return 1;
	}

	printf("Enter matrix elements:\n");
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("Column-wise sums:\n");
	for (j = 0; j < cols; j++) {
		int sum = 0;
		for (i = 0; i < rows; i++) {
			sum += matrix[i][j];
		}
		printf("Column %d: %d\n", j + 1, sum);
	}

	return 0;
}
