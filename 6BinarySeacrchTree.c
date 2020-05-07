/* Binary search tree
Sol alt ikili arama agacindaki elemanlarin kokten kucuk,
sag alt ikili arama agacindaki
elemanlarin kokten buyuk
oldugu ikili agac




Adding a new node.
If less, go to left, if null, create new one
6,5,1,0,8,12,10,7
6 -> head
5 -> left                                   6
1 -> left                               5       8
0 -> left                             1      7    12
Worst case O(n)                     0            10
8 -> right
12 -> right right

*/
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


// WEEK 6!!!
tree insert(tree node,char data){
    if(node == NULL){
        return createTree(data);
    }
    if (data < node -> data){
        node -> left = insert(node -> left,data);
    }
    else if(data > node -> data){
        node -> right = insert(node -> right, data);
    }
    // if data is equal -> return node, because we already have it
    return node;
}


tree search(tree root,char key){
    if ( root == NULL || root -> data == key){
        return root;
    }
    if( key < root -> data){
        return(search(root->left,key));
    }
    return search(root -> right,key);
}

// Delete a element
// 3 cases:
// No child -> no problem
// 1 chld -> no problem
// 2 children - Have a look at geeksforgeeks
// RED BLACK TREES
// Complexity is O(n)
tree minValueNode(tree node){
    tree current = node;
    while(current -> left != NULL){
        current = current -> left;
    }
    return current;
}

tree delete(tree root, char data){
    if(root == NULL)
        return root;
    if(data < root -> data)
        root -> left = delete(root->left,data);
    else if(data > root -> data)
        root -> right = delete(root -> right,data);
    else {
        if(root -> left == NULL){
            tree tmp = root -> right;
            free(root);
            return tmp;
        }
        else if(root -> right == NULL){
            tree tmp = root -> left;
            free(root);
            return tmp;
        }
        tree tmp  = minValueNode(root -> right);
        root -> data = tmp -> data;
        root -> right = delete(root -> right, tmp -> data);
        }
    return root;
}



// Same code from previous week
// Try to solve it using 2 stacks
int main(){
    return 0;
}


