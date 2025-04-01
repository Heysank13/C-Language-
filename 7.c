#include <stdio.h>
#include <stdlib.h>
#define N 5
int q[N];
int front = -1;
int rear = -1;

void enqueuefront(void);
void enqueuerear(void);
void dequeuefront(void);
void dequeuerear(void);
void display(void);
void getfront(void);
void getrear(void);

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
        printf("5.Display all elements of deque \n");
        printf("6.Get front element of deque \n");
        printf("7.Get rear element of deque \n");
        printf("8.Quit \n");
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
            getfront();
            break;
        case 7:
            getrear();
            break;
        case 8:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    } while (1);
}

void enqueuefront()
{
    int x;
    printf("Enter the value of x:\n");
    scanf("%d", &x);

    if (front == ((rear + 1) % N))
    {
        printf("Deque is Full\n");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[front] = x;
        printf("Entered number in Deque is: %d\n", q[front]);
    }

    else if (front == 0)
    {
        front = N - 1;
        q[front] = x;
        printf("Entered number in Deque is: %d\n", q[front]);
    }
    else
    {
        front--;
        q[front] = x;
        printf("Entered number in Deque is: %d\n", q[front]);
    }
}

void enqueuerear()
{
    int x;
    printf("Enter the value of x:\n");
    scanf("%d", &x);

    if (front == ((rear + 1) % N))
    {
        printf("Deque is Full\n");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear] = x;
        printf("Entered number in Deque is: %d\n", q[rear]);
    }

    else if (rear == N - 1)
    {
        rear = 0;
        q[rear] = x;
        printf("Entered number in Deque is: %d\n", q[rear]);
    }
    else
    {
        rear++;
        q[rear] = x;
        printf("Entered number in Deque is: %d\n", q[rear]);
    }
}

void dequeuefront()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty\n");
    }
    else if (front == rear)
    {
        printf("Deleted number from Deque is: %d\n", q[front]);
        front = rear = -1;
    }
    else if (front == N - 1)
    {
        printf("Deleted number from Deque is: %d\n", q[front]);
        front = 0;
    }
    else
    {
        printf("Deleted number from Deque is: %d\n", q[front]);
        front++;
    }
}

void dequeuerear()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty\n");
    }
    else if (front == rear)
    {
        printf("Deleted number from Deque is: %d\n", q[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("Deleted number from Deque is: %d\n", q[rear]);
        rear = N - 1;
    }
    else
    {
        printf("Deleted number from Deque is: %d\n", q[rear]);
        rear--;
    }
}

void getfront()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty");
    }
    else
    {
        printf(" Front element of Deque is: %d", q[front]);
    }
}

void getrear()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty");
    }
    else
    {
        printf(" Rear element of Deque is: %d", q[rear]);
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Deque is Empty\n");
    }
    else
    {
        printf("Deque is:\n");
        while (i != rear)
        {
            printf(" %d ", q[i]);
            i = ((i + 1) % N);
        }
        printf("%d", q[rear]);
    }
}