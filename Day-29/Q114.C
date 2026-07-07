// Write a program to Create menu-driven array operations system.

#include <stdio.h>

#define MAX 100

void displayArray(int arr[], int size)
{
	int i;

	if (size == 0)
	{
		printf("Array is empty.\n");
		return;
	}

	printf("Array elements: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sortArray(int arr[], int size)
{
	int i, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[MAX];
	int size = 0;
	int choice, value, position, i, found;

	while (1)
	{
		printf("\nMenu-Driven Array Operations\n");
		printf("1. Insert element\n");
		printf("2. Delete element by position\n");
		printf("3. Display array\n");
		printf("4. Search element\n");
		printf("5. Sort array\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid input. Exiting.\n");
			return 1;
		}

		switch (choice)
		{
			case 1:
				if (size >= MAX)
				{
					printf("Array is full.\n");
					break;
				}

				printf("Enter element to insert: ");
				if (scanf("%d", &value) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				arr[size++] = value;
				printf("Element inserted successfully.\n");
				break;

			case 2:
				if (size == 0)
				{
					printf("Array is empty.\n");
					break;
				}

				printf("Enter position to delete (1 to %d): ", size);
				if (scanf("%d", &position) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				if (position < 1 || position > size)
				{
					printf("Invalid position.\n");
					break;
				}

				for (i = position - 1; i < size - 1; i++)
				{
					arr[i] = arr[i + 1];
				}
				size--;
				printf("Element deleted successfully.\n");
				break;

			case 3:
				displayArray(arr, size);
				break;

			case 4:
				if (size == 0)
				{
					printf("Array is empty.\n");
					break;
				}

				printf("Enter element to search: ");
				if (scanf("%d", &value) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				found = 0;
				for (i = 0; i < size; i++)
				{
					if (arr[i] == value)
					{
						printf("Element found at position %d.\n", i + 1);
						found = 1;
						break;
					}
				}

				if (!found)
				{
					printf("Element not found.\n");
				}
				break;

			case 5:
				if (size == 0)
				{
					printf("Array is empty.\n");
					break;
				}

				sortArray(arr, size);
				printf("Array sorted successfully.\n");
				displayArray(arr, size);
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