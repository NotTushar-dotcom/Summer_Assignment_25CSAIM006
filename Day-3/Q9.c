// Write a program to Check whether a number is prime.

#include <stdio.h>

int main() {
    int n, i, isPrime = 1;

    printf("Enter the Number: ");
    scanf("%d", &n);

    
    if (n <= 1) {
        isPrime = 0; 
    } else {
       
        for (i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                isPrime = 0; 
                break;      
            }
        }
    }

    if (isPrime == 1) {
        printf("Prime Number\n");
    } else {
        printf("Not a Prime Number\n");
    }

    return 0;
}
