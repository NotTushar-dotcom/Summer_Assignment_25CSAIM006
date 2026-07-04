// Write a program to Create ATM simulation.

#include <stdio.h>

int main() {
	int pin = 1234;
	int enteredPin, choice;
	float balance = 1000.0f;
	float amount;

	printf("Enter your PIN: ");
	scanf("%d", &enteredPin);

	if (enteredPin != pin) {
		printf("Invalid PIN. Access denied.\n");
		return 0;
	}

	do {
		printf("\nATM Menu\n");
		printf("1. Balance Inquiry\n");
		printf("2. Deposit\n");
		printf("3. Withdraw\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Current balance: %.2f\n", balance);
				break;
			case 2:
				printf("Enter amount to deposit: ");
				scanf("%f", &amount);
				if (amount > 0) {
					balance += amount;
					printf("Deposit successful. New balance: %.2f\n", balance);
				} else {
					printf("Invalid deposit amount.\n");
				}
				break;
			case 3:
				printf("Enter amount to withdraw: ");
				scanf("%f", &amount);
				if (amount > 0 && amount <= balance) {
					balance -= amount;
					printf("Withdrawal successful. New balance: %.2f\n", balance);
				} else {
					printf("Invalid withdrawal amount or insufficient balance.\n");
				}
				break;
			case 4:
				printf("Thank you for using the ATM.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 4);

	return 0;
}