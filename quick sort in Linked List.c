#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void input(int n)
{
    struct node *newnode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newnode->data = data;
                newnode->next = NULL;
                temp->next = newnode;
                temp = temp->next;
            }
        }
    }
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Empty List.");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

struct node* last_node(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}


struct node* partition(struct node* low, struct node* high)
{
    // Taking low node of given partition
    struct node* pivot = low;
    struct node* front = low;
    int temp = 0;
    while (front != NULL && front != high) {
        if (front->data > high->data) {
            pivot = low;
 
            // Swapping node->data
            temp = low->data;
            low->data = front->data;
            front->data = temp;
 
            // Moving to next node
            low = low->next;
        }
 
        // Moving to next node
        front = front->next;
    }
 
    // Change high node value to current node
    temp = low->data;
    low->data = high->data;
    high->data = temp;
    return pivot;
}
 
// Performing quick sort in the given linked list
int quicksort(struct node* low, struct node* high)
{
    if (low == high) {
        return 0;
    }
    struct node* pivot = partition(low, high);
 
    if (pivot != NULL && pivot->next != NULL) {
        quicksort(pivot->next, high);
    }
 
    if (pivot != NULL && low != pivot) {
        quicksort(low, pivot);
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    input(n);
    printf("The linked list is: ");
    display();
    quicksort(head, NULL);
// not running beyond this
    printf("\nThe sorted linked list is: "); 
    display();
    return 0;
}
