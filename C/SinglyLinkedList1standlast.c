#include<stdio.h>
#include<stdlib.h>

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

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
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

void InsertLast(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL) 
    {
        *first = newn;
    }
    else                       
    {
        PNODE i = *first;

        while (i->next != NULL)
        {
            i = i->next;
        }

        i->next = newn;
    }
}


int main()
{
    PNODE head = NULL;

    InsertFirst(&head,51);

    InsertFirst(&head,21);

    InsertFirst(&head,11);

    Display(head);

    InsertLast(&head , 101);

    Display(head);

    return 0;

}