#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "book.h"

void shell_sort(BOOK *books, int n);
void insertion_sort_by_publication_year(BOOK *books, int n);
void insertion_sort_by_release_year(BOOK *books, int n);
void bubble_sort_by_release_year(BOOK *books, int n);
void bubble_sort_by_publication_year(BOOK *books, int n);
void heap_sort(BOOK *books, int n);

#endif
