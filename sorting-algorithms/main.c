#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algorithms.h"
#include "book.h"

void readCSV(BOOK books[], int *counter)
{
    printf("===============================\n");
    printf("Reading books from .csv file...");
    FILE *dat = fopen("books.csv", "r");
    if (dat == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }
    char lines[300];
    int br = 0;
    while (fgets(lines, sizeof(lines), dat) != NULL)
    {
        books[br].id = atoi(strtok(lines, ","));
        strcpy(books[br].title, strtok(NULL, ","));
        strcpy(books[br].original_title, strtok(NULL, ","));
        books[br].publication_year = atoi(strtok(NULL, ","));
        strcpy(books[br].writer, strtok(NULL, ","));
        books[br].release_year = atoi(strtok(NULL, ","));
        strcpy(books[br].publisher, strtok(NULL, ","));
        strcpy(books[br].purchase_date, strtok(NULL, "\n"));
        br++;
    }

    fclose(dat);
    *counter = br;
    printf("\n===============================\n");
    printf("After reading books from .csv, there are %d books in the file.", *counter);
    printf("\n===============================\n");
}

void printExecutionTime(char *algorithmName, clock_t begin, clock_t end)
{
    printf("===============================\n");
    printf("Total time of %s algorithm is %lf.\n", algorithmName, (double)(end - begin) / CLOCKS_PER_SEC);
    printf("===============================\n");
}

void execute_algorithm(BOOK *books, int counter, char *type)
{
    clock_t begin, end;
    begin = clock();

    if (strcmp(type, "SHELL-SORT") == 0)
        shell_sort(books, counter);
    else if (strcmp(type, "INSERTION-SORT1") == 0)
        insertion_sort_by_publication_year(books, counter);
    else if (strcmp(type, "INSERTION-SORT2") == 0)
        insertion_sort_by_release_year(books, counter);
    else if (strcmp(type, "BUBBLE_SORT1") == 0)
        bubble_sort_by_release_year(books, counter);
    else if (strcmp(type, "BUBBLE-SORT2") == 0)
        bubble_sort_by_publication_year(books, counter);
    else if (strcmp(type, "HEEP-SORT") == 0)
        heap_sort(books, counter);
    end = clock();
    printExecutionTime(type, begin, end);
}

int main()
{
    BOOK *books = (BOOK *)malloc(1000 * sizeof(BOOK));
    int counter = 0;

    readCSV(books, &counter);

    execute_algorithm(books, counter, "SHELL-SORT");      // Exceute shell-sort algorithm (sorting by year of publication ASC)
    execute_algorithm(books, counter, "INSERTION-SORT1"); // Execute insertion-sort algorithm (sorting by year of publication ASC)
    execute_algorithm(books, counter, "INSERTION-SORT2"); // Execute insertion-sort algorithm (sorting by year of release DESC)
    execute_algorithm(books, counter, "BUBBLE-SORT1");    // Execute bubble-sort algorithm (sorting by year of release ASC)
    execute_algorithm(books, counter, "BUBBLE-SORT2");    // Execute bubble-sort algorithm (sorting by year of release DESC)
    execute_algorithm(books, counter, "HEEP-SORT");       // Execute heep-sort algorithm (sorting by year of release ASC)

    free(books);
    return 0;
}
