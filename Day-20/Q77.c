#include <stdio.h>

int main(void) {
	int rows1, cols1, rows2, cols2;
	int i, j, k;
	int a[10][10], b[10][10], result[10][10] = {0};

	printf("Enter rows and columns of first matrix: ");
	if (scanf("%d %d", &rows1, &cols1) != 2) {
		return 1;
	}

	printf("Enter rows and columns of second matrix: ");
	if (scanf("%d %d", &rows2, &cols2) != 2) {
		return 1;
	}

	if (cols1 != rows2) {
		printf("Matrix multiplication not possible.\n");
		return 0;
	}

	printf("Enter elements of first matrix:\n");
	for (i = 0; i < rows1; i++) {
		for (j = 0; j < cols1; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("Enter elements of second matrix:\n");
	for (i = 0; i < rows2; i++) {
		for (j = 0; j < cols2; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	for (i = 0; i < rows1; i++) {
		for (j = 0; j < cols2; j++) {
			for (k = 0; k < cols1; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	printf("Product matrix:\n");
	for (i = 0; i < rows1; i++) {
		for (j = 0; j < cols2; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}