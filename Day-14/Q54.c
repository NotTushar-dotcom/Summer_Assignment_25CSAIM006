// Write a program to Frequency of an element.

#include <stdio.h>

int main() {
    int n, i, target, count = 0;
    printf("Enter size: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter element: ");
    scanf("%d", &target);
    
    for(i = 0; i < n; i++)
        if(arr[i] == target)
            count++;
    
    printf("%d occurs %d times\n", target, count);
    return 0;
}
