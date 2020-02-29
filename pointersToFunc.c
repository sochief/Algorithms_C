#include <stdio.h>
#include <time.h>

void getSeconds(unsigned long *par);

int main(){
    unsigned long sec;
    getSeconds(&sec);

    /* Print the actual value */
    printf("Number of second: %ld\n", sec);
    return 0;
}
void getSeconds(unsigned long *par){
    /* Get current number of seconds */
    *par = time( NULL );
    return;
}