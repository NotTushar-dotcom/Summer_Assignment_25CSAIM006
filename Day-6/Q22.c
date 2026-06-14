// Write a program to Convert binary to decimal.

#include <stdio.h>

int main(void) {
    int binary, rem, decimal = 0, power = 1;

    printf("Enter binary number: ");
    if (scanf("%d", &binary) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    while (binary != 0) {
        rem = binary % 10;
        if (rem != 0 && rem != 1) {
            printf("Invalid binary number\n");
            return 1;
        }
        decimal += rem * power;
        binary = binary / 10;
        power *= 2;
    }

    printf("Decimal = %d\n", decimal);
    return 0;
}
