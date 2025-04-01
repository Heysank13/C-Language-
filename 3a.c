#include<stdio.h>
#include<string.h>

union Details{
    char name[100];
    char home_address[100];
    char hostel_address[100];
    char city[100];
    char state[100];
    int zip;
    
} ;

void display( union Details x){
printf("Enter the Name:\n");
scanf("%s",x.name);
printf("Enter the Home Address:\n");
scanf("%s",x.home_address);
printf("Enter the Hostel Address:\n");
scanf("%s",x.hostel_address);
printf("Enter the City:\n");
scanf("%s",x.city);
printf("Enter the State:\n");
scanf("%s",x.state);
printf("Enter the Zip Code:\n");
scanf("%d",&x.zip);

printf("Name: %s Home Address: %s Hostel Address: %s City: %s State: %s  Zip Code: %d ", x.name , x.home_address , x.hostel_address , x.city , x.state , x.zip);

}

int main(){

union Details x;

printf("Enter the #Details:\n");


display(x);
}