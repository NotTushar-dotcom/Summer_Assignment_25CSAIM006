// Write a program to Check anagram strings.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalize(char source[], char target[]) {
	int i, j = 0;

	for (i = 0; source[i] != '\0'; i++) {
		if (isalnum((unsigned char)source[i])) {
			target[j++] = (char)tolower((unsigned char)source[i]);
		}
	}
	target[j] = '\0';
}

int main(void) {
	char first[1000], second[1000];
	char normalizedFirst[1000], normalizedSecond[1000];
	int count[256] = {0};
	int i;

	if (fgets(first, sizeof(first), stdin) == NULL) {
		return 0;
	}
	if (fgets(second, sizeof(second), stdin) == NULL) {
		return 0;
	}

	first[strcspn(first, "\n")] = '\0';
	second[strcspn(second, "\n")] = '\0';

	normalize(first, normalizedFirst);
	normalize(second, normalizedSecond);

	if (strlen(normalizedFirst) != strlen(normalizedSecond)) {
		printf("Not Anagram\n");
		return 0;
	}

	for (i = 0; normalizedFirst[i] != '\0'; i++) {
		count[(unsigned char)normalizedFirst[i]]++;
	}

	for (i = 0; normalizedSecond[i] != '\0'; i++) {
		count[(unsigned char)normalizedSecond[i]]--;
	}

	for (i = 0; i < 256; i++) {
		if (count[i] != 0) {
			printf("Not Anagram\n");
			return 0;
		}
	}

	printf("Anagram\n");
	return 0;
}
