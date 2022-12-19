#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct quadTree
{
    int data;
    struct quadTree *topLeft;
    struct quadTree *topRight;
    struct quadTree *bottomLeft;
    struct quadTree *bottomRight;
};  

typedef struct quadTree * nodeAddress;

nodeAddress generateQuadTree(int size){
    nodeAddress head = NULL;
    nodeAddress temp = NULL;
    nodeAddress current = NULL;
    int i;
    for (i = 0; i < size; i++)
    {
        temp = (nodeAddress)malloc(sizeof(struct quadTree));
        temp->data = rand() % 100;
        temp->topLeft = NULL;
        temp->topRight = NULL;
        temp->bottomLeft = NULL;
        temp->bottomRight = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->topLeft = temp;
            current->topRight = temp;
            current->bottomLeft = temp;
            current->bottomRight = temp;
            current = temp;
        }
    }
    return head;
}

void printQuadTree(nodeAddress head){
    nodeAddress current = head;
    printf("Quad Tree = ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->topLeft;
    }
}

int main(){
    srand(time(0));
    nodeAddress head = generateQuadTree(10);
    printQuadTree(head);
    return 0;
}
