#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXIMUM  100
/* Shafkat Nurtdinov St.No: 16011141 
В каждом узле:
1) Адрес страницы.(DONE)
2) Количество запросов(DONE)
3) next previous(DONE)
Функции:
1) Навигация по узлам(Вывести все nodes)(TO DO)
2) Вывести счётчик запросов(Find out!)
3) Add-delete operations(Almost check!)
4) Input -- .txt(Almost check!)
5) If the address is not in the buffer -- create a node for that
    if it is -- increase a requests counter
        if the counter exceeds threshold:
            make it head
also, there is a volume limit of cache - L
    if the volume is more than L -- delete the last node
In the end of the day, ask user does he want to delete the cache after all og the actions. If user wants to quit, erase everythong.
Use doubly linked lists!
*/
struct Node{
    char address;
    int requests;
    struct Node* next;
    struct Node* prev;
};

//Add a check for biggest request
//Add a node in the beginning



void addNewRequest(struct Node** head_ref, char address,int requests){
    // Allocate node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Put in a new everything
    new_node -> address = address;
    new_node -> requests = requests;
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

void printForward(struct Node* node){
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf( "The address of the page is:%c\n ",last -> address);
        printf( "An amount of the requests is:%d\n", last -> requests);
        last = node;
        node = node -> next;
    }}
void printReverse(struct Node* node){
    struct Node* last;
    printf("/nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf( "The address of the page is:%c\n ",last -> address);
        printf( "An amount of the requests is:%d\n", last -> requests);
        last = last -> prev;
    }
}
void deleteNode(struct Node** head_ref, struct Node* del){
    if(head_ref == NULL || del == NULL){
        return;
    }
    // check if its a head node
    if(*head_ref == del){
        *head_ref = del -> next;
    }
    //if the node is not the last one
    if(del -> next != NULL){
        del -> next -> prev = del -> prev;
    }
    // change prev if node is not the first one
    if(del -> prev != NULL){
        del -> prev -> next = del -> next;
    }
    // free up the memory
    free(del);
    return;
}
// Read in the data
int main(){
    char data;
    //data = fopen("data.txt","r");
}