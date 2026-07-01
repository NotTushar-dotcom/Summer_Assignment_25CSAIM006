// Write a program to Find maximum occurring character.

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000];
	int count[256] = {0};
	int i;
	unsigned char maxChar = 0;
	int maxCount = 0;

	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 0;
	}

	str[strcspn(str, "\n")] = '\0';

	for (i = 0; str[i] != '\0'; i++) {
		count[(unsigned char)str[i]]++;
	}

	for (i = 0; i < 256; i++) {
		if (count[i] > maxCount) {
			maxCount = count[i];
			maxChar = (unsigned char)i;
		}
	}

	if (maxCount > 0) {
		printf("%c\n", maxChar);
	}

	return 0;
}
