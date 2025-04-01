#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int q[MAX];
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
        printf("\n1.Insert element to queue \n");
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

    int isFull(){
        if (rear == MAX - 1)
        {
            return 1;
        }
        return -1;
    }

    void enqueue()
    {
        int x;
        printf("Enter the value of x:\n");
        scanf("%d", &x);

        if (isFull() == 1)
        {
            printf("Queue is Overflow");
        }

        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            q[rear] = x;
        }
        else
        {
            rear++;
            q[rear] = x;
        }
    }

    int isEmpty(){
        if (front == -1 && rear == -1)
        {
            return 1;
        }
        return -1;
    }

    void dequeue()
    {
        if (isEmpty() == 1)
        {
            printf("Queue is Underflow");
        }

        else if (front == rear)
        {
            printf("%d", q[front]);
            front = rear = -1;
        }
        else
        {
            printf("%d", q[front]);
            front++;
        }
    }

    void display()
    {
        int i;
        if (front == -1 && rear == -1)
        {
            printf("Queue is empty");
        }
        else
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d", q[i]);
            }
        }
    }