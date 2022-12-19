
#include<stdio.h>
#include<stdlib.h>
#define MAX 10 
int stack[MAX];
int top = -1; 


void push(int data){
    if(top == MAX-1){
        printf("\nStack Overflow");
    }
    else{
        top++;
        stack[top] = data;
    }
}

void pop(){
    if(top == -1){
        printf("\nStack Underflow");
    }
    else{
        printf("\nThe popped element is %d", stack[top]);
        top--;
    }
}

void display(){
    int i;
    if(top == -1){
        printf("\nStack is empty/Underflow");
    }
    else{
        printf("\nThe elements in the stack are: ");
        for(i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
    }
}
void peek(){
    if(top == -1){
        printf("\nStack is empty/Underflow");
    }
    else{
        printf("\nThe top element is %d", stack[top]);
    }
}

int main(int argc, char const *argv[])
{
    int choice, data;
    do{
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the data to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    } while (choice != 5);    
    return 0;
}


