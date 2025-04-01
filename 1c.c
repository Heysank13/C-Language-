#include<stdio.h>

struct books
{
    char name[100];
    char author[100];
    int id;
    int price;
};

void display(struct books b);


void display(struct books b)
{
    printf("Book name:%s",b.name);
    printf("Author name:%s",b.author);
    printf("Book id number:%d",b.id);
    printf("Book price:%d",b.price);
}

int main()
{
    int n,i;
    struct books b[100];
    printf("Enter the number of books:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter book name:\n");
        scanf("%s",b[i].name);
        printf("Enter author name:\n");
        scanf("%s",b[i].author);
        printf("Enter book id number:\n");
        scanf("%d",&b[i].id);
        printf("Enter the book price:\n");
        scanf("%d",&b[i].price);
    }
    for(i=0;i<n;i++)
    {
        printf("\nBook #%d detail:\n",(i+1));
        display(b[i]);
    }
}
