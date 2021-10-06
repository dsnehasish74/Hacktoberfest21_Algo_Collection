#include<stdio.h> 

void main(){
    int arr[10] , n, i , j , temp;
    printf("Enter the number of elements : ");
    scanf ("%d",&n);
    for (i=0;i<n;i++){
        printf("arr[%d] = " , i);
        scanf("%d", &arr[i]);
    }
    for (i=0;i<n-1;i++){
        for (j=0;j<n-1;j++){
            if (arr[j+1] < arr[j]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("The sorted array is : \n");
     for (i=0;i<n;i++){
        printf("%d \n" , arr[i]);
    }
}