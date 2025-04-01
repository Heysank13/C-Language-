#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;

void pop(void);
void push(void);
void display(void);
void isPalindrome(void);

void main()
{
    int ch;
    do
    {
        printf("\nMenu:\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Display Stack\n");
        printf("4. Check Palindrome\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            isPalindrome();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (1);
}


int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    return -1;
}

void push()
{
    if (isFull() == 1)
    {
        printf("Stack is Overflow");
    }
    else
    {   int x;
        printf("Enter the value of x:\n");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("%d Pushed onto the stack.\n", x);
    }
}

int isEmpty(){
    if (top == -1)
    { return 1;
    }
    return -1;
}

void pop()
{
    int item;
    if (isEmpty() == 1)
    {
        printf("Stack is Underflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf("%d Popped from the stack.\n",item);
    }
}



void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void isPalindrome()
{
    int i, j;
    for (i = 0, j = top; i <= j; i++, j--)
    {
        if (stack[i] != stack[j])
        {
            printf("Not a Palindrome.\n");
            return;
        }
    }
    printf("Palindrome.\n");
}

