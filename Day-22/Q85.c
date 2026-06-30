// Write a program to Check palindrome String.

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];
	int left, right;
	int isPalindrome = 1;

	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);

	str[strcspn(str, "\n")] = '\0';

	left = 0;
	right = (int)strlen(str) - 1;

	while (left < right) {
		if (str[left] != str[right]) {
			isPalindrome = 0;
			break;
		}
		left++;
		right--;
	}

	if (isPalindrome) {
		printf("Palindrome string\n");
	} else {
		printf("Not a palindrome string\n");
	}

	return 0;
}
