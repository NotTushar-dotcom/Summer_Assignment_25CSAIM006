// Write a program to Remove spaces from string

#include <stdio.h>

int main(void) {
	char str[200];
	int i = 0, j = 0;

	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);

	while (str[i] != '\0') {
		if (str[i] != ' ' && str[i] != '\n') {
			str[j++] = str[i];
		}
		i++;
	}

	str[j] = '\0';

	printf("String without spaces: %s\n", str);
	return 0;
}