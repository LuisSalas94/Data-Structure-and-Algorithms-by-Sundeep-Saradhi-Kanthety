#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

}*newNode, *head, *tail, *temp;

int value;
int position;
char ch;


//display function
void display(struct Node *head)
{
    temp = head;

    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("%d ", temp->data);

}

//insert at the beginning
void InsertAtBeginning(struct Node *newNode)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter value to be inserted: \n");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

//insert at the end
void InsertAtTheEnd(struct Node *newNode)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter value to be inserted: \n");
    scanf("%d", &value);
    newNode->data = value;
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;

}

//insert at given position
void InsertAtGivenPosition(struct Node *newNode)
{
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter value to be inserted: \n");
    scanf("%d", &value);

    printf("\nEnter position: \n");
    scanf("%d", &position);

    temp = head;

    for(int i = 0; i<position-1; i++)
    {
        temp = temp->next;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//delete at beginning
void deleteAtBeginning(struct Node *newNode)
{
    temp = head;
    head = head->next;
    tail->next = head;
    temp->next = NULL;
}

//delete at ending position
void deleteAtEnding(struct Node *newNode)
{
    temp = head;

    while(temp->next != tail)
    {
        temp = temp->next;
    }

    tail->next = NULL;
    temp->next = head;
    tail = temp;
}


//delete at given position
void deleteGivenPosition(struct Node *newNode)
{
    printf("Enter position to be eliminated: ");
    scanf("%d", &position);

    temp = head;
    for(int i = 0; i<position-1; i++)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;
}



int main()
{
    do
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: \n");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    printf("Press Y - Continue or N - Exit: ");
    fflush(stdin);
    scanf("%c", &ch);


}while(ch == 'Y');

    printf("***Before Deleting***\n");
    display(head);

    printf("\n\n");

    deleteGivenPosition(head);
    printf("***After Deleting***\n");
    display(head);


    return 0;
}
