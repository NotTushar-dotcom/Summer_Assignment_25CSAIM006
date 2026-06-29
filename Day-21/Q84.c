// Write a program to Convert lowercase to uppercase.
#include <stdio.h>

int main(void) {
	char str[1000];
	int index;

	printf("Enter a string: ");
	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 1;
	}

	for (index = 0; str[index] != '\0'; index++) {
		if (str[index] >= 'a' && str[index] <= 'z') {
			str[index] = str[index] - ('a' - 'A');
		}
	}

	printf("Uppercase string: %s", str);
	return 0;
}

