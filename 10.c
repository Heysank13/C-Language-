#include <stdio.h>
#include <stdlib.h>
int count = 0;

void create(void);
void traverse(void);
void countNode(void);
void insertBeg(void);
void insertEnd(void);
void insertBet(void);
void delBeg(void);
void delEnd(void);
void delBet(void);

struct node
{
    int data;
    struct node *next;
} *head = 0, *first = 0, *temp = 0;

int main()
{

    do
    {
        int ch;
        printf("\nMenu:\n");
        printf("1.Create a Circular Linked List \n");
        printf("2.Traverse a Circular Linked List \n");
        printf("3.Count the Number of Nodes \n");
        printf("4.Insert a element from Beg \n");
        printf("5.Insert a element from End \n");
        printf("6.Insert a element from Bet \n");
        printf("7.Delete a element from Beg \n");
        printf("8.Delete a element from End \n");
        printf("9.Delete a element from Bet \n");
        printf("10.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            traverse();
            break;
        case 3:
            countNode();
            break;
        case 4:
            insertBeg();
            break;
        case 5:
            insertEnd();
            break;
        case 6:
            insertBet();
            break;
        case 7:
            delBeg();
            break;
        case 8:
            delEnd();
            break;
        case 9:
            delBet();
            break;
        case 10:
            exit(1);
        default:
            printf("Enter a Valid Choice");
        }
    } while (1);
}

void create()
{
    head = (struct node *)malloc(sizeof(struct node));

    printf("Enter the Data:\n");
    scanf("%d", &head->data);

    if (first == 0)
    {
        first = temp = head;
    }
    else
    {
        temp->next = head;
        temp = head;
    }
    head->next = first;
}

void traverse()
{
    temp = first;
    while (temp->next != first)
    {
        printf(" %d", temp->data);

        temp = temp->next;
    }
    printf(" %d", temp->data);
}

void countNode()
{
        temp = first;
while (temp -> next != first)
    {
            temp = temp->next;
        count++;
    }
    printf("\nTotal Nodes in Linked List is: %d\n", count+1);
}



void insertBeg()
{
    struct node *new;

    if (first == 0)
    {
        create();
    }
    else
    {
        new = (struct node *)malloc(sizeof(struct node));

        printf("Enter the Data:\n");
        scanf("%d", &new->data);

        new->next = 0;
        new->next = first;
        first = new;
        head->next = first;
    }
}

void insertEnd()
{
    struct node *new;

    if (first == 0)
    {
        create();
    }
    else
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Data:\n");
        scanf("%d", &new->data);

        new->next = 0;
        head->next = new;
        head = new;
        head->next = first;
    }
}

void insertBet()
{
    struct node *new;

    int pos, i = 1;
    printf("Enter the Position:\n");
    scanf("%d", &pos);
    traverse();
    if (pos < 1)
    {
        printf("Invalid Position");
    }
    else if (pos == 1)
    {
        insertBeg();
    }
    else if (pos == count + 1)
    {
        insertEnd();
    }
    else
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Data:\n");
        scanf("%d", &new->data);

        new->next = 0;
        temp = first;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void delBeg()
{
    if (first == 0)
    {
        printf("Linked List is Empty");
    }
    else
    {
        temp = first;
        first = temp->next;
        head->next = first;
        free(temp);
    }
}

void delEnd()
{
    struct node *prev;
    if (first == 0)
    {
        printf("Linked List Empty");
    }
    else if (first == head)
    {
        first = 0;
        free(temp);
    }
    else
    {
        temp = first;

        while ((struct node *)temp->next != first)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = first;
        head = prev;
        free(temp);
    }
}

void delBet()
{
    struct node *newnext;

    int pos, i;
    printf("Enter the Position:\n");
    scanf("%d", &pos);

    if (pos == 0)
    {
        printf("Invalid Position");
    }
    else if (pos == 1)
    {
        delBeg();
    }
    else if (pos == count)
    {
        delEnd();
    }
    else
    {
        temp = first;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnext = temp->next;
        temp->next = newnext->next;
        free(newnext);
    }
}
