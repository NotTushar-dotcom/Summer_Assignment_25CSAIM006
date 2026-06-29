// Write a program to Find string length without strlen().

#include <stdio.h>

int main(void) {
	char str[1000];
	int length = 0;

	printf("Enter a string: ");
	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 1;
	}

	while (str[length] != '\0' && str[length] != '\n') {
		length++;
	}

	printf("String length = %d\n", length);
	return 0;
}