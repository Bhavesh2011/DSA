#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertAtFirst(PPNODE first , int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

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

void InsertAtLast(PPNODE first , int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
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

void DeleteFirst(PPNODE first)
{
    if((*first) == NULL)
    {
        printf("Linked List is Empty");
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
    if(*first == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }

    if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
        return;
    }

    PNODE temp = *first;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |-> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int CountNode(PNODE first)
{
    int iCnt = 0;

    while(first != NULL)
    {
        iCnt++;
        first = first->next;
    }
    return iCnt;
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;
    InsertAtFirst(&head,101);
    InsertAtFirst(&head,51);
    InsertAtFirst(&head,21);
    InsertAtFirst(&head,11);
    Display(head);
    InsertAtLast(&head,121);
    InsertAtLast(&head,151);
    Display(head);
    DeleteFirst(&head);
    Display(head);
    DeleteLast(&head);
    Display(head);
    iRet = CountNode(head);
    printf("Number Of Nodes Are : %d", iRet);
    return 0;
}
