// Write a program to Create student record system using arrays and strings.

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DEPT_LEN 30

typedef struct {
	int roll;
	char name[NAME_LEN];
	char department[DEPT_LEN];
	float marks;
	int active;
} Student;

void remove_newline(char str[]) {
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

int find_student_index(Student students[], int count, int roll) {
	int i;
	for (i = 0; i < count; i++) {
		if (students[i].active && students[i].roll == roll) {
			return i;
		}
	}
	return -1;
}

void add_student(Student students[], int *count) {
	if (*count >= MAX_STUDENTS) {
		printf("\nRecord list is full. Cannot add more students.\n");
		return;
	}

	Student s;

	printf("\nEnter Roll Number: ");
	scanf("%d", &s.roll);
	getchar();

	if (find_student_index(students, *count, s.roll) != -1) {
		printf("Student with roll number %d already exists.\n", s.roll);
		return;
	}

	printf("Enter Name: ");
	fgets(s.name, NAME_LEN, stdin);
	remove_newline(s.name);

	printf("Enter Department: ");
	fgets(s.department, DEPT_LEN, stdin);
	remove_newline(s.department);

	printf("Enter Marks: ");
	scanf("%f", &s.marks);
	getchar();

	s.active = 1;
	students[*count] = s;
	(*count)++;

	printf("Student record added successfully.\n");
}

void display_students(Student students[], int count) {
	int i;
	int found = 0;

	printf("\n----- Student Records -----\n");
	for (i = 0; i < count; i++) {
		if (students[i].active) {
			found = 1;
			printf("Roll: %d\n", students[i].roll);
			printf("Name: %s\n", students[i].name);
			printf("Department: %s\n", students[i].department);
			printf("Marks: %.2f\n", students[i].marks);
			printf("---------------------------\n");
		}
	}

	if (!found) {
		printf("No student records found.\n");
	}
}

void search_student(Student students[], int count) {
	int roll;
	int index;

	printf("\nEnter roll number to search: ");
	scanf("%d", &roll);
	getchar();

	index = find_student_index(students, count, roll);
	if (index == -1) {
		printf("Student not found.\n");
		return;
	}

	printf("\nStudent Found:\n");
	printf("Roll: %d\n", students[index].roll);
	printf("Name: %s\n", students[index].name);
	printf("Department: %s\n", students[index].department);
	printf("Marks: %.2f\n", students[index].marks);
}

void update_student(Student students[], int count) {
	int roll;
	int index;

	printf("\nEnter roll number to update: ");
	scanf("%d", &roll);
	getchar();

	index = find_student_index(students, count, roll);
	if (index == -1) {
		printf("Student not found.\n");
		return;
	}

	printf("Enter new Name: ");
	fgets(students[index].name, NAME_LEN, stdin);
	remove_newline(students[index].name);

	printf("Enter new Department: ");
	fgets(students[index].department, DEPT_LEN, stdin);
	remove_newline(students[index].department);

	printf("Enter new Marks: ");
	scanf("%f", &students[index].marks);
	getchar();

	printf("Student record updated successfully.\n");
}

void delete_student(Student students[], int count) {
	int roll;
	int index;

	printf("\nEnter roll number to delete: ");
	scanf("%d", &roll);
	getchar();

	index = find_student_index(students, count, roll);
	if (index == -1) {
		printf("Student not found.\n");
		return;
	}

	students[index].active = 0;
	printf("Student record deleted successfully.\n");
}

int main() {
	Student students[MAX_STUDENTS];
	int count = 0;
	int choice;

	do {
		printf("\n===== Student Record System =====\n");
		printf("1. Add Student\n");
		printf("2. Display All Students\n");
		printf("3. Search Student by Roll Number\n");
		printf("4. Update Student Record\n");
		printf("5. Delete Student Record\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();

		switch (choice) {
			case 1:
				add_student(students, &count);
				break;
			case 2:
				display_students(students, count);
				break;
			case 3:
				search_student(students, count);
				break;
			case 4:
				update_student(students, count);
				break;
			case 5:
				delete_student(students, count);
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

