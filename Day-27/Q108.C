// Write a program to Create marksheet generation system.

#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5

struct Student {
	int rollNo;
	char name[50];
	char className[20];
	float marks[SUBJECTS];
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

float calculateTotal(struct Student student) {
	float total = 0.0f;
	for (int i = 0; i < SUBJECTS; i++) {
		total += student.marks[i];
	}
	return total;
}

float calculatePercentage(struct Student student) {
	return calculateTotal(student) / SUBJECTS;
}

const char *calculateGrade(float percentage) {
	if (percentage >= 90.0f) {
		return "A+";
	} else if (percentage >= 80.0f) {
		return "A";
	} else if (percentage >= 70.0f) {
		return "B";
	} else if (percentage >= 60.0f) {
		return "C";
	} else if (percentage >= 50.0f) {
		return "D";
	}
	return "F";
}

int isPass(struct Student student) {
	for (int i = 0; i < SUBJECTS; i++) {
		if (student.marks[i] < 33.0f) {
			return 0;
		}
	}
	return 1;
}

void addStudent(struct Student students[], int *count) {
	if (*count >= MAX_STUDENTS) {
		printf("Student limit reached.\n");
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

	printf("Enter class: ");
	readLine(students[*count].className, sizeof(students[*count].className));

	for (int i = 0; i < SUBJECTS; i++) {
		printf("Enter marks for subject %d: ", i + 1);
		scanf("%f", &students[*count].marks[i]);
	}
	clearInputBuffer();

	(*count)++;
	printf("Marks record added successfully.\n");
}

void displayMarksheet(struct Student student) {
	float total = calculateTotal(student);
	float percentage = calculatePercentage(student);
	const char *grade = calculateGrade(percentage);
	int result = isPass(student);

	printf("\n------------------------------\n");
	printf("         MARKSHEET           \n");
	printf("------------------------------\n");
	printf("Roll No : %d\n", student.rollNo);
	printf("Name    : %s\n", student.name);
	printf("Class   : %s\n", student.className);

	for (int i = 0; i < SUBJECTS; i++) {
		printf("Subject %d: %.2f\n", i + 1, student.marks[i]);
	}

	printf("------------------------------\n");
	printf("Total      : %.2f / %.2f\n", total, SUBJECTS * 100.0f);
	printf("Percentage : %.2f%%\n", percentage);
	printf("Grade      : %s\n", grade);
	printf("Result     : %s\n", result ? "PASS" : "FAIL");
}

void searchStudent(struct Student students[], int count) {
	int rollNo;
	printf("Enter roll number to generate marksheet: ");
	scanf("%d", &rollNo);
	clearInputBuffer();

	int index = findStudent(students, count, rollNo);
	if (index == -1) {
		printf("Student not found.\n");
		return;
	}

	displayMarksheet(students[index]);
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

	printf("Enter new class: ");
	readLine(students[index].className, sizeof(students[index].className));

	for (int i = 0; i < SUBJECTS; i++) {
		printf("Enter new marks for subject %d: ", i + 1);
		scanf("%f", &students[index].marks[i]);
	}
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
		printf("\nMarksheet Generation System\n");
		printf("1. Add Student\n");
		printf("2. Generate Marksheet\n");
		printf("3. Update Student\n");
		printf("4. Delete Student\n");
		printf("5. Exit\n");
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
				searchStudent(students, count);
				break;
			case 3:
				updateStudent(students, count);
				break;
			case 4:
				deleteStudent(students, &count);
				break;
			case 5:
				printf("Exiting program.\n");
				return 0;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}
}

