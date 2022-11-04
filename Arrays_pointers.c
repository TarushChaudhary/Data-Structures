//Making Arrays, Pointers and the malloc command which allows us to allocate space in the heap
#include <stdio.h>
#include <stdlib.h>

int * generateArray(int n){ //  We create an integer pointer to get the starting address of the array, assuming n is a postive integer
	int * addr; // declaring a new starting address for the array

	addr = malloc( n*sizeof(int) ); // we allocate block of memory to the array

	//Validity condition to check for proper memory allocation
	if(addr){ 
		for (int i = 0; i < n; i++){
      addr[i] = i; // if check fails, for loop is skipped
    }
	}
	return addr;
}

void printArray(int *a, int n){
	printf("Array = ");
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main(int argc, char **argv){
	int * a;
	int n = 10;

	a = generateArray(n); // We store the base address of array in a

	printArray(a, n); // last function call to print array using the printArray Method

	//After allocating memory, we free the memory for efficiency
	free(a);
	return 0;
}