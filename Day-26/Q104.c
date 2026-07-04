// Write a program to Create quiz application.

#include <stdio.h>

int main() {
	int answer, score = 0;

	printf("Quiz Application\n");

	printf("Q1. Which of the following is a programming language?\n");
	printf("1. HTML\n2. C\n3. CSS\n4. PNG\n");
	printf("Enter your answer: ");
	scanf("%d", &answer);
	if (answer == 2) {
		score++;
	}

	printf("\nQ2. What is the output of 2 + 2?\n");
	printf("1. 3\n2. 4\n3. 5\n4. 6\n");
	printf("Enter your answer: ");
	scanf("%d", &answer);
	if (answer == 2) {
		score++;
	}

	printf("\nQ3. Which symbol is used to end a statement in C?\n");
	printf("1. ,\n2. :\n3. ;\n4. .\n");
	printf("Enter your answer: ");
	scanf("%d", &answer);
	if (answer == 3) {
		score++;
	}

	printf("\nYour score: %d out of 3\n", score);

	return 0;
}

