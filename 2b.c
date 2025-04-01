#include<stdio.h>

int sumNatural(int n){
    if(n <= 1){
        return n;
    }
    return(n + sumNatural(n-1));
}

int main(){
    int sum,n=20;
    sum = sumNatural(n);
    printf("Sum of first 20th natural number is: %d",sum);
}