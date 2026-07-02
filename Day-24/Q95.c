// Write a program to Find longest word. 

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000];
	char longest[1000] = "";
	int i = 0;
	int start = 0;
	int maxLen = 0;

	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 0;
	}

	str[strcspn(str, "\n")] = '\0';

	while (str[i] != '\0') {
		while (str[i] == ' ') {
			i++;
		}

		start = i;

		while (str[i] != '\0' && str[i] != ' ') {
			i++;
		}

		if (i - start > maxLen) {
			maxLen = i - start;
			strncpy(longest, str + start, maxLen);
			longest[maxLen] = '\0';
		}
	}

	printf("%s\n", longest);
	return 0;
}