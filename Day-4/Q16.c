// Write a program to Print Armstrong numbers in a range.

#include <stdio.h>

int main() {
    int start, end, num, rem, sum, temp;

    printf("Enter lower and upper limits: ");
    scanf("%d %d", &start, &end);

    printf("Armstrong numbers: ");
    for (num = start; num <= end; num++) {
        temp = num;
        sum = 0;

        while (temp > 0) {
            rem = temp % 10;
            sum += rem * rem * rem;
            temp /= 10;
        }

        if (sum == num) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}
