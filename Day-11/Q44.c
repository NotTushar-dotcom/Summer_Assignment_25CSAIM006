// Write a program to Write function to find factorial.

#include<stdio.h>

long long factorial(int n) {
    long long fact = 1;
    for(int i =1; i <= n; i++)
        fact = fact * i;
    return fact;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Factorial = %lld\n", factorial(n));
    return 0;
}