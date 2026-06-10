// Write a program to calculate sum of first N natural numbers.

#include <stdio.h>

int main() {
    int n;
    int sum = 0;

    printf("Enter N: ");
    scanf("%d", &n);

    for ( int i = 1; i <= n; i++ ){
        sum += i;
    }

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
