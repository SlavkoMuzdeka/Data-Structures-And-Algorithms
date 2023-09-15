#include "algorithms.h"
#include <stdio.h>
#include <stdlib.h>

void shell_sort(BOOK *books, int n)
{
    printf("Sorting books with Shell-sort algorithm (by publication year ASC)....\n");
    printf("===============================\n");
    int i, j, h;
    for (h = n / 2; h > 0; h /= 2)
    {
        for (i = h; i < n; i++)
        {
            BOOK book = books[i];
            for (j = i; j >= h && book.release_year < books[j - h].release_year; j -= h)
                books[j] = books[j - h];
            books[j] = book;
        }
    }
    printf("Sorting with Shell-sort algorithm is finished...\n");
}

void insertion_sort_by_publication_year(BOOK *books, int n)
{
    printf("Sorting books with Insertion-sort algorithm (by publication year ASC)....\n");
    printf("===============================\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        BOOK book = books[i];
        for (j = i; j > 0 && book.publication_year < books[j - 1].publication_year; j--)
            books[j] = books[j - 1];
        books[j] = book;
    }
    printf("Sorting with Insertion-sort algorithm is finished...\n");
}

void insertion_sort_by_release_year(BOOK *books, int n)
{
    printf("Sorting books with Insertion-sort algorithm (by release year DESC)....\n");
    printf("===============================\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        BOOK book = books[i];
        for (j = i; j > 0 && book.release_year > books[j - 1].release_year; j--)
            books[j] = books[j - 1];
        books[j] = book;
    }
    printf("Sorting with Insertion-sort algorithm is finished...\n");
}

void bubble_sort_by_release_year(BOOK *books, int n)
{
    printf("Sorting books with Bubble-sort algorithm (by release year ASC)....\n");
    printf("===============================\n");
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            if (books[j].release_year < books[j + 1].release_year)
            {
                BOOK book = books[j];
                books[j] = books[j + 1];
                books[j + 1] = book;
            }
    }
    printf("Sorting with Bubble-sort algorithm is finished...\n");
}

void bubble_sort_by_publication_year(BOOK *books, int n)
{
    printf("Sorting books with Bubble-sort algorithm (by publication year DESC)....\n");
    printf("===============================\n");
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            if (books[j].publication_year > books[j + 1].publication_year)
            {
                BOOK book = books[j];
                books[j] = books[j + 1];
                books[j + 1] = book;
            }
    }
    printf("Sorting with Bubble-sort algorithm is finished...\n");
}

void sortHeep(BOOK *books, int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && books[left].release_year < books[max].release_year)
        max = left;
    if (right < n && books[right].release_year < books[max].release_year)
        max = right;
    if (max != i)
    {
        BOOK book = books[i];
        books[i] = books[max];
        books[max] = book;
        sortHeep(books, n, max);
    }
}

void heap_sort(BOOK *books, int n)
{
    printf("Sorting books with Heep-sort algorithm (by release year ASC)....\n");
    printf("===============================\n");
    for (int i = n / 2 - 1; i >= 0; i--)
        sortHeep(books, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        BOOK book = books[0];
        books[0] = books[i];
        books[i] = book;
        sortHeep(books, i, 0);
    }
    printf("Sorting with Heep-sort algorithm is finished...\n");
}