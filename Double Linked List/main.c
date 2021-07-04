#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

}*newNode, *head, *tail, *temp;

char ch;
int value;
int position;


//display function
void display(struct Node *head)
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


//insertion at beginning function
void InsertionAtBeginning(struct Node *newNode)
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter value: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

//insertion at the end function
void InsertionAtTheEnd(struct Node *newNode)
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter value: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

//insertion at given position function
void InsertionAtGivenPosition(struct Node *newNode)
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter value: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &position);

    temp = head;

    for(int i = 0; i<position-1; i++)
    {
        temp = temp->next;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

//deletion at beginning function
void DeletionAtBeginning(struct Node *newNode)
{
    temp = head;
    head = head->next;
    temp->next = NULL;
    head->prev = NULL;
}

//deletion at the end function
void DeletionAtTheEnd(struct Node *newNode)
{
    temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
}

//deletion at given position function
void DeletionAtGivenPosition(struct Node *newNode)
{
    printf("\nEnter position: ");
    scanf("%d", &position);
    temp = head;
    for(int i = 0; i<position-1; i++)
    {
        temp = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }
}



int main()
{
    do
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &value);
        newNode->prev = NULL;
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
            newNode->prev = tail;
            tail = newNode;
        }

        printf("Press Y - Continue or N - Exit: ");
        fflush(stdin);
        scanf("%c", &ch);

    }while(ch == 'Y');

    printf("***Before Deletion***\n");
    display(head);

    DeletionAtGivenPosition(head);
    printf("\n***After Deletion***\n");
    display(head);

    return 0;
}
