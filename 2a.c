#include<stdio.h>

int sumDigits(int n){
    if(n == 0){
        return 0;
    }
    return(n % 10 + sumDigits(n / 10));
}

int main(){
    int n, sum;
    printf("Enter the number:\n");
    scanf("%d",&n);

    sum = sumDigits(n);
    printf("Sum of Digits of %d is: %d",n,sum);
}