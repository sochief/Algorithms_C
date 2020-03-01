#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct node *next;
};

void printList(struct Node* n){
    while ( n!= NULL)
    {
        printf(" %d ", n -> data);
        n = n -> next;
    }
};

struct Node* head = NULL;
struct Node* second = NULL;
struct Node* third = NULL;


// Allocate 3 nodes in the heap
int main(){
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data in first node
    head -> data = 1;
    // Link first node with second
    head -> next = second;

    // Assign data to the second node
    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL;


    printList(head);
}