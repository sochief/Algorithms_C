#include <stdio.h>
static void bubbleSort(int arr[],int n){
    int temp;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array: \n ");
    for(int j = 0;j < n; j++){
        printf("%d ",arr[j]);
    }
}

int main(){
    int arr[100],n;
    // ask user for the number of elements to be sorted:
    printf("Enter the number of the elements to be sorted: ");
    scanf("%d",&n);
    //input elements in the array:
    for (int  i = 0; i<n;i++){
        printf("Enter the element no. %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    // Call the function
    bubbleSort(arr,n);
    return 0;
}