typedef struct link{
    int item;
    struct link *next;
}node;

node * insert_top(int num,node *head){
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode -> item = num;
    newnode -> next = head;
    head = newnode;
    return head;
}
node * instert_after(int num, int pre_num,node *head){
    node * curr = head;
    node * newnode;
    while(curr -> item != pre_num){
        curr = curr -> next;
    }
    newnode = (node *)malloc(sizeof(node));
    newnode -> item = num;
    newnode -> next = curr -> next;
    curr -> next = newnode;
    return head;
    }
node * delete_value(int num,node *head){
    node *curr = head;
    node *prev;
    while(curr != 0){
        if(curr -> item == num){
            if(curr == head){
                head = curr ->next;
            }
            else{
                prev -> next = curr -> next;
            }
        }
        prev = curr;
        curr = curr -> next;
    }
    return head;
}
int main(void){
    node *head = 0;
    int i;
    head = insert_top(5,head);
    for(i = 2; i < 10;i++){
        instert_after(i,i-1,head);
    }
    delete_value(6,head);
    return 0;
}

