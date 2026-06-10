// Write a program to Revserse a number.

#include<stdio.h>

int main(){
    long long num;
    int rem, rev = 0;

    printf("Enter the Number: ");
    scanf("%lld",&num);

    while( num != 0){
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }

    printf("The reverse of a number is: %d", rev);
    return 0;
}