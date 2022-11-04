#include <stdio.h>
#include<stdlib.h>

struct node {  //structs allows us to define data types such as nodes
	int val;
	struct node * next; // a pointer which saves the address of next node
};

struct node * generateLL(int * a, int n){
	int i; // counter
	struct node * head = NULL;   // head of linked list
	struct node * temp = NULL;   // temp pointer to traverse linked list

	// creating the head of the link list
	if(n>0){
		head = malloc(sizeof(struct node));
		head->val = a[0];
		head->next = NULL;
		temp = head;
	}
	//if the head exists, a new node is created and stores the address for it in the pointer variable of the previous node
  // temp is then changed to new next and update value of val and set temp back to NULL
	// i starts from 1, since head case has been created 
  	for(i=1; i<n; i++){
		temp->next = malloc(sizeof(struct node));
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}
	return head;
}

void freeLL(struct node * head){
	// We can't just destroy a linked list with free() since the nodes are discontiguous unlike arrays
	struct node * prev;
	while(head){
		prev = head;
		head = head->next;
		free(prev); //freeing the previous node after moving the head to the next node
	}
}

void printLL(struct node * head){
	struct node * temp;
	printf("Linked List = ");
	for (temp = head; temp; temp=temp->next){     //loop exits when temp has the value NULL which will be the last address of Linked List
		printf("%d ", temp->val);
	}
	printf("\n");

}

void printArray(int * a, int n){
	printf("Array = ");
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(int argc, char **argv){
	int n = 10;
	struct node * list;
 
	int a[] = {23,24,56,78,90,12,34,56,78,90};
	list = generateLL(a, n); // generate a linked list from an array

	printArray(a, n); 

	printLL(list);

	//Again, we MUST free the space we have allocated and are finished using
	free(a);
	freeLL(list);
	return 0;
}
