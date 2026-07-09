// Write a program to Develop complete mini project using arrays, strings and functions.

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 20
#define EMAIL_LEN 60

typedef struct {
	int id;
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char email[EMAIL_LEN];
	int active;
} Contact;

void remove_newline(char text[]) {
	size_t len = strlen(text);
	if (len > 0 && text[len - 1] == '\n') {
		text[len - 1] = '\0';
	}
}

void read_line(char buffer[], int size) {
	fgets(buffer, size, stdin);
	remove_newline(buffer);
}

int find_contact_index(Contact contacts[], int count, int id) {
	int i;
	for (i = 0; i < count; i++) {
		if (contacts[i].active && contacts[i].id == id) {
			return i;
		}
	}
	return -1;
}

void swap_contacts(Contact *a, Contact *b) {
	Contact temp = *a;
	*a = *b;
	*b = temp;
}

void add_contact(Contact contacts[], int *count) {
	Contact c;

	if (*count >= MAX_CONTACTS) {
		printf("\nContact list is full.\n");
		return;
	}

	printf("\nEnter Contact ID: ");
	scanf("%d", &c.id);
	getchar();

	if (find_contact_index(contacts, *count, c.id) != -1) {
		printf("Contact with ID %d already exists.\n", c.id);
		return;
	}

	printf("Enter Name: ");
	read_line(c.name, NAME_LEN);

	printf("Enter Phone: ");
	read_line(c.phone, PHONE_LEN);

	printf("Enter Email: ");
	read_line(c.email, EMAIL_LEN);

	c.active = 1;
	contacts[*count] = c;
	(*count)++;

	printf("Contact added successfully.\n");
}

void display_contacts(Contact contacts[], int count) {
	int i;
	int found = 0;

	printf("\n---------- Contact List ----------\n");
	for (i = 0; i < count; i++) {
		if (contacts[i].active) {
			found = 1;
			printf("ID: %d\n", contacts[i].id);
			printf("Name: %s\n", contacts[i].name);
			printf("Phone: %s\n", contacts[i].phone);
			printf("Email: %s\n", contacts[i].email);
			printf("----------------------------------\n");
		}
	}

	if (!found) {
		printf("No contacts available.\n");
	}
}

void search_contact(Contact contacts[], int count) {
	int id;
	int index;

	printf("\nEnter Contact ID to search: ");
	scanf("%d", &id);
	getchar();

	index = find_contact_index(contacts, count, id);
	if (index == -1) {
		printf("Contact not found.\n");
		return;
	}

	printf("\nContact Found:\n");
	printf("ID: %d\n", contacts[index].id);
	printf("Name: %s\n", contacts[index].name);
	printf("Phone: %s\n", contacts[index].phone);
	printf("Email: %s\n", contacts[index].email);
}

void update_contact(Contact contacts[], int count) {
	int id;
	int index;

	printf("\nEnter Contact ID to update: ");
	scanf("%d", &id);
	getchar();

	index = find_contact_index(contacts, count, id);
	if (index == -1) {
		printf("Contact not found.\n");
		return;
	}

	printf("Enter new Name: ");
	read_line(contacts[index].name, NAME_LEN);

	printf("Enter new Phone: ");
	read_line(contacts[index].phone, PHONE_LEN);

	printf("Enter new Email: ");
	read_line(contacts[index].email, EMAIL_LEN);

	printf("Contact updated successfully.\n");
}

void delete_contact(Contact contacts[], int count) {
	int id;
	int index;

	printf("\nEnter Contact ID to delete: ");
	scanf("%d", &id);
	getchar();

	index = find_contact_index(contacts, count, id);
	if (index == -1) {
		printf("Contact not found.\n");
		return;
	}

	contacts[index].active = 0;
	printf("Contact deleted successfully.\n");
}

void sort_contacts_by_name(Contact contacts[], int count) {
	int i;
	int j;

	for (i = 0; i < count - 1; i++) {
		for (j = i + 1; j < count; j++) {
			if (contacts[i].active && contacts[j].active && strcmp(contacts[i].name, contacts[j].name) > 0) {
				swap_contacts(&contacts[i], &contacts[j]);
			}
		}
	}

	printf("Contacts sorted by name successfully.\n");
}

int main() {
	Contact contacts[MAX_CONTACTS];
	int count = 0;
	int choice;

	do {
		printf("\n===== Mini Contact Management System =====\n");
		printf("1. Add Contact\n");
		printf("2. Display All Contacts\n");
		printf("3. Search Contact by ID\n");
		printf("4. Update Contact\n");
		printf("5. Delete Contact\n");
		printf("6. Sort Contacts by Name\n");
		printf("7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();

		switch (choice) {
			case 1:
				add_contact(contacts, &count);
				break;
			case 2:
				display_contacts(contacts, count);
				break;
			case 3:
				search_contact(contacts, count);
				break;
			case 4:
				update_contact(contacts, count);
				break;
			case 5:
				delete_contact(contacts, count);
				break;
			case 6:
				sort_contacts_by_name(contacts, count);
				break;
			case 7:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 7);

	return 0;
}

