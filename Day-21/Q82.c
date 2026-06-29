// Write a program to Reverse a string.
#include <stdio.h>

int main(void) {
	char str[1000];
	int start = 0;
	int end;
	char temp;

	printf("Enter a string: ");
	if (fgets(str, sizeof(str), stdin) == NULL) {
		return 1;
	}

	for (end = 0; str[end] != '\0'; end++) {
		if (str[end] == '\n') {
			str[end] = '\0';
			break;
		}
	}

	end = 0;
	while (str[end] != '\0') {
		end++;
	}

	if (end > 0) {
		end--;
	}

	while (start < end) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	printf("Reversed string: %s\n", str);
	return 0;
}