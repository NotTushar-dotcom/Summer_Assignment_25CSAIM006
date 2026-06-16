// Write a program to Print number triangle. 

// 1
// 12 
// 123 
// 1234 
// 12345 

#include <stdio.h>

int main() {
    int i, j;
    int rows = 5; 

   
    for (i = 1; i <= rows; ++i) {
        for (j = 1; j <= i; ++j) {
            printf("%d", j);
        }
        printf("\n\n");
    }

    return 0;
}
