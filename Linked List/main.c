#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode;
struct Node *head;
struct Node *tail;
struct Node *temp;

int value;
char ch;


//display function
void display(struct Node *head)
{
    temp = head;

    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

//insert at begin function
void insertBegin(struct Node *newNode)
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    int value;
    printf("Insert value to be inserted at the beginning: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = head;
    head = newNode;

}


//insert at end function
void insertEnd(struct Node *newNode)
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    int value;
    printf("Insert value to be inserted at the end: ");
    scanf("%d", &value);
    newNode->data = value;
    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;

}


//insert at specific position
void insertAtPosition(struct Node *newNode)
{
    newNode = (struct Node*)malloc(sizeof(struct Node));

    int value;
    printf("Insert value: ");
    scanf("%d", &value);

    int position;
    printf("Insert position: ");
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

//delete at beginning function
void deleteBeginning(struct Node *head)
{
    temp = head;
    head = head->next;
    temp->next = NULL;

}

//delete at the end function
void deleteAtEnd(struct Node *head)
{
    temp = head;
    while(temp->next != tail)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    tail = temp;
}

//delete at given position
void deleteAtGivenPosition(struct Node *head)
{
    int position;
    printf("Enter position: ");
    scanf("%d", &position);
    temp = head;

    for(int i = 0; i<position-1; i++)
    {
        temp = temp->next;
        temp->next = temp->next->next;
    }
}

//length of linked list
int lengthOfLinkedList(struct Node *head)
{
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}


//reverse of linked list function
void Reverse(struct Node *newNode)
{
    struct Node *current, *next, *prev = NULL;
    current = head;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

}


int main()
{

    do
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter a value: ");
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
        }

        printf("Y - Continue, N - Exit: ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'Y');


    printf("***Before Reversing***\n");
    display(head);
    /*
    insertBegin(head);
    printf("***After Inserting at beginning***\n");
    display(head);
    */

    /*
    insertEnd(head);
    printf("***After Inserting at end***\n");
    display(head);
    */

    /*
    insertAtPosition(head);
    printf("***After Inserting at desired position***\n");
    display(head);
    */

    /*deleteAtGivenPosition(head);
    printf("***After Deleting at given position***\n");
    display(head);
    */

    /*int result;
    result = lengthOfLinkedList(head);
    printf("Length of linked list is: %d", result);
    */


    Reverse(head);
    printf("***After Reverse of linked list***\n");
    display(head);





    return 0;
}
