#include <stdio.h>
#include <stdlib.h>
#include "book.h"

void printBooks(BOOK *books, int counter)
{
    printf("Books are: \n");
    for (int i = 0; i < counter; i++)
        printf("%d, %s, %s, %d, %s, %d, %s, %s\n",
               books[i].id,
               books[i].title,
               books[i].original_title,
               books[i].publication_year,
               books[i].writer,
               books[i].release_year,
               books[i].publisher,
               books[i].purchase_date);
    printf("===============================\n");
}