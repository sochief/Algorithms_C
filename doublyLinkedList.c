#include <stdio.h>
#include <stdlib.h>

// Node of a doubly linked list
// DLL -- doubly linked list
struct Node
{
    int data;
    struct Node* next; // pointer to next node in DLL
    struct Node* prev;
    /* data */
};

// Add a node in the front of the DLL
/* Given a reference (pointer to pointer) to the head of a list 
and int, inserts a new node on the front of the list */
void addToBeginning(struct Node** head_ref, int new_data ){
    // Allocate node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Put in a new data
    new_node -> data = new_data;

    // Make next node as head and prev as NULL
    new_node -> next = (*head_ref);
    new_node -> prev = NULL;
    // Change previous of head node to the new node
    if ((*head_ref)!=NULL){
        (*head_ref) -> prev = new_node;
    }

    // Move the head to point to the new node
    (*head_ref) = new_node;
}


// Insert a node after
void insertAfter(struct Node* prev_node, int new_data)
{
    // Check wheteher the given prev_node is NULL
    if(prev_node == NULL){
        printf(" The given previous node cannot be NULL");
        return;
    }
    // allocate new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Put in a new data
    new_node ->data = new_data;

    // Make next of new node as next of prev_node
    new_node -> next = prev_node->next;

    // Make the next of prev_node as new_node
    prev_node -> next = new_node;

    // Make prev_node as previous of new node
    new_node -> prev = prev_node;

    // Change previous of new_node's next node
    if(new_node -> next != NULL){
        new_node -> next -> prev = new_node;
    }
}

void instertBefore(struct Node** head_ref,struct Node* next_node, int new_data){
    // check if the given next_node if NULL
    if(next_node == NULL){
        printf("The given next node cant be null!");
        return;
    }
    //allocate a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // insert a new data
    new_node ->data = new_data;

    //make prev of new_node as prev of next_node
    new_node -> prev = next_node -> prev;

    //make prev of next_node as new_node
    next_node -> prev = new_node;

    // make next_node as next of new_node
    new_node -> next = next_node;

    //change next of new_node's previous node
    if(new_node -> prev != NULL){
        new_node -> prev -> next = new_node;
    }
    //and if it doesn't exist we make it head
    else
    {
        (*head_ref) = new_node;
    }
}



// Add a node in the end:

void addInTheEnd(struct Node** head_ref, int new_data){
    // Allocate the node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref; //will use later

    // put in new data

    new_node -> data = new_data;
    // make the next of the node as last
    new_node -> next = NULL;
    //if the linked list is empty, then we make the new node as head
    if(*head_ref == NULL){
        new_node -> prev = NULL;
        *head_ref = new_node;
        return;
    }
    // else, traverse till the last node
    while (last -> next != NULL)
    {
        last = last -> next;
    }
    // change the next of last node
    last -> next = new_node;
    // make the last node as previous of a new node
    new_node -> prev = last;
}

void printList(struct Node* node){
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ",node -> data);
        last = node;
        node = node -> next;
    }
    printf("/nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ",last -> data);
        last = last -> prev;
    }
}