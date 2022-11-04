// Write a program to perform selection sort on linked list
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

void sort()   // using selection swap which swaps the data in linked list 
{
    struct node *current, *index;
    int temp;
    if (head == NULL)
    {
        printf("Empty List.");
    }
    else
    {
        for (current = head; current != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    input(n);
    printf("The Linked List is: ");
    display();
    sort();
    printf("The Sorted Linked List is: ");
    display();
    return 0;
}
