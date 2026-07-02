// Write a program to Check string rotation. 

#include <stdio.h>
#include <string.h>

int main(void) {
	char str1[1000], str2[1000], combined[2000];
	int len1, len2;

	if (fgets(str1, sizeof(str1), stdin) == NULL) {
		return 0;
	}
	if (fgets(str2, sizeof(str2), stdin) == NULL) {
		return 0;
	}

	str1[strcspn(str1, "\n")] = '\0';
	str2[strcspn(str2, "\n")] = '\0';

	len1 = strlen(str1);
	len2 = strlen(str2);

	if (len1 != len2) {
		printf("No\n");
		return 0;
	}

	strcpy(combined, str1);
	strcat(combined, str1);

	if (strstr(combined, str2) != NULL) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}