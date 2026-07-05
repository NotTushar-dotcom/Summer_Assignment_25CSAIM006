// Write a program to Create employee management system.

#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

struct Employee {
	int id;
	char name[50];
	char department[50];
	char designation[50];
	float salary;
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

	printf("Enter department: ");
	readLine(employees[*count].department, sizeof(employees[*count].department));

	printf("Enter designation: ");
	readLine(employees[*count].designation, sizeof(employees[*count].designation));

	printf("Enter salary: ");
	scanf("%f", &employees[*count].salary);
	clearInputBuffer();

	(*count)++;
	printf("Employee added successfully.\n");
}

void displayEmployees(struct Employee employees[], int count) {
	if (count == 0) {
		printf("No employee records found.\n");
		return;
	}

	printf("\n%-8s %-20s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Designation", "Salary");
	printf("--------------------------------------------------------------------------------\n");

	for (int i = 0; i < count; i++) {
		printf("%-8d %-20s %-20s %-20s %-10.2f\n",
			   employees[i].id,
			   employees[i].name,
			   employees[i].department,
			   employees[i].designation,
			   employees[i].salary);
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
	printf("Department  : %s\n", employees[index].department);
	printf("Designation : %s\n", employees[index].designation);
	printf("Salary      : %.2f\n", employees[index].salary);
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

	printf("Enter new department: ");
	readLine(employees[index].department, sizeof(employees[index].department));

	printf("Enter new designation: ");
	readLine(employees[index].designation, sizeof(employees[index].designation));

	printf("Enter new salary: ");
	scanf("%f", &employees[index].salary);
	clearInputBuffer();

	printf("Employee record updated successfully.\n");
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
	printf("Employee record deleted successfully.\n");
}

int main(void) {
	struct Employee employees[MAX_EMPLOYEES];
	int count = 0;
	int choice;

	while (1) {
		printf("\nEmployee Management System\n");
		printf("1. Add Employee\n");
		printf("2. Display Employees\n");
		printf("3. Search Employee\n");
		printf("4. Update Employee\n");
		printf("5. Delete Employee\n");
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

