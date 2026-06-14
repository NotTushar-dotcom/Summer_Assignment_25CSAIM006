// Write a program to Count set bits in a number.

#include<stdio.h>

    int main(){
    int n, count = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    while(n > 0){
        if(n & 1)
            count++;
        n = n >> 1;
    }

    printf("Set bits = %d\n", count);
    return 0;
}