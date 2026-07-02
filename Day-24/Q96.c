// Write a program to Remove duplicate characters.

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000];
	char result[1000];
	int seen[256] = {0};
	int i, j = 0;

	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 0;
	}

	str[strcspn(str, "\n")] = '\0';

	for (i = 0; str[i] != '\0'; i++) {
		unsigned char ch = (unsigned char)str[i];

		if (!seen[ch]) {
			seen[ch] = 1;
			result[j++] = str[i];
		}
	}

	result[j] = '\0';

	printf("%s\n", result);
	return 0;
}