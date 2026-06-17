// Write a program to Print repeated-number pattern. 

// 1 
// 22 
// 333 
// 4444 
// 55555 

#include <stdio.h>

int main() {
    int i, j;
    int rows = 5;

    for (i = 1; i <= rows; ++i) {
        for (j = 1; j <= i; ++j) {
            printf("%d", i);
        }
        printf("\n\n");
    }

    return 0;
}
