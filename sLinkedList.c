#include <stdio.h>
#include <stdlib.h>
int count = 0;

void create(void);
void traverse(void);
void Count(void);
void search(void);
void insertbeg(void);
void insertend(void);
void insertbet(void);
void delbeg(void);
void delend(void);
void delbet(void);


struct node
{
    int data;
    struct node *next;

} *head, *first, *temp;

void main()
{
    int ch;
    first = 0, temp = 0;
    do
    {
        printf("\n 1.Create\n 2.Traverse\n 3.Count\n 4.Search\n 5.insertBeg\n 6.insertEnd\n 7.insertBet\n 8.delBeg\n 9.delEnd\n 10.delBet\n 11.Exit\n");
        printf("Enter your choice:\n");
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
            Count();
            break;
        case 4:
            search();
            break;
        case 5:
            insertbeg();
            break;
        case 6:
            insertend();
            break;
        case 7:
            insertbet();
            break;
        case 8:
            delbeg();
            break;
        case 9:
            delend();
            break;
        case 10:
            delbet();
            break;
        case 11:
            exit(1);
        default:
            printf("Enter a valid choice:\n");
        }
    } while (1);
}

void create()
{

    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data\n");
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
}

void traverse()
{  head -> next = 0;
    temp = first;
    while (temp != 0)
    {
        printf("Elements of Linked List is : %d\n", temp -> data);
        temp = temp -> next;
    }
}

void Count(){
    int count = 0;
    temp = first;
    while(temp != 0){
        count++;
        temp = temp -> next;

    }
    printf("Total Nodes in Linked List is: %d\n",count);
}

void search(){
    int s, flag = 0, position = 0;

    printf("Enter Search Element:\n");
    scanf("%d",&s);

    temp = first;
    while(temp != 0){
        position++;
        if(temp -> data == s){
            flag = 1;
            break;
        }
        else{
            flag = 0;
        }
        temp = temp -> next;
    }
    if(flag == 1){
        printf("Element found at %d position\n",position);
    }
    else{
        printf("Not found...!\n");
    }
}

void insertbeg(){
    struct node *new;

    if(first == 0){
        create();
    }
    else{
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d",&new -> data);
        new -> next = 0;
        new -> next  = first;
        first = new;

    }
}

void insertend(){
    struct node *new;
    if(first == 0){
        create();
    }
    else{
        new =(struct node*)malloc(sizeof(struct node));

        printf("Enter Data:\n");
        scanf("%d",&new -> data);
        new -> next = 0;
        head -> next = new;
        head = new;
    }
}

void insertbet(){
    struct node *new;
    int position, i=1;
    printf("Enter the Position:\n");
    scanf("%d",&position);
    Count();

    if(position == 0){
        printf("Invalid Position:\n");
    }
    else if(position = 1){
        insertbeg();
    }
    else if(position > count){
        insertend();
    }
    else{
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d",&new -> data);
        new -> next = 0;
        temp = first;
        while(i < position-1){
            temp = temp -> next;
            i++;
        }
        new -> next = temp -> next;
        temp -> next = new;
    }
}

void delbeg(){
    if(first == 0){
        printf("First create linked list:\n");
    }
    else{
        temp = first;
        first = first -> next;
        free(temp);
    }
}

void delend(){
    struct node *prev;
    temp = first;
    if(first == 0){
        printf("First create linked list:\n");
    }
    else if(first == head){
        first = 0;
        free(temp);
    }
    else{
        while(temp -> next != 0){
            prev = temp;
            temp = temp -> next;
        }
        head = prev;
        free(temp);
    }
}

void delbet(){
    struct node *newnext;
    int pos, i = 1;
    printf("Enter Data:\n");
    scanf("%d",&pos);

    if(pos == 0){
        printf("Invalid position\n");
    }

    else if(pos == 1){
        delbeg();
    }
    else if(pos == count){
        delend();
    }
    else{
        temp = first;
        while(i < pos-1){
            temp = temp -> next;
            i++;
        }
        newnext = temp -> next;
        temp -> next = newnext -> next;
        free(newnext);
    }
}