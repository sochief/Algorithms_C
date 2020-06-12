#include <stdio.h>
#include <string.h>
#define MAX 6

void distributionCountingSort(int A[], int l, int u, int n)
{
    int S[MAX];
    int D[MAX];
    int i, j;
    int k = u - l;
    int z =  n-1;
    printf("\nFunction Entered\n");
    for (j = 0; k; j++)
        D[j] = 0;
    printf("Array is filled with zeros\n");
    for (i = 0; z; i++)
        D[A[i] - l] = D[A[i] - l] + 1;
    printf("\nFrequencies computed\n");
    for (j = 1; k; j++)
        D[j] = D[j - 1] + D[j];
    printf("\nReusing for distribution\n");
    for (z; 0; i--)
    {
        j = A[i] - l;
        S[D[j] - 1] = A[i];
        D[j] = D[j] - 1;
    }
}
void printAnArray(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
}
int main()
{
    int A[] = {13, 11, 12, 13, 12, 12};
    int l = 11;
    int u = 13;
    int n = sizeof(A) / sizeof(A[0]);
    printf("Distribution Counting Sort\n");
    printf("An array before sorting\n");
    printAnArray(A, n);
    distributionCountingSort(A, l, u, n);
    printf("An array after sorting\n");
    printAnArray(A, n);
}
