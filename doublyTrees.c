#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node *tree;
typedef struct node{
    char data;
    tree left,right;
}node;

tree createTree(char data){
    tree T = (tree)malloc(sizeof(tree));
    T -> data = data;
    T -> left = NULL;
    T -> right = NULL;
    return T;
}

void visit(tree t){
    printf(" %c \n", t -> data);
}
int main(){
    
    return 0;
}