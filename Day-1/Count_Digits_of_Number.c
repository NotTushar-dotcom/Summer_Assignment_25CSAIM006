// Write a program to Count digits in a number. 

#include<stdio.h>

int main(){
    long long n, temp = 0;

    printf("Enter the Number to Count: ");
    scanf("%lld",&n);

    if (n==0){
        temp = 1;
    } else {
        while (n != 0){
            n = n / 10;
            temp++;
        }
    }

    printf("The number of digits is: %d", temp);
    return 0;
}