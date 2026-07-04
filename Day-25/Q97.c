// Write a program to Merge two sorted arrays.

#include <stdio.h>

int main() {
	int n1, n2;

	printf("Enter the number of elements in first sorted array: ");
	scanf("%d", &n1);

	int a[n1];
	printf("Enter %d sorted elements of first array: ", n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d", &a[i]);
	}

	printf("Enter the number of elements in second sorted array: ");
	scanf("%d", &n2);

	int b[n2];
	printf("Enter %d sorted elements of second array: ", n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d", &b[i]);
	}

	int merged[n1 + n2];
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2) {
		if (a[i] <= b[j]) {
			merged[k++] = a[i++];
		} else {
			merged[k++] = b[j++];
		}
	}

	while (i < n1) {
		merged[k++] = a[i++];
	}

	while (j < n2) {
		merged[k++] = b[j++];
	}

	printf("Merged sorted array: ");
	for (int x = 0; x < n1 + n2; x++) {
		printf("%d ", merged[x]);
	}
	printf("\n");

	return 0;
}

