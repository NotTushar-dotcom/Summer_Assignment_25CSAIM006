// Write a program to Create mini library system.

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 60
#define AUTHOR_LEN 40

typedef struct {
	int id;
	char title[TITLE_LEN];
	char author[AUTHOR_LEN];
	int quantity;
	int active;
} Book;

void trim_newline(char text[]) {
	size_t len = strlen(text);
	if (len > 0 && text[len - 1] == '\n') {
		text[len - 1] = '\0';
	}
}

int find_book_index(Book books[], int count, int id) {
	int i;
	for (i = 0; i < count; i++) {
		if (books[i].active && books[i].id == id) {
			return i;
		}
	}
	return -1;
}

void add_book(Book books[], int *count) {
	Book b;

	if (*count >= MAX_BOOKS) {
		printf("\nLibrary is full. Cannot add more books.\n");
		return;
	}

	printf("\nEnter Book ID: ");
	scanf("%d", &b.id);
	getchar();

	if (find_book_index(books, *count, b.id) != -1) {
		printf("Book with ID %d already exists.\n", b.id);
		return;
	}

	printf("Enter Title: ");
	fgets(b.title, TITLE_LEN, stdin);
	trim_newline(b.title);

	printf("Enter Author: ");
	fgets(b.author, AUTHOR_LEN, stdin);
	trim_newline(b.author);

	printf("Enter Quantity: ");
	scanf("%d", &b.quantity);
	getchar();

	if (b.quantity < 0) {
		b.quantity = 0;
	}

	b.active = 1;
	books[*count] = b;
	(*count)++;

	printf("Book added successfully.\n");
}

void display_books(Book books[], int count) {
	int i;
	int found = 0;

	printf("\n------ Library Books ------\n");
	for (i = 0; i < count; i++) {
		if (books[i].active) {
			found = 1;
			printf("ID: %d\n", books[i].id);
			printf("Title: %s\n", books[i].title);
			printf("Author: %s\n", books[i].author);
			printf("Available Copies: %d\n", books[i].quantity);
			printf("---------------------------\n");
		}
	}

	if (!found) {
		printf("No books found in library.\n");
	}
}

void search_book(Book books[], int count) {
	int id;
	int index;

	printf("\nEnter Book ID to search: ");
	scanf("%d", &id);
	getchar();

	index = find_book_index(books, count, id);
	if (index == -1) {
		printf("Book not found.\n");
		return;
	}

	printf("\nBook Found:\n");
	printf("ID: %d\n", books[index].id);
	printf("Title: %s\n", books[index].title);
	printf("Author: %s\n", books[index].author);
	printf("Available Copies: %d\n", books[index].quantity);
}

void issue_book(Book books[], int count) {
	int id;
	int index;

	printf("\nEnter Book ID to issue: ");
	scanf("%d", &id);
	getchar();

	index = find_book_index(books, count, id);
	if (index == -1) {
		printf("Book not found.\n");
		return;
	}

	if (books[index].quantity <= 0) {
		printf("No copies available to issue.\n");
		return;
	}

	books[index].quantity--;
	printf("Book issued successfully.\n");
}

void return_book(Book books[], int count) {
	int id;
	int index;

	printf("\nEnter Book ID to return: ");
	scanf("%d", &id);
	getchar();

	index = find_book_index(books, count, id);
	if (index == -1) {
		printf("Book not found.\n");
		return;
	}

	books[index].quantity++;
	printf("Book returned successfully.\n");
}

void remove_book(Book books[], int count) {
	int id;
	int index;

	printf("\nEnter Book ID to remove: ");
	scanf("%d", &id);
	getchar();

	index = find_book_index(books, count, id);
	if (index == -1) {
		printf("Book not found.\n");
		return;
	}

	books[index].active = 0;
	printf("Book removed successfully.\n");
}

int main() {
	Book books[MAX_BOOKS];
	int count = 0;
	int choice;

	do {
		printf("\n===== Mini Library System =====\n");
		printf("1. Add Book\n");
		printf("2. Display All Books\n");
		printf("3. Search Book by ID\n");
		printf("4. Issue Book\n");
		printf("5. Return Book\n");
		printf("6. Remove Book\n");
		printf("7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();

		switch (choice) {
			case 1:
				add_book(books, &count);
				break;
			case 2:
				display_books(books, count);
				break;
			case 3:
				search_book(books, count);
				break;
			case 4:
				issue_book(books, count);
				break;
			case 5:
				return_book(books, count);
				break;
			case 6:
				remove_book(books, count);
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