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

void InsertAtFirst(PPNODE first, int no)
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

void InsertAtLast(PPNODE first , int no)
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
        PNODE temp = NULL;
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;

    }
}

void Display(PNODE first)
{
    PNODE temp = first;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int CountNode(PNODE first)
{
    int iCnt = 0;
    PNODE temp = first;
    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

void InsertAtPos(PPNODE first , int no , int pos)
{
    if(pos <= 0)
    {
        printf("Invalid Position\n");
        return;
    }

    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(pos == 1)
    {
        // InsertAtFirst(PPNODE first, int no);
    }

    PNODE temp = *first;
    int i = 1;

    while(i < pos-1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    newn->next = temp->next;
    temp->next = newn;
}

void DeleteAtPos(PPNODE first , int pos)
{
    int i = 1;
    if(pos < 0)
    {
        printf("Invalid Position");
        return;
    }

    PNODE temp = *first;

    while(i < pos -1)
    {
        temp = temp ->next;
        i++;
    }

    PNODE temp2 = temp->next;
    temp->next = temp ->next->next;
    free(temp2);

}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertAtFirst(&head , 51);
    InsertAtFirst(&head , 21);
    InsertAtFirst(&head , 11);

    Display(head);

    InsertAtLast(&head,101);
    InsertAtLast(&head,111);

    Display(head);

    iRet = CountNode(head);
    printf("%d",iRet);

    InsertAtPos(&head,31,3);

    Display(head);

    iRet = CountNode(head);
    printf("%d",iRet);

    DeleteAtPos(&head , 3);
    Display(head);

    iRet = CountNode(head);
    printf("%d",iRet);

    return 0;
}