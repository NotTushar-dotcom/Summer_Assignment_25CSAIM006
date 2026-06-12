// Write a program to Check Armstrong number.

#include <stdio.h>

int main() {
    int num, original, rem, sum = 0;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    original = num;
    while (num > 0) {
        rem = num % 10;
        sum += rem * rem * rem;
        num /= 10;
    }

    if (sum == original)
        printf("Armstrong number\n");
    else
        printf("Not an Armstrong number\n");

    return 0;
}
