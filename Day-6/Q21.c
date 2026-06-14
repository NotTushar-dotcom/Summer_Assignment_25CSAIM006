// Write a program to Convert decimal to binary.

#include <stdio.h>
#include <string.h>

int main() {
    double num;
    char int_bin[64] = ""; 
    int i = 0;

    printf("Enter a decimal number: ");
    scanf("%lf", &num);

    long long int_part = (long long)num;
    double frac_part = num - int_part;

    
    if (int_part == 0) {
        printf("0");
    } else {
        while (int_part > 0) {
            int_bin[i++] = (int_part % 2) + '0'; 
            int_part /= 2;
        }
        
        for (int j = i - 1; j >= 0; j--) {
            printf("%char", int_bin[j]); 
        }
    }

    // 3. Process fractional part
    if (frac_part > 0) {
        printf(".");
        for (int k = 0; k < 6; k++) { 
            frac_part *= 2;
            printf("%d", (int)frac_part);
            frac_part -= (int)frac_part;
        }
    }
    
    printf("\n");
    return 0;
}

