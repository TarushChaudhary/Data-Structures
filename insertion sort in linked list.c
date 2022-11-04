 #include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;   // head is a global variable
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
        printf("List is empty.");
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
void insertionSort()
{
    // Insertion sort is a simple sorting algorithm that sorts a list one item at a time.
    struct node *current, *index, *temp;
    if (head == NULL)           
    {
        printf("List is empty.");
    }
    else
    {
        current = head->next;                          //current is the second element
        while (current != NULL)
        {
            temp = current->next;                       //storing the address of next element in temp
            index = head;                               //index is the first element
            while (index != current)                    
            {
                if (index->data > current->data)        
                {
                    int temp1 = index->data;            //swapping the data of index and current
                    index->data = current->data;        
                    current->data = temp1;              
                }
                index = index->next;                    //index is the next element
            }
            current = temp;
        } 
    }
}
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    input(n);
    printf("\nThe linked list is: ");
    display();
    insertionSort();
    printf("\nThe sorted linked list is: ");
    display();
    return 0;
}
