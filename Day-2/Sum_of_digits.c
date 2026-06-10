// Write a program to Find the sum of digits of a number.

#include<stdio.h>

int main(){
    long long num;
    int rem, sum = 0;

    printf("Enter the Number: ");
    scanf("%lld",&num);

    while (num != 0){
        rem = num % 10;
        sum += rem;
        num /= 10;
    }

    printf("The sum of digits of a Number is: %d", sum);

    return 0;

}