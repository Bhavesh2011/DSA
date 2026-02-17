#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
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

void InsertLast(PPNODE first , int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while((temp -> next) != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
    } 
}

void DeleteFirst(PPNODE first)
{
    if((*first) == NULL)
    {
        printf("The List Is empty");
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
    PNODE temp = *first;

    if((*first) == NULL)
    {
        printf("The List Is empty");
        return;
    }
    if(temp->next->next == NULL)
    {
        PNODE temp2 = temp->next;
        temp->next = NULL;
        free(temp2);

    }
    else
    {
        
        PNODE temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        PNODE temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
    }
}

void InsertAtPos(PPNODE first , int no , int pos)
{
    PNODE newn = NULL;
    PNODE temp = *first;
    int i = 1;

    newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newn->data = no;
    newn->next = NULL;

    if(pos == 1)
    {
        newn->next = *first;
        *first = newn;
        return;
    }

    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }

    newn->next = temp->next;
    temp->next = newn;
}

void DeleteAtPos(PPNODE first, int pos)
{
    PNODE temp = *first;
    PNODE target = NULL;
    int i = 1;

    if(*first == NULL)
    {
        return;
    }

    if(pos == 1)
    {
        *first = temp->next;
        free(temp);
        return;
    }

    while(i < pos-1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    target = temp->next;
    temp->next = target->next;
    free(target);
}


void Display(PNODE first)
{
    PNODE temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
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

    InsertFirst(&head , 51);
    InsertFirst(&head , 21);
    InsertFirst(&head , 11);
    Display(head);

    InsertLast(&head , 101);
    InsertLast(&head , 111);
    InsertLast(&head , 121);
    Display(head);

    // DeleteFirst(&head);
    Display(head);

    // DeleteLast(&head);
    Display(head);

    InsertAtPos(&head, 31, 3);
    Display(head);

    DeleteAtPos(&head,3);
    Display(head);

    iRet = CountNode(head);
    printf("Number Of Nodes Are : %d", iRet);

    return 0;
}