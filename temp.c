#include<stdio.h>
#include<stdlib.h>
int count = 0;

struct node {
    char ssn[10];
    char name[50];
    char dept[10];
    char desig[50];
    int salary;
    char phno[10];
    struct node* next;
    struct node* prev;
}*temp = 0,*head = 0,*first = 0;

void create(){
    head = (struct node*) malloc(sizeof(struct node));
    printf("Enter your SSN number : ");
    scanf("%s" , &head -> ssn);
    printf("Enter your Name : ");
    scanf("%s" , &head -> name);
    printf("Enter your Department : ");
    scanf("%s" , &head -> dept);
    printf("Enter your Designation : ");
    scanf("%s" , &head -> desig);
    printf("Enter your Salary : ");
    scanf("%d" , &head -> salary);
    printf("Enter your Phone number : ");
    scanf("%s" , &head -> phno);
    head -> prev = 0;
    head -> next = 0;
    if(first == 0){
        first = temp = head;
    }
    else{
        head -> prev = temp;
        temp -> next = head;
        temp = head;
    }
}

void countNode(){
    temp = first;
    count = 0;
    while (temp != 0)
    {
        temp = temp -> next;
        count++;
    }
    printf("Number of nodes : %d \n",count);
}

void display(){
    temp = first;
    int i=1;
    while(temp != 0){
        printf("Data %d : \n",i);
        printf("\t  your SSN number : %s \n" , temp -> ssn);
        printf("\t  your Name : %s \n" , temp -> name);
        printf("\t  your Department : %s \n" , temp -> dept);
        printf("\t  your Designation : %s \n" , temp -> desig);
        printf("\t  your Salary : %d \n" , temp -> salary);
        printf("\t  your Phone number : %s \n" , temp -> phno);
        temp = temp -> next;
        i++;
    }
}

void insertBegin(){
    struct node* new;
    if(first == 0){
        create();
    }
    else{
        new = (struct node*) malloc(sizeof(struct node));
        printf("Enter your SSN number : ");
        scanf("%s" , &new -> ssn);
        printf("Enter your Name : ");
        scanf("%s" , &new -> name);
        printf("Enter your Department : ");
        scanf("%s" , &new -> dept);
        printf("Enter your Designation : ");
        scanf("%s" , &new -> desig);
        printf("Enter your Salary : ");
        scanf("%d" , &new -> salary);
        printf("Enter your Phone number : ");
        scanf("%s" , &new -> phno);
        new -> next = 0;
        new -> prev = 0;
        new -> next = first;
        first -> prev = new;
        first = new;
    }
}

void insertEnd(){
    struct node* new;
    if(first == 0){
        create();
    }
    else{
        new = (struct node*) malloc(sizeof(struct node));
        printf("Enter your SSN number : ");
        scanf("%s" , &new -> ssn);
        printf("Enter your Name : ");
        scanf("%s" , &new -> name);
        printf("Enter your Department : ");
        scanf("%s" , &new -> dept);
        printf("Enter your Designation : ");
        scanf("%s" , &new -> desig);
        printf("Enter your Salary : ");
        scanf("%d" , &new -> salary);
        printf("Enter your Phone number : ");
        scanf("%s" , &new -> phno);
        new -> next = 0;
        new -> prev = 0;
        head -> next = new;
        new -> prev = head;
        head = new;
    }
}

void deleteBegin(){
    if(first == 0){
        printf("Khali hai \n Pahle dal le \n");
    }
    else{
        temp = first;
        first = first -> next;
        first -> prev = 0;
        free(temp);
    }
}

void deleteEnd(){
    if(first == 0){
        printf("Khali hai \n Pahle dal le \n");
    }
    else{
        temp = head;
        head = head -> next;
        head -> prev = 0;
        free(temp);
    }
}

int main(){
    int k;
    printf("\t1.Insert at Begin \n\t2.Insert at End \n\t3.Delete fron Begin \n\t4.Delete from End \n\t5.Count Nodes \n\t6.Display Nodes \n\t7.Exit \n");
    do{
        printf("Enter your choice : ");
        scanf("%d",&k);
        switch (k)
        {
        case 1:
            insertBegin();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            deleteBegin();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            countNode();
            break;
        case 6:
            display();
            break;
        case 7:
            printf("You exited successfully \n");
            break;
        default:
            printf("Enter valid number \n");
            break;
        }
    }while(k!=7);
    return 0;
}