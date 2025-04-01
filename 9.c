#include <stdio.h>
#include <stdlib.h>
int count = 0;

void insertFirst(void);
void insertEnd(void);
void deleteFirst(void);
void deleteEnd(void);
void display(void);

struct employee
{
    struct employee *prev;
    int ssn;
    char name[100];
    char dept[100];
    char desig[100];
    float sal;
    char phone[100];
    struct employee *next;
} *head = 0, *first = 0, *temp = 0;

int main()
{
    do
    {
        int ch;
        printf("\nMenu:\n");
        printf("1.Insert Element from Front \n");
        printf("2.Insert Element from End \n");
        printf("3.Delete element from Front\n");
        printf("4.Delete element from End\n");
        printf("5.Display the Status of SLL and Count the number of Nodes\n");
        printf("6.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFirst();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("Enter a Valid Choice");
        }
    } while (1);
}

void create()
{

    head = (struct employee *)malloc(sizeof(struct employee));

    printf("Enter the SSN Number: ");
    scanf("%d", &head->ssn);

    printf("Enter the Name of Employee: ");
    scanf("%s", head->name);

    printf("Enter the Department of Employee: ");
    scanf("%s", head->dept);

    printf("Enter the Designation of Employee: ");
    scanf("%s", head->desig);

    printf("Enter the Salary of Employee: ");
    scanf("%f", &head->sal);

    printf("Enter the Phone Number of Employee: ");
    scanf("%s", head->phone);


    head->next = 0;
    head->prev = 0;

    if (first == 0)
    {
        first = temp = head;
    }

    else
    {
        head->prev = temp;
        temp->next = head;
        temp = head;
    }
}

void insertEnd()
{
    struct employee* new;
    if(first == 0){
        create();
    }
    else{
        struct employee *new = (struct employee *)malloc(sizeof(struct employee));
        printf("Enter the SSN Number: ");
        scanf("%d", &new->ssn);

        printf("Enter the Name of Employee: ");
        scanf("%s", new->name);

        printf("Enter the Department of Employee: ");
        scanf("%s", new->dept);

        printf("Enter the Designation of Employee: ");
        scanf("%s", new->desig);

        printf("Enter the Salary of Employee: ");
        scanf("%f", &new->sal);

        printf("Enter the Phone Number of Employee: ");
        scanf("%s", new->phone);;
        new -> next = 0;
        new -> prev = 0;
        head -> next = new;
        new -> prev = head;
        head = new;
    }
}

void insertFirst()
{
    if (head == 0)
    {
        create();
    }
    else
    {
        struct employee *new = (struct employee *)malloc(sizeof(struct employee));
        printf("Enter the SSN Number: ");
        scanf("%d", &new->ssn);

        printf("Enter the Name of Employee: ");
        scanf("%s", new->name);

        printf("Enter the Department of Employee: ");
        scanf("%s", new->dept);

        printf("Enter the Designation of Employee: ");
        scanf("%s", new->desig);

        printf("Enter the Salary of Employee: ");
        scanf("%f", &new->sal);

        printf("Enter the Phone Number of Employee: ");
        scanf("%s", new->phone);

        new->next = 0;
        new ->prev = 0;
        new -> next = first;
        first -> prev = new;
        first = new;
    }
}

void deleteFirst()
{
    if (first == 0)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp = first;
        first = first->next;
        first->prev = 0;
        free(temp);
    }
}

void deleteEnd()
{
    if (first == 0)
    {
        printf("List is Empty \n");
    }
    else
    {
        temp = head;
        head -> prev ->next = 0;
        head = head -> prev;
        free(temp);
    }
}

void display()
{
    temp = first;
    while (temp != 0)
    {
        printf("SSN -> %d \n", temp->ssn);
        printf("Name -> %s \n", temp->name);
        printf("Department -> %s \n", temp->dept);
        printf("Designation -> %s \n", temp->desig);
        printf("Salary -> %f \n", temp->sal);
        printf("Phone Number -> %s \n", temp->phone);
        temp = temp->next;
        printf("\n");
    }

    int count = 0;
    temp = first;
    while (temp != 0)
    {

        temp = temp->next;
        count++;
    }
    printf("Total Nodes in Linked List is: %d\n", count);
}
