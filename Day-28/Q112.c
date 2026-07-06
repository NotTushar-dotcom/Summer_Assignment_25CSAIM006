// Write a program to Create contact management system.

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
	int id;
	char name[50];
	char phone[20];
	char email[50];
} Contact;

int findContactIndex(Contact contacts[], int count, int id) {
	for (int i = 0; i < count; i++) {
		if (contacts[i].id == id) {
			return i;
		}
	}
	return -1;
}

void readLine(char *buffer, int size) {
	fgets(buffer, size, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
}

void clearInputBuffer(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
	}
}

void addContact(Contact contacts[], int *count) {
	if (*count >= MAX_CONTACTS) {
		printf("Contact list is full.\n");
		return;
	}

	int id;
	printf("Enter Contact ID: ");
	scanf("%d", &id);
	clearInputBuffer();

	if (findContactIndex(contacts, *count, id) != -1) {
		printf("Contact ID already exists.\n");
		return;
	}

	contacts[*count].id = id;

	printf("Enter Name: ");
	readLine(contacts[*count].name, sizeof(contacts[*count].name));

	printf("Enter Phone Number: ");
	readLine(contacts[*count].phone, sizeof(contacts[*count].phone));

	printf("Enter Email Address: ");
	readLine(contacts[*count].email, sizeof(contacts[*count].email));

	(*count)++;
	printf("Contact added successfully.\n");
}

void displayContacts(Contact contacts[], int count) {
	if (count == 0) {
		printf("No contacts available.\n");
		return;
	}

	printf("\n%-8s %-25s %-18s %-30s\n", "ID", "Name", "Phone", "Email");
	printf("--------------------------------------------------------------------------------\n");
	for (int i = 0; i < count; i++) {
		printf("%-8d %-25s %-18s %-30s\n",
		       contacts[i].id,
		       contacts[i].name,
		       contacts[i].phone,
		       contacts[i].email);
	}
}

void searchContact(Contact contacts[], int count) {
	int id;
	printf("Enter Contact ID to search: ");
	scanf("%d", &id);

	int index = findContactIndex(contacts, count, id);
	if (index == -1) {
		printf("Contact not found.\n");
		return;
	}

	printf("Contact Found:\n");
	printf("ID: %d\n", contacts[index].id);
	printf("Name: %s\n", contacts[index].name);
	printf("Phone: %s\n", contacts[index].phone);
	printf("Email: %s\n", contacts[index].email);
}

void updateContact(Contact contacts[], int count) {
	int id;
	printf("Enter Contact ID to update: ");
	scanf("%d", &id);
	clearInputBuffer();

	int index = findContactIndex(contacts, count, id);
	if (index == -1) {
		printf("Contact not found.\n");
		return;
	}

	printf("Enter New Name: ");
	readLine(contacts[index].name, sizeof(contacts[index].name));

	printf("Enter New Phone Number: ");
	readLine(contacts[index].phone, sizeof(contacts[index].phone));

	printf("Enter New Email Address: ");
	readLine(contacts[index].email, sizeof(contacts[index].email));

	printf("Contact updated successfully.\n");
}

void deleteContact(Contact contacts[], int *count) {
	int id;
	printf("Enter Contact ID to delete: ");
	scanf("%d", &id);

	int index = findContactIndex(contacts, *count, id);
	if (index == -1) {
		printf("Contact not found.\n");
		return;
	}

	for (int i = index; i < *count - 1; i++) {
		contacts[i] = contacts[i + 1];
	}

	(*count)--;
	printf("Contact deleted successfully.\n");
}

int main(void) {
	Contact contacts[MAX_CONTACTS];
	int count = 0;
	int choice;

	do {
		printf("\nContact Management System\n");
		printf("1. Add Contact\n");
		printf("2. Display All Contacts\n");
		printf("3. Search Contact\n");
		printf("4. Update Contact\n");
		printf("5. Delete Contact\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		clearInputBuffer();

		switch (choice) {
			case 1:
				addContact(contacts, &count);
				break;
			case 2:
				displayContacts(contacts, count);
				break;
			case 3:
				searchContact(contacts, count);
				break;
			case 4:
				updateContact(contacts, count);
				break;
			case 5:
				deleteContact(contacts, &count);
				break;
			case 6:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 6);

	return 0;
}