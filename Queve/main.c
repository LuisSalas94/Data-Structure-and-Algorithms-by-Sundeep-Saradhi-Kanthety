#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

}*newNode, *rear, *front, *temp;

int element;
int option;


void enqueve(struct Node *newNode)
{
    do
    {
       newNode = (struct Node*)malloc(sizeof(struct Node));
       printf("Enter element to be inserted: ");
       scanf("%d", &element);
       newNode->data = element;
       newNode->next = NULL;

       if(rear == NULL)
       {
           front = newNode;
           rear = newNode;
       }
       else
       {
           rear->next = newNode;
           rear = newNode;
       }

       printf("***Press 1 - Continue or 0 - Exit***\n");
       scanf("%d", &option);

    }while(option == 1);
}

void dequeve(struct Node *newNode)
{
    if(front == NULL)
    {
        printf("Queve is Empty!!!");
    }
    else
    {
        temp = front;
        front = front->next;
        temp->next = NULL;
        free(temp);
    }
}


void display(struct Node *newNode)
{
    temp = front;
    if(front == NULL)
    {
        printf("Queve is Empty!!!");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}


int main()
{
    enqueve(newNode);
    printf("Elements before dequeve: \n");
    display(newNode);
    printf("\n\n");
    dequeve(newNode);
    printf("Elements after dequeve: \n");
    display(newNode);


    return 0;
}
