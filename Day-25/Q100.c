// Write a program to Sort words by length.

#include <stdio.h>
#include <string.h>

int main() {
	char text[500];
	char words[100][50];
	int count = 0;

	printf("Enter a sentence: ");
	fgets(text, sizeof(text), stdin);

	text[strcspn(text, "\n")] = '\0';

	char *token = strtok(text, " ");
	while (token != NULL && count < 100) {
		strcpy(words[count++], token);
		token = strtok(NULL, " ");
	}

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strlen(words[i]) > strlen(words[j])) {
				char temp[50];
				strcpy(temp, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], temp);
			}
		}
	}

	printf("Words sorted by length:\n");
	for (int i = 0; i < count; i++) {
		printf("%s\n", words[i]);
	}

	return 0;
}