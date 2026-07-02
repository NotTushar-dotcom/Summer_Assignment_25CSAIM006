// Write a program to Compress a string. 

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000];
	char compressed[2000];
	int i = 0, j = 0;

	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 0;
	}

	str[strcspn(str, "\n")] = '\0';

	while (str[i] != '\0') {
		char current = str[i];
		int count = 1;

		while (str[i + 1] == current) {
			count++;
			i++;
		}

		compressed[j++] = current;

		if (count > 1) {
			j += sprintf(compressed + j, "%d", count);
		}

		i++;
	}

	compressed[j] = '\0';

	printf("%s\n", compressed);
	return 0;
}