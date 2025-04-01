#include <stdio.h>
#include <stdlib.h>
#define N 5
int q[N];
int front = -1;
int rear = -1;
void enqueue(void);
void dequeue(void);
void display(void);

int main()
{
    do
    {
        int ch;
        printf("\nMenu:\n");
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    } while (1);
}

void enqueue()
{
    int x;
    printf("Enter the value of x:\n");
    scanf("%d", &x);

    if (front == ((rear + 1) % N))
    {
        printf("Queue is Full\n");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear] = x;
        printf("Entered number in Queue is: %d\n", q[rear]);
    }

    else
    {
        rear = ((rear + 1) % N);
        q[rear] = x;
        printf("Entered number in Queue is: %d\n", q[rear]);
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else if (front == rear)
    {
        printf("Deleted number from Queue is: %d\n", q[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted number from Queue is: %d\n", q[front]);
        front = ((front + 1) % N);
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is:\n");
        while (i != rear)
        {
            printf(" %d ",q[i]);
            i = ((i + 1) % N);
        }
        printf("%d", q[rear]);
    }
}