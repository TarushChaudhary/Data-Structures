// WAP to Reverse a Linked List 
    
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct Node{
    int val;
    struct Node * next;
};

struct Node *  generateLL(int n){
    int i;
    struct Node *  head = NULL;
    struct Node *  temp = NULL;
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct Node));
        head->val = rand()%1000;            // assigning a random value to the head->val
        head->next = NULL;                  // assigning NULL to the head->next
        temp = head;
    }
    // general case
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next;
        temp->val = rand()%1000;            // assigning a random value to the temp->val
        temp->next = NULL;                  // assigning NULL to the temp->next
    }
    return head;                            // returning the address of the head of Linked List
}

//To reverse a linked list, we need 3 pointers to keep track of the previous node, the current node and the next node
struct Node *  reverseLL(struct Node *  head){
    struct Node *  prev, *current, *forward;
    current = head; 
    prev = NULL; 
    forward = NULL;
    while(current != NULL){       
        forward = current->next;            // Set the forward pointer to the next node of the current node
        current->next = prev;               // Set the next pointer of the current node to the previous node
        prev = current;                     // Set the previous node to the current node
        current = forward;                  // Set the current node to the forward node
    }
    head = prev;                            // Set the head to the previous node
    return head;
}


void printLL(struct Node *  head, int n){
    struct Node *  temp = head;
    printf("Linked List = ");
    for(int i=0; i<n; i++){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
    }
    printf(".\n");
}

void freeLL(struct Node *  head){
    struct Node *  prev;
	while(head){                
		prev = head;
		head = head->next;
		free(prev);               // moving ahead one step, freeing the previous node
	}
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    struct Node *  list, * list_rev;        
    srand(time(NULL));                      // seeding the random number generator
    list = generateLL(n);                   
    printLL(list, n);                       
    list_rev = reverseLL(list);             
    printLL(list_rev, n);                   
    freeLL(list);                           
    freeLL(list_rev);                       
    return 0;
}