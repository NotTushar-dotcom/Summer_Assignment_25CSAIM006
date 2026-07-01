// Write a program to Find first nonrepeating character.

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000];
	int count[256] = {0};
	int i;

	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 0;
	}

	str[strcspn(str, "\n")] = '\0';

	for (i = 0; str[i] != '\0'; i++) {
		count[(unsigned char)str[i]]++;
	}

	for (i = 0; str[i] != '\0'; i++) {
		if (count[(unsigned char)str[i]] == 1) {
			printf("%c\n", str[i]);
			return 0;
		}
	}

	printf("No non-repeating character\n");
	return 0;
}