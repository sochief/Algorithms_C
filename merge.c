#include <stdio.h>
void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printArray(int arr[],int n){
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
void getArray(int arr[],int n){
    for(int i = 0; i < n; i++){
        printf("Print you element with a no.%d ",i+1);
        scanf("%d",&arr[i]);
    }
}
void mergeSort(int arr[],int n){
    
}