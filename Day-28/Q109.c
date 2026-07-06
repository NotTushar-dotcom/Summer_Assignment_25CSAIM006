// Write a program to Create library management system.

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
	int id;
	char title[50];
	char author[50];
	int quantity;
} Book;

int findBookIndexById(Book books[], int count, int id) {
	for (int i = 0; i < count; i++) {
		if (books[i].id == id) {
			return i;
		}
	}
	return -1;
}

void readLine(char *buffer, int size) {
	fgets(buffer, size, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
}

void addBook(Book books[], int *count) {
	if (*count >= MAX_BOOKS) {
		printf("Library is full. Cannot add more books.\n");
		return;
	}

	int id;
	printf("Enter Book ID: ");
	scanf("%d", &id);
	getchar();

	if (findBookIndexById(books, *count, id) != -1) {
		printf("Book ID already exists.\n");
		return;
	}

	books[*count].id = id;

	printf("Enter Book Title: ");
	readLine(books[*count].title, sizeof(books[*count].title));

	printf("Enter Author Name: ");
	readLine(books[*count].author, sizeof(books[*count].author));

	printf("Enter Quantity: ");
	scanf("%d", &books[*count].quantity);
	getchar();

	(*count)++;
	printf("Book added successfully.\n");
}

void displayBooks(Book books[], int count) {
	if (count == 0) {
		printf("No books available.\n");
		return;
	}

	printf("\n%-8s %-25s %-25s %-10s\n", "ID", "Title", "Author", "Quantity");
	printf("--------------------------------------------------------------------------\n");
	for (int i = 0; i < count; i++) {
		printf("%-8d %-25s %-25s %-10d\n",
			   books[i].id,
			   books[i].title,
			   books[i].author,
			   books[i].quantity);
	}
}

void searchBook(Book books[], int count) {
	int id;
	printf("Enter Book ID to search: ");
	scanf("%d", &id);

	int index = findBookIndexById(books, count, id);
	if (index == -1) {
		printf("Book not found.\n");
		return;
	}

	printf("Book Found:\n");
	printf("ID: %d\n", books[index].id);
	printf("Title: %s\n", books[index].title);
	printf("Author: %s\n", books[index].author);
	printf("Quantity: %d\n", books[index].quantity);
}

void issueBook(Book books[], int count) {
	int id;
	printf("Enter Book ID to issue: ");
	scanf("%d", &id);

	int index = findBookIndexById(books, count, id);
	if (index == -1) {
		printf("Book not found.\n");
		return;
	}

	if (books[index].quantity <= 0) {
		printf("Book is not available for issue.\n");
		return;
	}

	books[index].quantity--;
	printf("Book issued successfully.\n");
}

void returnBook(Book books[], int count) {
	int id;
	printf("Enter Book ID to return: ");
	scanf("%d", &id);

	int index = findBookIndexById(books, count, id);
	if (index == -1) {
		printf("Book not found.\n");
		return;
	}

	books[index].quantity++;
	printf("Book returned successfully.\n");
}

int main() {
	Book books[MAX_BOOKS];
	int count = 0;
	int choice;

	do {
		printf("\nLibrary Management System\n");
		printf("1. Add Book\n");
		printf("2. Display All Books\n");
		printf("3. Search Book\n");
		printf("4. Issue Book\n");
		printf("5. Return Book\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				addBook(books, &count);
				break;
			case 2:
				displayBooks(books, count);
				break;
			case 3:
				searchBook(books, count);
				break;
			case 4:
				issueBook(books, count);
				break;
			case 5:
				returnBook(books, count);
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