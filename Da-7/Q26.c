// Write a program to Recursive Fibonacci.

#include<Stdio.h>

int Fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    } else 
        return Fib(n-1)+Fib(n-2);
}

int main() {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%dth Fibonacci = %d\n", n, Fib(n));
    return 0;
}