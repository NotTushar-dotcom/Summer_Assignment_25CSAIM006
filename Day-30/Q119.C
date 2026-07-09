// Write a program to Create mini employee management system.

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50
#define ROLE_LEN 40

typedef struct {
	int id;
	char name[NAME_LEN];
	char role[ROLE_LEN];
	float salary;
	int active;
} Employee;

void remove_newline(char text[]) {
	size_t len = strlen(text);
	if (len > 0 && text[len - 1] == '\n') {
		text[len - 1] = '\0';
	}
}

int find_employee_index(Employee employees[], int count, int id) {
	int i;
	for (i = 0; i < count; i++) {
		if (employees[i].active && employees[i].id == id) {
			return i;
		}
	}
	return -1;
}

void add_employee(Employee employees[], int *count) {
	Employee e;

	if (*count >= MAX_EMPLOYEES) {
		printf("\nEmployee list is full. Cannot add more employees.\n");
		return;
	}

	printf("\nEnter Employee ID: ");
	scanf("%d", &e.id);
	getchar();

	if (find_employee_index(employees, *count, e.id) != -1) {
		printf("Employee with ID %d already exists.\n", e.id);
		return;
	}

	printf("Enter Name: ");
	fgets(e.name, NAME_LEN, stdin);
	remove_newline(e.name);

	printf("Enter Role: ");
	fgets(e.role, ROLE_LEN, stdin);
	remove_newline(e.role);

	printf("Enter Salary: ");
	scanf("%f", &e.salary);
	getchar();

	if (e.salary < 0) {
		e.salary = 0;
	}

	e.active = 1;
	employees[*count] = e;
	(*count)++;

	printf("Employee added successfully.\n");
}

void display_employees(Employee employees[], int count) {
	int i;
	int found = 0;

	printf("\n----- Employee Records -----\n");
	for (i = 0; i < count; i++) {
		if (employees[i].active) {
			found = 1;
			printf("ID: %d\n", employees[i].id);
			printf("Name: %s\n", employees[i].name);
			printf("Role: %s\n", employees[i].role);
			printf("Salary: %.2f\n", employees[i].salary);
			printf("----------------------------\n");
		}
	}

	if (!found) {
		printf("No employee records found.\n");
	}
}

void search_employee(Employee employees[], int count) {
	int id;
	int index;

	printf("\nEnter Employee ID to search: ");
	scanf("%d", &id);
	getchar();

	index = find_employee_index(employees, count, id);
	if (index == -1) {
		printf("Employee not found.\n");
		return;
	}

	printf("\nEmployee Found:\n");
	printf("ID: %d\n", employees[index].id);
	printf("Name: %s\n", employees[index].name);
	printf("Role: %s\n", employees[index].role);
	printf("Salary: %.2f\n", employees[index].salary);
}

void update_employee(Employee employees[], int count) {
	int id;
	int index;

	printf("\nEnter Employee ID to update: ");
	scanf("%d", &id);
	getchar();

	index = find_employee_index(employees, count, id);
	if (index == -1) {
		printf("Employee not found.\n");
		return;
	}

	printf("Enter new Name: ");
	fgets(employees[index].name, NAME_LEN, stdin);
	remove_newline(employees[index].name);

	printf("Enter new Role: ");
	fgets(employees[index].role, ROLE_LEN, stdin);
	remove_newline(employees[index].role);

	printf("Enter new Salary: ");
	scanf("%f", &employees[index].salary);
	getchar();

	if (employees[index].salary < 0) {
		employees[index].salary = 0;
	}

	printf("Employee updated successfully.\n");
}

void delete_employee(Employee employees[], int count) {
	int id;
	int index;

	printf("\nEnter Employee ID to delete: ");
	scanf("%d", &id);
	getchar();

	index = find_employee_index(employees, count, id);
	if (index == -1) {
		printf("Employee not found.\n");
		return;
	}

	employees[index].active = 0;
	printf("Employee deleted successfully.\n");
}

int main() {
	Employee employees[MAX_EMPLOYEES];
	int count = 0;
	int choice;

	do {
		printf("\n===== Mini Employee Management System =====\n");
		printf("1. Add Employee\n");
		printf("2. Display All Employees\n");
		printf("3. Search Employee by ID\n");
		printf("4. Update Employee\n");
		printf("5. Delete Employee\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();

		switch (choice) {
			case 1:
				add_employee(employees, &count);
				break;
			case 2:
				display_employees(employees, count);
				break;
			case 3:
				search_employee(employees, count);
				break;
			case 4:
				update_employee(employees, count);
				break;
			case 5:
				delete_employee(employees, count);
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