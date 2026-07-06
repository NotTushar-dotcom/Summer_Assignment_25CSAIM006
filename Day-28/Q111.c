// Write a program to Create ticket booking system.

#include <stdio.h>
#include <string.h>

#define MAX_TICKETS 100

typedef struct {
	int ticketId;
	char passengerName[50];
	char source[30];
	char destination[30];
	int seats;
	int booked;
} Ticket;

int findTicketIndex(Ticket tickets[], int count, int ticketId) {
	for (int i = 0; i < count; i++) {
		if (tickets[i].ticketId == ticketId) {
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

void bookTicket(Ticket tickets[], int *count) {
	if (*count >= MAX_TICKETS) {
		printf("Ticket list is full.\n");
		return;
	}

	int ticketId;
	printf("Enter Ticket ID: ");
	scanf("%d", &ticketId);
	clearInputBuffer();

	if (findTicketIndex(tickets, *count, ticketId) != -1) {
		printf("Ticket ID already exists.\n");
		return;
	}

	tickets[*count].ticketId = ticketId;

	printf("Enter Passenger Name: ");
	readLine(tickets[*count].passengerName, sizeof(tickets[*count].passengerName));

	printf("Enter Source: ");
	readLine(tickets[*count].source, sizeof(tickets[*count].source));

	printf("Enter Destination: ");
	readLine(tickets[*count].destination, sizeof(tickets[*count].destination));

	printf("Enter Number of Seats: ");
	scanf("%d", &tickets[*count].seats);
	clearInputBuffer();

	if (tickets[*count].seats <= 0) {
		printf("Invalid number of seats.\n");
		return;
	}

	tickets[*count].booked = 1;
	(*count)++;

	printf("Ticket booked successfully.\n");
}

void displayTickets(Ticket tickets[], int count) {
	if (count == 0) {
		printf("No tickets booked.\n");
		return;
	}

	printf("\n%-10s %-25s %-15s %-15s %-10s\n", "Ticket ID", "Passenger Name", "Source", "Destination", "Seats");
	printf("-------------------------------------------------------------------------------\n");
	for (int i = 0; i < count; i++) {
		if (tickets[i].booked) {
			printf("%-10d %-25s %-15s %-15s %-10d\n",
			       tickets[i].ticketId,
			       tickets[i].passengerName,
			       tickets[i].source,
			       tickets[i].destination,
			       tickets[i].seats);
		}
	}
}

void searchTicket(Ticket tickets[], int count) {
	int ticketId;
	printf("Enter Ticket ID to search: ");
	scanf("%d", &ticketId);

	int index = findTicketIndex(tickets, count, ticketId);
	if (index == -1 || !tickets[index].booked) {
		printf("Ticket not found.\n");
		return;
	}

	printf("Ticket Found:\n");
	printf("Ticket ID: %d\n", tickets[index].ticketId);
	printf("Passenger Name: %s\n", tickets[index].passengerName);
	printf("Source: %s\n", tickets[index].source);
	printf("Destination: %s\n", tickets[index].destination);
	printf("Seats: %d\n", tickets[index].seats);
}

void cancelTicket(Ticket tickets[], int count) {
	int ticketId;
	printf("Enter Ticket ID to cancel: ");
	scanf("%d", &ticketId);

	int index = findTicketIndex(tickets, count, ticketId);
	if (index == -1 || !tickets[index].booked) {
		printf("Ticket not found.\n");
		return;
	}

	tickets[index].booked = 0;
	tickets[index].seats = 0;
	printf("Ticket cancelled successfully.\n");
}

int main(void) {
	Ticket tickets[MAX_TICKETS];
	int count = 0;
	int choice;

	do {
		printf("\nTicket Booking System\n");
		printf("1. Book Ticket\n");
		printf("2. Display All Tickets\n");
		printf("3. Search Ticket\n");
		printf("4. Cancel Ticket\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		clearInputBuffer();

		switch (choice) {
			case 1:
				bookTicket(tickets, &count);
				break;
			case 2:
				displayTickets(tickets, count);
				break;
			case 3:
				searchTicket(tickets, count);
				break;
			case 4:
				cancelTicket(tickets, count);
				break;
			case 5:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 5);

	return 0;
}