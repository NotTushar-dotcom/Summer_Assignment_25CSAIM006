// Write a program to Count words in a sentence.

#include <stdio.h>
#include <ctype.h>

int main(void) {
	char sentence[200];
	int words = 0;
	int inWord = 0;
	int i = 0;

	printf("Enter a sentence: ");
	fgets(sentence, sizeof(sentence), stdin);

	while (sentence[i] != '\0') {
		if (isspace((unsigned char)sentence[i])) {
			inWord = 0;
		} else if (!inWord) {
			words++;
			inWord = 1;
		}
		i++;
	}

	printf("Number of words: %d\n", words);
	return 0;
}

