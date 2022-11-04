// Write a program to perform selection sort on array
#include <stdio.h>
int main()
{
    int a[100], i, j, n, temp;
    printf("Enter total elements in array: ");
    scanf("%d", &n);                            // taking input
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)    // i < n-1 since last element does not need to be sorted
    {
        for (j = i + 1; j < n; j++)   // j = i+1 since it only needs to compare to other elements
        {
            if (a[i] > a[j])      //swapping the elements to arrange in ascending order
            {
                temp = a[i]; // storing the value in temp variable to empty element address
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}