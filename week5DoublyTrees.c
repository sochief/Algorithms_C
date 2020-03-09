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

void preTraverse(tree t){
    if( t == NULL)
        return;
    visit(t);
    preTraverse(t -> left);
    preTraverse(t -> right);
}
void inTraverse(tree t){
    if (t == NULL)
        return;
    inTraverse(t -> left);
    visit(t);
    inTraverse(t -> right);
}
void postTraverse(tree t){
    if (t == NULL)
        return;
    postTraverse(t -> left);
    postTraverse(t -> right);
    visit(t);
}
tree copy(tree orig){
    tree temp;
    if(orig){
        temp = (tree)malloc(sizeof(tree));
        temp -> left = copy(orig -> left);
        temp -> right = copy(orig -> right);
        temp -> data = orig -> data;
        return temp;
    }
    return NULL;
}
int equal(tree first, tree second){
    // Are two trees are equal?
    return((!first && !second) ||
    (first && second
    &&(first -> data == second -> data) // are the data's equal, if yes go check right, and if they are the same as well -- return 1
    && equal(first -> left,second -> left)
    && equal(first -> right,second -> right)
    )
    );
    // we use preorder, while we have to check the data between two arrays
}



// Try to solve it using 2 stacks
int main(){
    return 0;
}