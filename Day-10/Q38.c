// Write a program to Print reverse pyramid.
// *********
//  *******
//   *****
//    ***
//     *


#include <stdio.h>

int main() {
    int rows, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 0; i < rows; i++) {
        
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        for (k = 0; k < (2 * (rows - i) - 1); k++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
