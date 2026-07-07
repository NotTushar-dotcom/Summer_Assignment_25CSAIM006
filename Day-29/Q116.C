// Write a program to Create inventory management system.

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

typedef struct
{
	int id;
	char name[NAME_LEN];
	int quantity;
	float price;
} Item;

void clearInputBuffer(void)
{
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
	}
}

int findItemById(Item inventory[], int itemCount, int id)
{
	int i;

	for (i = 0; i < itemCount; i++)
	{
		if (inventory[i].id == id)
		{
			return i;
		}
	}

	return -1;
}

void displayInventory(Item inventory[], int itemCount)
{
	int i;

	if (itemCount == 0)
	{
		printf("Inventory is empty.\n");
		return;
	}

	printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Qty", "Price");
	printf("------------------------------------------------------\n");
	for (i = 0; i < itemCount; i++)
	{
		printf("%-10d %-20s %-10d %-10.2f\n",
			   inventory[i].id,
			   inventory[i].name,
			   inventory[i].quantity,
			   inventory[i].price);
	}
}

int main(void)
{
	Item inventory[MAX_ITEMS];
	int itemCount = 0;
	int choice, id, quantity, index;
	float price;
	char name[NAME_LEN];

	while (1)
	{
		printf("\nInventory Management System\n");
		printf("1. Add item\n");
		printf("2. Display all items\n");
		printf("3. Search item by ID\n");
		printf("4. Update item quantity\n");
		printf("5. Delete item\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid input. Exiting.\n");
			return 1;
		}

		clearInputBuffer();

		switch (choice)
		{
			case 1:
				if (itemCount >= MAX_ITEMS)
				{
					printf("Inventory is full.\n");
					break;
				}

				printf("Enter item ID: ");
				if (scanf("%d", &id) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}
				clearInputBuffer();

				if (findItemById(inventory, itemCount, id) != -1)
				{
					printf("Item ID already exists.\n");
					break;
				}

				printf("Enter item name: ");
				if (fgets(name, sizeof(name), stdin) == NULL)
				{
					printf("Input error.\n");
					return 1;
				}
				name[strcspn(name, "\n")] = '\0';

				printf("Enter quantity: ");
				if (scanf("%d", &quantity) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				printf("Enter price: ");
				if (scanf("%f", &price) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				inventory[itemCount].id = id;
				strcpy(inventory[itemCount].name, name);
				inventory[itemCount].quantity = quantity;
				inventory[itemCount].price = price;
				itemCount++;

				printf("Item added successfully.\n");
				break;

			case 2:
				displayInventory(inventory, itemCount);
				break;

			case 3:
				printf("Enter item ID to search: ");
				if (scanf("%d", &id) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				index = findItemById(inventory, itemCount, id);
				if (index == -1)
				{
					printf("Item not found.\n");
				}
				else
				{
					printf("Item found:\n");
					printf("ID: %d\n", inventory[index].id);
					printf("Name: %s\n", inventory[index].name);
					printf("Quantity: %d\n", inventory[index].quantity);
					printf("Price: %.2f\n", inventory[index].price);
				}
				break;

			case 4:
				printf("Enter item ID to update: ");
				if (scanf("%d", &id) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				index = findItemById(inventory, itemCount, id);
				if (index == -1)
				{
					printf("Item not found.\n");
					break;
				}

				printf("Enter new quantity: ");
				if (scanf("%d", &quantity) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				inventory[index].quantity = quantity;
				printf("Quantity updated successfully.\n");
				break;

			case 5:
				printf("Enter item ID to delete: ");
				if (scanf("%d", &id) != 1)
				{
					printf("Invalid input. Exiting.\n");
					return 1;
				}

				index = findItemById(inventory, itemCount, id);
				if (index == -1)
				{
					printf("Item not found.\n");
					break;
				}

				for (int i = index; i < itemCount - 1; i++)
				{
					inventory[i] = inventory[i + 1];
				}
				itemCount--;
				printf("Item deleted successfully.\n");
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

