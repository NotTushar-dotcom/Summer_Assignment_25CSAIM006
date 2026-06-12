// Write a program to Find nth Fibonacci term.

#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, next;

    printf("Enter the position (n): ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }

    printf("The %dth Fibonacci term is: %d\n", n, t1);
    return 0;
}
