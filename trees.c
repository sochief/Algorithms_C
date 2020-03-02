#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct xnode{
    int data;
    unsigned int child;
    unsigned int sibling;
};
struct pnode{
    int data;
    struct pnode *child;
    struct pnode *siblings;
};
int main(){
    int N;
    struct xnode* T = (struct xnode*)malloc(N* sizeof(struct xnode));
    //trr in the copybook
    struct pnode* P = (struct pnode*)malloc(sizeof(struct pnode));
}