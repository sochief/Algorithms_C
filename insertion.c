#include <stdio.h>
void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void getArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Print you element with a no.%d ", i + 1);
        scanf("%d", &arr[i]);
    }
}
void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printArray(arr, n);
}

int main()
{
    int arr[100], n;
    printf("Type the number of elements in array: ");
    scanf("%d", &n);
    getArray(arr, n);
    insertionSort(arr, n);
    return 0;
}