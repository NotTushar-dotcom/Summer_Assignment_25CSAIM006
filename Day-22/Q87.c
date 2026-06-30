// Write a program to Character frequency.

#include <stdio.h>

int main(void) {
	char str[200];
	int frequency[256] = {0};
	int i = 0;

	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);

	while (str[i] != '\0') {
		unsigned char ch = (unsigned char)str[i];

		if (ch != '\n') {
			frequency[ch]++;
		}

		i++;
	}

	printf("Character frequency:\n");
	for (i = 0; i < 256; i++) {
		if (frequency[i] > 0) {
			if (i == ' ') {
				printf("' ' : %d\n", frequency[i]);
			} else if (i == '\t') {
				printf("'\\t' : %d\n", frequency[i]);
			} else {
				printf("%c : %d\n", i, frequency[i]);
			}
		}
	}

	return 0;
}