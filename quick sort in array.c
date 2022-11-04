// Write a program to perform quick sort on array
#include <stdio.h>
#include<time.h>


int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

void quickSort(int a[], int first, int last)
{
    if(last>=first){
        int p = partition(a, first, last);
        quickSort(a, first, p - 1);
        quickSort(a, p + 1, last);
    }
 
}


int main(int argc, char const *argv[])
{
  int a[100], i, j, n;
  //input array from user
  printf("Enter the number of elements in array: ");
  scanf("%d", &n);
  printf("Enter the elements of array: ");
  for (i = 0; i < n; i++)
  {   
    scanf("%d", &a[i]);
  }
  printf("The array is: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }

  // sorting the array
  quickSort(a, 0, n-1);
  printf("\n The Sorted array is: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  return 0;
}
