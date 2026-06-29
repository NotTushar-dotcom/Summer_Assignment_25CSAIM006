// Write a program to Count vowels and consonants.
#include <stdio.h>

int main(void) {
	char str[1000];
	int vowels = 0;
	int consonants = 0;
	int index;

	printf("Enter a string: ");
	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 1;
	}

	for (index = 0; str[index] != '\0'; index++) {
		char ch = str[index];

		if (ch >= 'A' && ch <= 'Z') {
			ch = ch - ('A' - 'a');
		}

		if (ch >= 'a' && ch <= 'z') {
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				vowels++;
			} else {
				consonants++;
			}
		}
	}

	printf("Vowels = %d\n", vowels);
	printf("Consonants = %d\n", consonants);
	return 0;
}