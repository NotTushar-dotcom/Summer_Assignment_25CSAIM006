// Write a program to Find LCM of two numbers.

#include <stdio.h>

int main() {
    int num1, num2, a, b, remainder, gcd, lcm;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    
    a = num1;
    b = num2;

    
    while (b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    gcd = a; 

    
    lcm = (num1 / gcd) * num2; 

   
    printf("The GCD is: %d\n", gcd);
    printf("The LCM of %d and %d is: %d\n", num1, num2, lcm);

    return 0;
}
