#include <stdio.h>
#include <stdlib.h>

void enqueuefront(void);
void enqueuerear(void);
void dequeuefront(void);
void dequeuerear(void);
void display(void);

struct node
{
    int data;
    struct node *next;
};

int main()
{
    do
    {
        int ch;
        printf("\nMenu:\n");
        printf("1.Insert element to deque from Front \n");
        printf("2.Insert element to deque from Rear \n");
        printf("3.Delete element from deque from Front \n");
        printf("4.Delete element from deque from Rear \n");
        printf("5.Display the deque elements\n");
        printf("6.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueuefront();
            break;
        case 2:
            enqueuerear();
            break;
        case 3:
            dequeuefront();
            break;
        case 4:
            dequeuerear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);

        default:
            printf("Enter a valid choice");
        }
    } while (1);
}

void enqueuerear()
{
    int x;
    printf("Enter a data:\n");
    scanf("%d", &x);
    struct node *front, *rear, *temp;
    if (front == NULL)
    {
        front = malloc(sizeof(struct node));
        front->data = x;
        front->next = NULL;
        rear = front;
    }
    else
    {
        temp = malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
}

void enqueuefront()
{
    struct node *front, *rear, *temp;
    int x;
    printf("Enter a data:\n");
    scanf("%d", &x);
    if (front == NULL)
    {
        front = malloc(sizeof(struct node));
        front->data = x;
        front->next = NULL;
        rear = front;
    }
    else
    {
        struct node *temp;
        temp = malloc(sizeof(struct node));
        temp->data = x;
        temp->next = front;
        front = temp;
    }
}

void dequeuefront()
{
    struct node *front, *rear;
    if (front == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        printf("Delete Value %d", temp->data);
        free(temp);

        if (front == NULL)
            rear = NULL;
    }
}

void dequeuerear()
{
    struct node *front;
    struct node *rear;
    struct node *l = front;
    if (front == NULL)
    {
        printf("\n Deque is Empty");
    }
    else if (front->next == NULL)
    {
        printf("Delete element %d", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        for (l = front; l->next != rear; l = l->next)
        {
            printf("Delete element %d", rear->data);
            free(rear);
            l->next = NULL;
            rear = l;
        }
    }
    return;
}

void display()
{
    struct node *front, *next, *temp, *head, *first;
    if (front == NULL)
    {
        printf("Deque is Empty");
    }
    // else
    // {
    // for (struct node *l = front; l != NULL; l = l->next)
    //{
    //  printf("%d", l->data);
    // }
    //   printf("NULL");

    // }
    else
    {
        head->next = 0;
        temp = first;
        while (temp != 0)
        {
            printf("Elements of Linked List is : %d\n", temp->data);
            temp = temp->next;
        }
    }
}