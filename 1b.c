#include<stdio.h>

int sumElements(int *arr, int n){
    int sum = 0,i;
    for(i=0; i<=n-1; i++){
        sum = sum + arr[i];
    }
    return (sum);
}

int main(){
    int arr[1000],i,n;
    int total;

    printf("Enter the size of array:\n");
    scanf("%d",&n);

    printf("Enter the elements of array:\n");

    for(i=0; i<=n-1; i++){
        scanf("%d",&arr[i]);

    }
    total = sumElements(arr,n);
    printf("sum of elements is %d",total);
}