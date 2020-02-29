#include <stdio.h>

int main(){
    int var1 = 20;
    int *ip;
    ip = &var1;
    printf("The address of the var variable is: %x\n",&var1);
    printf("The address stored in  ip variable: %x\n",ip);
    /* Acces to the value using pointer*/
    printf("Value of *ip variable is : %d\n",*ip);
}