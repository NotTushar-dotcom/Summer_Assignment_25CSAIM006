// Write a program to Find the product of digits.

#include<stdio.h>

int main(){
    int n;
    int rem, product = 1;

    printf("Enter the Number: ");
    scanf("%d",&n);

    if (n == 0){
        product = 0;
    }

    if(n < 0){
        n = -n;
    }

    while (n > 0){
        rem = n % 10;
        product *= rem;
        n /= 10;
    }

    printf("Product of digits is: %d\n", product);
    return 0;
}