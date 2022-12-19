#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}


int * heapDelete(int *A, int n, int k){
    
    
    int i, j;
    for(i = 0; i < n; i++){
        if(A[i] == k){
            A[i] = A[n-1];              
            n--;                        
            break;
        }
    }
    
    
    while(2*i+1 < n){                           
        j = 2*i+1;
        if(j+1 < n && A[j+1] < A[j]){           
            j++;                                
        }
        if(A[i] > A[j]){                        
            swap(&A[i], &A[j]);
            i = j;                              
        }
        else{
            break;                              
        }
    }
    return A;    
}


int * generateArray(int n){ 
    int * t; 
    t = (int *) malloc(n*sizeof(int)); 
    if(t){ 
        for (int i = 0; i < n; i++){ 
            t[i] = rand()%1000; 
        } 
    }
    return t; 
}

void printArray(int *a, int n){
    printf("Array = ");
    for (int i = 0; i < n; i++){
        printf(i?", %d":"%d", a[i]);
    }
    printf(".\n");
}

void makeMinHeap(int * A, int n){    
    
    int i, j, k;
    for(i = 0; i < n; i++){     
        k = i;                 
        do{                     
            j = (k - 1) / 2;        
            if(A[j] > A[k]){        
                swap(&A[j], &A[k]);
            }
            k = j;                  
        }while(k != 0);             
    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    
    srand(time(NULL)); 
    int *A;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    A = generateArray(n); 
    printArray(A, n);
    
    
    makeMinHeap(A, n);
    printf("Minimum Heap ");
    printArray(A, n);
    
    printf("Enter the element to be deleted: ");
    scanf("%d", &k);

    A = heapDelete(A, n, k);
    printArray(A, n-1);

    free(A);
    return 0;
}