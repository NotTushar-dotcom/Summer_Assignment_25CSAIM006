// Write a program to Create bank account system.

#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
	int accountNumber;
	char holderName[50];
	char accountType[20];
	double balance;
} Account;

int findAccountIndex(Account accounts[], int count, int accountNumber) {
	for (int i = 0; i < count; i++) {
		if (accounts[i].accountNumber == accountNumber) {
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

void createAccount(Account accounts[], int *count) {
	if (*count >= MAX_ACCOUNTS) {
		printf("Account list is full.\n");
		return;
	}

	int accountNumber;
	printf("Enter Account Number: ");
	scanf("%d", &accountNumber);
	clearInputBuffer();

	if (findAccountIndex(accounts, *count, accountNumber) != -1) {
		printf("Account number already exists.\n");
		return;
	}

	accounts[*count].accountNumber = accountNumber;

	printf("Enter Account Holder Name: ");
	readLine(accounts[*count].holderName, sizeof(accounts[*count].holderName));

	printf("Enter Account Type (Savings/Current): ");
	readLine(accounts[*count].accountType, sizeof(accounts[*count].accountType));

	printf("Enter Initial Balance: ");
	scanf("%lf", &accounts[*count].balance);
	clearInputBuffer();

	if (accounts[*count].balance < 0) {
		printf("Balance cannot be negative.\n");
		return;
	}

	(*count)++;
	printf("Account created successfully.\n");
}

void displayAccounts(Account accounts[], int count) {
	if (count == 0) {
		printf("No accounts available.\n");
		return;
	}

	printf("\n%-15s %-25s %-20s %-12s\n", "Account No", "Holder Name", "Type", "Balance");
	printf("--------------------------------------------------------------------------------\n");
	for (int i = 0; i < count; i++) {
		printf("%-15d %-25s %-20s %-12.2f\n",
		       accounts[i].accountNumber,
		       accounts[i].holderName,
		       accounts[i].accountType,
		       accounts[i].balance);
	}
}

void searchAccount(Account accounts[], int count) {
	int accountNumber;
	printf("Enter Account Number to search: ");
	scanf("%d", &accountNumber);

	int index = findAccountIndex(accounts, count, accountNumber);
	if (index == -1) {
		printf("Account not found.\n");
		return;
	}

	printf("Account Found:\n");
	printf("Account Number: %d\n", accounts[index].accountNumber);
	printf("Holder Name: %s\n", accounts[index].holderName);
	printf("Account Type: %s\n", accounts[index].accountType);
	printf("Balance: %.2f\n", accounts[index].balance);
}

void depositMoney(Account accounts[], int count) {
	int accountNumber;
	double amount;

	printf("Enter Account Number: ");
	scanf("%d", &accountNumber);

	int index = findAccountIndex(accounts, count, accountNumber);
	if (index == -1) {
		printf("Account not found.\n");
		return;
	}

	printf("Enter Deposit Amount: ");
	scanf("%lf", &amount);

	if (amount <= 0) {
		printf("Invalid amount.\n");
		return;
	}

	accounts[index].balance += amount;
	printf("Deposit successful. New Balance: %.2f\n", accounts[index].balance);
}

void withdrawMoney(Account accounts[], int count) {
	int accountNumber;
	double amount;

	printf("Enter Account Number: ");
	scanf("%d", &accountNumber);

	int index = findAccountIndex(accounts, count, accountNumber);
	if (index == -1) {
		printf("Account not found.\n");
		return;
	}

	printf("Enter Withdrawal Amount: ");
	scanf("%lf", &amount);

	if (amount <= 0) {
		printf("Invalid amount.\n");
		return;
	}

	if (amount > accounts[index].balance) {
		printf("Insufficient balance.\n");
		return;
	}

	accounts[index].balance -= amount;
	printf("Withdrawal successful. New Balance: %.2f\n", accounts[index].balance);
}

int main(void) {
	Account accounts[MAX_ACCOUNTS];
	int count = 0;
	int choice;

	do {
		printf("\nBank Account System\n");
		printf("1. Create Account\n");
		printf("2. Display All Accounts\n");
		printf("3. Search Account\n");
		printf("4. Deposit Money\n");
		printf("5. Withdraw Money\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				createAccount(accounts, &count);
				break;
			case 2:
				displayAccounts(accounts, count);
				break;
			case 3:
				searchAccount(accounts, count);
				break;
			case 4:
				depositMoney(accounts, count);
				break;
			case 5:
				withdrawMoney(accounts, count);
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