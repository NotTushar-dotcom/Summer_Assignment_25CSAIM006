// Write a program to Check strong number.

// A strong number is a positive integer where the sum of the factorials of its individual digits equals the number itself.

// For example, 145 is a strong number because 1! + 4! + 5! = 1 + 24 + 120 = 145.

#include <stdio.h>

int main() {
    int num, originalNum, rem, sum = 0, i, fact;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;
    
    while (num > 0) {
        rem = num % 10; 

        
        fact = 1;
        for (i = 1; i <= rem; i++) {
            fact *= i;
        }

        sum += fact;  
        num /= 10;     
    }

    if (sum == originalNum && originalNum > 0) {
        printf("%d is a strong number.\n", originalNum);
    } else {
        printf("%d is not a strong number.\n", originalNum);
    }

    return 0;
}
