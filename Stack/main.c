#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

}*newNode, *temp, *top;

int element;
char ch;


//push method
void push(struct Node *newNode)
{
    do
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element to the Stack: \n");
        scanf("%d", &element);
        if(top == NULL)
        {
        newNode->data = element;
        newNode->next = NULL;
        top = newNode;
        }
        else
        {
        newNode->data = element;
        newNode->next = top;
        top = newNode;
        }

        printf("Press Y - Continue or N - Exit: \n");
        fflush(stdin);
        scanf("%c", &ch);

    }while(ch == 'Y');
}

//pop method
void pop(struct Node *newNode)
{
    if(top == NULL)
    {
        printf("Stack is empty!!!");
    }
    else
    {
        temp = top;
        element = top->data;
        printf("\n%d will be deleted\n", element);
        top = top->next;
        temp->next = NULL;
    }

}


//display method
void display(struct Node *newNode)
{
    if(top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}


int main()
{
    push(newNode);
    printf("Elements of the Stack before deleting: \n");
    display(newNode);
    pop(newNode);
    printf("Elements of the Stack after deleting: \n");
    display(newNode);
    return 0;
}
