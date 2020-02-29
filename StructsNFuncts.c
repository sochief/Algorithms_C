#include <stdio.h>
#include <string.h>

struct Book
{
    char title[50];
    char author[50];
    char topic[50];
    int bookId;
    /* data */
};
void printBook(struct Book book){
    printf( "Book title : %s\n", book.title);
    printf( "Book author : %s\n",book.author);
    printf( "Book topic : %s\n",book.topic);
    printf( "Book id: %d\n",book.bookId);
}
int main(){
    struct Book Book1;
    struct Book Book2;
    strcpy( Book1.title, "C Programming");
    strcpy( Book1.author, "Nuha Ali"); 
    strcpy( Book1.topic, "C Programming Tutorial");
    Book1.bookId = 6495407;

    strcpy(Book2.title, "Ali Baba");
    strcpy(Book2.author, "Baba Ali");
    strcpy(Book2.topic,"Fairy Tales");
    Book2.bookId = 12314;
    printf("First book:\n");
    printBook(Book1);
    printf("Second Book: \n");
    printBook(Book2);

    }
