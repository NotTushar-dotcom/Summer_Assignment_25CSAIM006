// Write a program to Convert decimal to binary.

#include <stdio.h>

int main(void) {
    int n, rem, binary = 0, base = 1;

    printf("Enter decimal number: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    while (n > 0) {
        rem = n % 2;
        binary = binary + rem * base;
        n = n / 2;
        base = base * 10; // 1, 10, 100, ...
    }

    printf("Binary = %d\n", binary);
    return 0;
}

