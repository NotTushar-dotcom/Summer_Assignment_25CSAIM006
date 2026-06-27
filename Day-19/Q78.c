#include <stdio.h>

int main(void) {
	int n, i, j;
	int matrix[10][10];
	int isSymmetric = 1;

	printf("Enter the order of the square matrix: ");
	if (scanf("%d", &n) != 1) {
		return 1;
	}

	printf("Enter matrix elements:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	for (i = 0; i < n && isSymmetric; i++) {
		for (j = i + 1; j < n; j++) {
			if (matrix[i][j] != matrix[j][i]) {
				isSymmetric = 0;
				break;
			}
		}
	}

	if (isSymmetric) {
		printf("The matrix is symmetric.\n");
	} else {
		printf("The matrix is not symmetric.\n");
	}

	return 0;
}
