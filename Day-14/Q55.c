// Write a program to Second largest element.

#include <stdio.h>

int main() {
    int n, i;
    printf("Enter size: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int max = arr[0], second = -1;
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            second = max; // purana max ab second ban gaya
            max = arr[i]; // naya max mil gaya
        }
        else if(arr[i] > second && arr[i] != max) {
            second = arr[i]; // max nahi hai lekin second se bada
        }
    }
    
    printf("Second largest = %d\n", second);
    return 0;
}