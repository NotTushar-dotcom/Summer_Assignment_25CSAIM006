// Write a program to Find largest prime factor.

#include <stdio.h>

int main() {
    long long num, originalNum;
    long long maxPrime = -1;
    long long i;

    printf("Enter a positive integer: ");
    if (scanf("%lld", &num) != 1 || num <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    originalNum = num;

    while (num % 2 == 0) {
        maxPrime = 2;
        num /= 2;
    }

    for (i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            maxPrime = i;
            num /= i;
        }
    }

    if (num > 2) {
        maxPrime = num;
    }

    if (maxPrime == -1) {
        printf("1 has no prime factors.\n");
    } else {
        printf("The largest prime factor of %lld is %lld.\n", originalNum, maxPrime);
    }

    return 0;
}
