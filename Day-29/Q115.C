// Write a program to Create menu-driven string operations system.

#include <stdio.h>
#include <string.h>

#define MAX 200

void removeNewline(char str[])
{
	str[strcspn(str, "\n")] = '\0';
}

void reverseString(char str[])
{
	int left = 0;
	int right = (int)strlen(str) - 1;
	char temp;

	while (left < right)
	{
		temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		left++;
		right--;
	}
}

int main(void)
{
	char str1[MAX], str2[MAX], result[MAX * 2];
	int choice;

	while (1)
	{
		printf("\nMenu-Driven String Operations\n");
		printf("1. Find length of a string\n");
		printf("2. Copy string\n");
		printf("3. Concatenate strings\n");
		printf("4. Compare strings\n");
		printf("5. Reverse a string\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid input. Exiting.\n");
			return 1;
		}

		getchar();

		switch (choice)
		{
			case 1:
				printf("Enter a string: ");
				if (fgets(str1, sizeof(str1), stdin) == NULL)
				{
					printf("Input error.\n");
					return 1;
				}
				removeNewline(str1);
				printf("Length of string: %zu\n", strlen(str1));
				break;

			case 2:
				printf("Enter a string: ");
				if (fgets(str1, sizeof(str1), stdin) == NULL)
				{
					printf("Input error.\n");
					return 1;
				}
				removeNewline(str1);
				strcpy(result, str1);
				printf("Copied string: %s\n", result);
				break;

			case 3:
				printf("Enter first string: ");
				if (fgets(str1, sizeof(str1), stdin) == NULL)
				{
					printf("Input error.\n");
					return 1;
				}
				removeNewline(str1);

				printf("Enter second string: ");
				if (fgets(str2, sizeof(str2), stdin) == NULL)
				{
					printf("Input error.\n");
					return 1;
				}
				removeNewline(str2);

				strcpy(result, str1);
				strcat(result, str2);
				printf("Concatenated string: %s\n", result);
				break;

			case 4:
				printf("Enter first string: ");
				if (fgets(str1, sizeof(str1), stdin) == NULL)
				{
					printf("Input error.\n");
					return 1;
				}
				removeNewline(str1);

				printf("Enter second string: ");
				if (fgets(str2, sizeof(str2), stdin) == NULL)
				{
					printf("Input error.\n");
					return 1;
				}
				removeNewline(str2);

				if (strcmp(str1, str2) == 0)
				{
					printf("Strings are equal.\n");
				}
				else if (strcmp(str1, str2) < 0)
				{
					printf("First string is smaller.\n");
				}
				else
				{
					printf("First string is greater.\n");
				}
				break;

			case 5:
				printf("Enter a string: ");
				if (fgets(str1, sizeof(str1), stdin) == NULL)
				{
					printf("Input error.\n");
					return 1;
				}
				removeNewline(str1);
				strcpy(result, str1);
				reverseString(result);
				printf("Reversed string: %s\n", result);
				break;

			case 6:
				printf("Exiting program.\n");
				return 0;

			default:
				printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}
