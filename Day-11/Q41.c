// Write a program to Write function to find sum of two numbers.

#include<stdio.h>
int add(int a, int b);

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    int result = add(x, y);
    printf("Sum = %d\n", result);
    return 0;
}

int add(int a, int b) {
    return a + b;
}