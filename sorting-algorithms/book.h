#ifndef BOOK_H
#define BOOK_H

typedef struct book
{
    int id;
    char title[30];
    char original_title[30];
    int publication_year;
    char writer[40];
    int release_year;
    char publisher[30];
    char purchase_date[12];
} BOOK;

void printBooks(BOOK *book, int counter);

#endif