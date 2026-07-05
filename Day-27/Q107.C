// Write a program to Create salary management system.

#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

struct Employee {
	int id;
	char name[50];
	float basicSalary;
	float bonus;
	float deduction;
};

int findEmployee(struct Employee employees[], int count, int id) {
	for (int i = 0; i < count; i++) {
		if (employees[i].id == id) {
			return i;
		}
	}
	return -1;
}

void clearInputBuffer(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
	}
}

void readLine(char text[], int size) {
	fgets(text, size, stdin);
	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] == '\n') {
			text[i] = '\0';
			break;
		}
	}
}

float calculateNetSalary(struct Employee employee) {
	return employee.basicSalary + employee.bonus - employee.deduction;
}

void addEmployee(struct Employee employees[], int *count) {
	if (*count >= MAX_EMPLOYEES) {
		printf("Employee record limit reached.\n");
		return;
	}

	printf("Enter employee id: ");
	scanf("%d", &employees[*count].id);
	clearInputBuffer();

	if (findEmployee(employees, *count, employees[*count].id) != -1) {
		printf("Employee with this id already exists.\n");
		return;
	}

	printf("Enter name: ");
	readLine(employees[*count].name, sizeof(employees[*count].name));

	printf("Enter basic salary: ");
	scanf("%f", &employees[*count].basicSalary);

	printf("Enter bonus: ");
	scanf("%f", &employees[*count].bonus);

	printf("Enter deduction: ");
	scanf("%f", &employees[*count].deduction);
	clearInputBuffer();

	(*count)++;
	printf("Salary record added successfully.\n");
}

void displayEmployees(struct Employee employees[], int count) {
	if (count == 0) {
		printf("No salary records found.\n");
		return;
	}

	printf("\n%-8s %-20s %-12s %-10s %-12s %-12s\n", "ID", "Name", "Basic", "Bonus", "Deduction", "Net Salary");
	printf("--------------------------------------------------------------------------\n");

	for (int i = 0; i < count; i++) {
		printf("%-8d %-20s %-12.2f %-10.2f %-12.2f %-12.2f\n",
			   employees[i].id,
			   employees[i].name,
			   employees[i].basicSalary,
			   employees[i].bonus,
			   employees[i].deduction,
			   calculateNetSalary(employees[i]));
	}
}

void searchEmployee(struct Employee employees[], int count) {
	int id;
	printf("Enter employee id to search: ");
	scanf("%d", &id);
	clearInputBuffer();

	int index = findEmployee(employees, count, id);
	if (index == -1) {
		printf("Employee not found.\n");
		return;
	}

	printf("Employee found:\n");
	printf("ID          : %d\n", employees[index].id);
	printf("Name        : %s\n", employees[index].name);
	printf("Basic Salary : %.2f\n", employees[index].basicSalary);
	printf("Bonus       : %.2f\n", employees[index].bonus);
	printf("Deduction   : %.2f\n", employees[index].deduction);
	printf("Net Salary  : %.2f\n", calculateNetSalary(employees[index]));
}

void updateEmployee(struct Employee employees[], int count) {
	int id;
	printf("Enter employee id to update: ");
	scanf("%d", &id);
	clearInputBuffer();

	int index = findEmployee(employees, count, id);
	if (index == -1) {
		printf("Employee not found.\n");
		return;
	}

	printf("Enter new name: ");
	readLine(employees[index].name, sizeof(employees[index].name));

	printf("Enter new basic salary: ");
	scanf("%f", &employees[index].basicSalary);

	printf("Enter new bonus: ");
	scanf("%f", &employees[index].bonus);

	printf("Enter new deduction: ");
	scanf("%f", &employees[index].deduction);
	clearInputBuffer();

	printf("Salary record updated successfully.\n");
}

void deleteEmployee(struct Employee employees[], int *count) {
	int id;
	printf("Enter employee id to delete: ");
	scanf("%d", &id);
	clearInputBuffer();

	int index = findEmployee(employees, *count, id);
	if (index == -1) {
		printf("Employee not found.\n");
		return;
	}

	for (int i = index; i < *count - 1; i++) {
		employees[i] = employees[i + 1];
	}

	(*count)--;
	printf("Salary record deleted successfully.\n");
}

int main(void) {
	struct Employee employees[MAX_EMPLOYEES];
	int count = 0;
	int choice;

	while (1) {
		printf("\nSalary Management System\n");
		printf("1. Add Salary Record\n");
		printf("2. Display Records\n");
		printf("3. Search Record\n");
		printf("4. Update Record\n");
		printf("5. Delete Record\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1) {
			printf("Invalid input.\n");
			return 1;
		}
		clearInputBuffer();

		switch (choice) {
			case 1:
				addEmployee(employees, &count);
				break;
			case 2:
				displayEmployees(employees, count);
				break;
			case 3:
				searchEmployee(employees, count);
				break;
			case 4:
				updateEmployee(employees, count);
				break;
			case 5:
				deleteEmployee(employees, &count);
				break;
			case 6:
				printf("Exiting program.\n");
				return 0;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}
}

