// Write a program to Check whether a number is palindrome.

#include<stdio.h>

int main(){
    int num, originalNum, rem, rev = 0;

    printf("Enter the Number: ");
    scanf("%d",&num);

    originalNum = num;

    while (num > 0){
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }

    if (originalNum == rev){
        printf("%d is a Palindrome Number", originalNum);
    } else{
        printf("%d is not a Palindrome Number", originalNum);
    }

    return 0;
}

  