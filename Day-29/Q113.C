// Write a program to Create menu-driven calculator.

#include <stdio.h>

int main(void)
{
	int choice;
	double num1, num2, result;

	while (1)
	{
		printf("\nMenu-Driven Calculator\n");
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid input. Exiting.\n");
			return 1;
		}

		if (choice == 5)
		{
			printf("Exiting calculator.\n");
			break;
		}

		printf("Enter first number: ");
		if (scanf("%lf", &num1) != 1)
		{
			printf("Invalid input. Exiting.\n");
			return 1;
		}

		printf("Enter second number: ");
		if (scanf("%lf", &num2) != 1)
		{
			printf("Invalid input. Exiting.\n");
			return 1;
		}

		switch (choice)
		{
			case 1:
				result = num1 + num2;
				printf("Result: %.2f\n", result);
				break;
			case 2:
				result = num1 - num2;
				printf("Result: %.2f\n", result);
				break;
			case 3:
				result = num1 * num2;
				printf("Result: %.2f\n", result);
				break;
			case 4:
				if (num2 == 0)
				{
					printf("Division by zero is not allowed.\n");
				}
				else
				{
					result = num1 / num2;
					printf("Result: %.2f\n", result);
				}
				break;
			default:
				printf("Invalid choice. Please select a valid option.\n");
		}
	}

	return 0;
}
