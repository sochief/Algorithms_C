#include <stdio.h>
// Function to find smallest element in the array

void swap(int arr[],int firstIndex,int secondIndex){
    int temp;
    temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
}

int indexOfMinimum(int arr[],int startIndex,int n){
    int minValue = arr[startIndex];
    int minIndex = startIndex;
    for (int i = minIndex;i<n;i++){
        if(arr[i]<minValue){
            minIndex = i;
            minValue = arr[i];
        }
    }
    return minIndex;
}

void selectionSort(int arr[],int n){
    for(int i = 0; i < n ; i++){
        int index = indexOfMinimum(arr,i,n);
        swap(arr,i,index);
    }
}

void printArray(int arr[],int n){
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
void getArray(int arr[],int n){
    for(int i = 0 ; i < n; i++){
        printf("Print the number of an element with a number %d \n",i+1);
        scanf("%d",&arr[i]);
    }
}

int main(){
    int arr[100],n;
    printf("Enter the number of the elements in the array:\n");
    scanf("%d",&n);
    getArray(arr,n);
    selectionSort(arr,n);
    printArray(arr,n);
    return 0;
}