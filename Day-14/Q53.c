// Write a program to Linear search. 

#include <stdio.h>

int main() {
    int n, i, target, found = 0;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &target);
        
    for(i = 0; i < n; i++) {
        if(arr[i] == target) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if(!found) printf("Not found!\n");
    return 0;
}
