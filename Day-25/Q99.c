// Write a program to Sort names alphabetically.

#include <stdio.h>
#include <string.h>

int main() {
	int n;

	printf("Enter number of names: ");
	scanf("%d", &n);

	char names[n][100];
	getchar();

	for (int i = 0; i < n; i++) {
		printf("Enter name %d: ", i + 1);
		fgets(names[i], sizeof(names[i]), stdin);
		names[i][strcspn(names[i], "\n")] = '\0';
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(names[i], names[j]) > 0) {
				char temp[100];
				strcpy(temp, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], temp);
			}
		}
	}

	printf("Names in alphabetical order:\n");
	for (int i = 0; i < n; i++) {
		printf("%s\n", names[i]);
	}

	return 0;
}

