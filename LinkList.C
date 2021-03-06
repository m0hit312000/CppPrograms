#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

int length()
{
    struct Node *p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void printList()
{
    struct Node *n = head;
    if (n == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while (n != NULL)
        {
            printf("%d \n", n->data);
            n = n->next;
        }
    }
}

void push(int n)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = n;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void append(int n)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = n;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *p;
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void insertAfter(int loc, int n)
{
    struct Node *temp, *p = head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = n;
    int len, i = 1;
    len = length();
    if (loc > len)
    {
        printf("Invalid Location \n");
    }
    else
    {
        while (i < loc)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void deleteNode(int loc)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    int len = length();
    if (len < loc)
    {
        printf("Invalid Location");
    }
    else if (loc == 1)
    {
        temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        struct Node *p;
        temp = head;
        int i = 1;
        temp = head;
        while (i < loc - 1)
        {
            temp = temp->next;
            i++;
        }
        p = temp->next;
        temp->next = p->next;
        p->next = NULL;
        free(p);
    }
}

void reverseLinkList()
{
    struct Node *Prev = NULL;
    struct Node *Curr = head;
    struct Node *Next = NULL;

    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while (Curr != NULL)
        {
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }
        head = Prev;
    }
}

struct Node *fixReverse(int n, struct Node *root)
{
    struct Node *Prev = NULL;
    struct Node *Curr = root;
    struct Node *Next = NULL;
    int count = 0;

    while (Curr != NULL && count < n)
    {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
        count++;
    }
    if (Next != NULL)
    {
        root->next = fixReverse(3, Next);
    }
    return Prev;
}

void nodeSwap(int x, int y)
{
    if (x == y)
    {
        return;
    }
    struct Node *currX = head, *prevX = NULL;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    struct Node *currY = head, *prevY = NULL;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
    {
        return;
    }

    if (prevX != NULL)
    {
        prevX->next = currY;
    }
    else
    {
        head = currY;
    }

    if (prevY != NULL)
    {
        prevY->next = currX;
    }
    else
    {
        head = currX;
    }

    struct Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

int main()
{
    push(2);
    push(1);
    append(3);
    append(5);
    insertAfter(3, 4);
    append(6);
    append(7);
    append(8);
    append(9);
    printList();
    // deleteNode(1);
    // deleteNode(4);
    // reverseLinkList();
    // printList();
    // head = fixReverse(3, head);
    nodeSwap(5, 8);
    printList();

    return 0;
}