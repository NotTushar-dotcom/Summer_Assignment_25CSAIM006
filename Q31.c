// Write a program to Print character triangle. 

// A 
// AB 
// ABC 
// ABCD 
// ABCDE 

#include <stdio.h>

int main() {
    int i, j;
    int rows = 5; 

    for (i = 1; i <= rows; ++i) {
        for (j = 1; j <= i; ++j) {
            // 'A' + 0 = 'A', 'A' + 1 = 'B', etc.
            printf("%c", 'A' + j - 1);
        }
        
        printf("\n\n");
    }

    return 0;
}
