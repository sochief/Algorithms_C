#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXIMUM  1024
// L = Volume T = threshold
#define VOLUME 4
#define THRESHOLD 3
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

typedef struct node{
    char address;
    int requests;
    struct node* next;
    struct node* prev;
} Node;

typedef struct llist{
    struct node **head;
    struct node **tail;
    int len;

} LLIST;


// Read in the data
int main(int argc,char *argv[]){
    LLIST *llist;
    llist = (LLIST*)malloc(sizeof(LLIST));
    Node** head;
    head = (Node**) malloc(sizeof(Node *));

    char line[MAXIMUM];
    char element;
    int i;
    char *tok, *delim;
    delim = " ";
    FILE *fptr;
    fptr = fopen("data.txt","r");
    if (fptr == NULL){
        printf("Error opening a file!");
        exit(1);}
        while (fgets(line,MAXIMUM,fptr)){
            tok = strtok(line, delim);
            processToken(tok,llist);
            while(tok = strtok(NULL, delim))
                processToken(tok,llist);
        }
        fclose(fptr);
        return 0;
}







//Add a check for biggest request
//Add a node in the beginning

void addToBeginning(Node** head_ref,char new_address,int new_requests){
    // Allocate node
    Node* new_node;

    new_node = (Node*)malloc(sizeof(Node));

    // put in new data
    new_node -> address = new_address;
    new_node -> requests = new_requests;


    // make next next node as prev and prev as null
    new_node -> next = (*head_ref);
    new_node -> prev = NULL;

    // change previous of head node to the new node
    if((*head_ref) != NULL){
        (*head_ref) -> prev = new_node;
    }
    // move the head to point to the new node
    (*head_ref) = new_node;
}

void printForward(Node* node){
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf( "The address of the page is:%c\n ",node -> address);
        printf( "An amount of the requests is:%d\n", node -> requests);
        node = node -> next;
    }
}


void printRevHelper(Node* node){
    if(node == NULL) return;

    printRevHelper(node -> next);
    printf( "The address of the page is:%c\n ",node -> address);
    printf( "An amount of the requests is:%d\n", node -> requests);
}
void printReverse(Node* node){
    printf("/nTraversal in reverse direction \n");
    printRevHelper(node);
}
void moveNode(Node** head_ref, Node* move,LLIST *llist){
    char address;
    int requests;
    address = move -> address;
    requests = move -> requests;
    deleteNode(llist);
    addToBeginning(head_ref,address,requests);
}

void deleteNode(LLIST *llist){
    if(llist -> tail == NULL){
        return;
    }
    Node* delete;
    delete = (Node*) malloc(sizeof(Node));
    delete = llist -> tail;
    llist -> tail = delete -> prev;
    delete -> prev -> next = NULL;
    free(delete);
    return;
}

void processToken(char *str, LLIST *llist){
    int i;
    char elem;

    if(!str) return;

    i = 0;

    while(str[i] != '\0'){
        elem = str[i];
        //  is it full?
        /* if (llist -> len > volume){
            delete the tail
        }
        if (we have a node with a same address? == yes){
            node -> requests = requests++
            if (requests > threshold == yes ){
                move node to the head
                change head node in llist
            }
        }
        else{
            if (len > volume)
            {
                delete the tail
                change a tail
                add node
            }
                else
                {
                    add to the end of a list
                    change tail
                }
            }*/


        i++;
    }
}

