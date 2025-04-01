#include <stdio.h>
#include <stdlib.h>

void insertFirst(void);
void insertHead(void);
void deleteFirst(void);
void deleteHead(void);
void display(void);

struct student
{
    int usn;
    char name[100];
    char branch[100];
    int sem;
    char phone[100];
    struct student *next;
} *head , *first = 0, *temp;

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
            insertHead();
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteHead();
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

    struct student *stud = (struct student *)malloc(sizeof(struct student));

    printf("Enter the USN Number: ");
    scanf("%d", &stud->usn);

    printf("Enter the Name of Student: ");
    scanf("%s", stud->name);

    printf("Enter the Branch of Student: ");
    scanf("%s", stud->branch);

    printf("Enter the Semester of Student: ");
    scanf("%d", &stud->sem);

    printf("Enter the Phone Number of Student: ");
    scanf("%s", stud->phone);

    if (head == NULL)
    {
        head = first = stud;
        head->next = NULL;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = stud;
        head = stud;
        head->next = NULL;
    }
}

void insertHead()
{
    create();
}

void insertFirst()
{
    if (head == NULL)
    {
        create();
    }
    else
    {
        struct student *stud = (struct student *)malloc(sizeof(struct student)); // Allocate memory for a new student
        printf("Enter the USN Number: ");
        scanf("%d", &stud->usn);

        printf("Enter the Name of Student: ");
        scanf("%s", stud->name);

        printf("Enter the Branch of Student: ");
        scanf("%s", stud->branch);

        printf("Enter the Semester of Student: ");
        scanf("%d", &stud->sem);

        printf("Enter the Phone Number of Student: ");
        scanf("%s",stud->phone);

        stud->next = first;
        first = stud;
    }
}


void deleteHead() {
	if (head == NULL) {
		printf("Can't Delete\n");
	} else {
		temp = first;
		struct student *pre = NULL;
		while (temp -> next!= NULL) {
			pre = temp;
			temp = temp -> next;
		}
		free(temp);
		head = pre;
		head -> next = NULL;
	}
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("Can't Delete\n");
    }
    else
    {
        temp = first->next;
        free(first);
        first = temp;
    }
}

void display()
{
    temp = first;
    while (temp != NULL)
    {
        printf("USN -> %d \n", temp->usn);
        printf("Name -> %s \n", temp->name);
        printf("Branch -> %s \n", temp->branch);
        printf("Sem -> %d \n", temp->sem);
        printf("Phone Number -> %s \n", temp->phone);
        temp = temp->next;
        printf("\n");
    }

    int count = 0;
    temp = first;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    printf("Total Nodes in Linked List is: %d\n", count);
}
