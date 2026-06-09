// Write a program to Find factorial of a number. 

#include<stdio.h>

int main(){
    int n, fact =1, i;

    printf("Enter the Number: ");
    scanf("%d", &n);

    for( i = 1; i <= n; i++){
        fact = fact * i;
    }

    printf("Factorial of a Number is: %d", fact);
    
    return 0;
}