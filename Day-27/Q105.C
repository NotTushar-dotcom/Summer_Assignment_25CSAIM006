// Write a program to Create student record management system.

#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct Student {
	int rollNo;
	char name[50];
	char course[50];
	float marks;
};

int findStudent(struct Student students[], int count, int rollNo) {
	for (int i = 0; i < count; i++) {
		if (students[i].rollNo == rollNo) {
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

void addStudent(struct Student students[], int *count) {
	if (*count >= MAX_STUDENTS) {
		printf("Student record limit reached.\n");
		return;
	}

	printf("Enter roll number: ");
	scanf("%d", &students[*count].rollNo);
	clearInputBuffer();

	if (findStudent(students, *count, students[*count].rollNo) != -1) {
		printf("Student with this roll number already exists.\n");
		return;
	}

	printf("Enter name: ");
	readLine(students[*count].name, sizeof(students[*count].name));

	printf("Enter course: ");
	readLine(students[*count].course, sizeof(students[*count].course));

	printf("Enter marks: ");
	scanf("%f", &students[*count].marks);
	clearInputBuffer();

	(*count)++;
	printf("Student added successfully.\n");
}

void displayStudents(struct Student students[], int count) {
	if (count == 0) {
		printf("No student records found.\n");
		return;
	}

	printf("\n%-10s %-20s %-20s %-10s\n", "Roll No", "Name", "Course", "Marks");
	printf("---------------------------------------------------------------\n");

	for (int i = 0; i < count; i++) {
		printf("%-10d %-20s %-20s %-10.2f\n",
			   students[i].rollNo,
			   students[i].name,
			   students[i].course,
			   students[i].marks);
	}
}

void searchStudent(struct Student students[], int count) {
	int rollNo;
	printf("Enter roll number to search: ");
	scanf("%d", &rollNo);
	clearInputBuffer();

	int index = findStudent(students, count, rollNo);
	if (index == -1) {
		printf("Student not found.\n");
		return;
	}

	printf("Student found:\n");
	printf("Roll No: %d\n", students[index].rollNo);
	printf("Name   : %s\n", students[index].name);
	printf("Course : %s\n", students[index].course);
	printf("Marks  : %.2f\n", students[index].marks);
}

void updateStudent(struct Student students[], int count) {
	int rollNo;
	printf("Enter roll number to update: ");
	scanf("%d", &rollNo);
	clearInputBuffer();

	int index = findStudent(students, count, rollNo);
	if (index == -1) {
		printf("Student not found.\n");
		return;
	}

	printf("Enter new name: ");
	readLine(students[index].name, sizeof(students[index].name));

	printf("Enter new course: ");
	readLine(students[index].course, sizeof(students[index].course));

	printf("Enter new marks: ");
	scanf("%f", &students[index].marks);
	clearInputBuffer();

	printf("Student record updated successfully.\n");
}

void deleteStudent(struct Student students[], int *count) {
	int rollNo;
	printf("Enter roll number to delete: ");
	scanf("%d", &rollNo);
	clearInputBuffer();

	int index = findStudent(students, *count, rollNo);
	if (index == -1) {
		printf("Student not found.\n");
		return;
	}

	for (int i = index; i < *count - 1; i++) {
		students[i] = students[i + 1];
	}

	(*count)--;
	printf("Student record deleted successfully.\n");
}

int main(void) {
	struct Student students[MAX_STUDENTS];
	int count = 0;
	int choice;

	while (1) {
		printf("\nStudent Record Management System\n");
		printf("1. Add Student\n");
		printf("2. Display Students\n");
		printf("3. Search Student\n");
		printf("4. Update Student\n");
		printf("5. Delete Student\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1) {
			printf("Invalid input.\n");
			return 1;
		}
		clearInputBuffer();

		switch (choice) {
			case 1:
				addStudent(students, &count);
				break;
			case 2:
				displayStudents(students, count);
				break;
			case 3:
				searchStudent(students, count);
				break;
			case 4:
				updateStudent(students, count);
				break;
			case 5:
				deleteStudent(students, &count);
				break;
			case 6:
				printf("Exiting program.\n");
				return 0;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}
}
