#include<stdio.h>
#include<stdlib.h>

// | Variable | What it stores                                           |
// | -------- | -------------------------------------------------------- |
// | `first`  | Address of head pointer                                  |
// | `*first` | Actual head pointer (which stores address of first node) |

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first , int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }

}

void Insertlast(PPNODE first , int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)
    {
        *first = newn;
    }
    else
    {
        PNODE temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first -> data);
        first = first -> next;
    }
    printf("\n");

}

void DeleteFirst(PPNODE first)
{
    if((*first == NULL))
    {
        printf("The List is Empty\n");
        return;
    }
    else
    {
        PNODE temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    if (*first == NULL)
    {
        printf("The List is Empty\n");
        return;
    }

    if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        return;
    }

    PNODE temp = *first;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);        
    temp->next = NULL;    
}


int main()
{
    PNODE head = NULL;

    DeleteFirst(&head);

    InsertFirst(&head,51);

    InsertFirst(&head,21);

    InsertFirst(&head,11);

    Display(head);

    Insertlast(&head , 101);

    DeleteFirst(&head);

    DeleteLast(&head);

    Display(head);


    return 0;
}