// Write a program to Count even and odd elements.

#include <stdio.h>
int main()
{
    int n, i;
    int evenCount = 0, oddCount = 0;
    printf("Enter n:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }

    printf("Even elements=%d\n", evenCount);
    printf("Odd elements=%d\n", oddCount);
    return 0;
}