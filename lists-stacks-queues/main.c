#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void readCSV(NODE **head, int *counter)
{
    printf("===============================\n");
    printf("Reading data from .csv file...");
    FILE *dat = fopen("inputData.csv", "r+");
    if (dat == NULL)
    {
        printf("Error opening the file.\n");
        printf("===============================\n");
        return;
    }

    char students[100];
    while (fgets(students, 100, dat) != NULL)
    {
        NODE *node = (NODE *)malloc(sizeof(NODE));

        char *index = strtok(students, ",");
        strcpy(node->student.index, index);

        char *first_name = strtok(NULL, ",");
        strcpy(node->student.first_name, first_name);

        char *last_name = strtok(NULL, ",");
        strcpy(node->student.last_name, last_name);

        char *study_program = strtok(NULL, ",");
        strcpy(node->student.study_program, study_program);

        char *college_year = strtok(NULL, "\n");
        strcpy(node->student.college_year, college_year);

        node->next = NULL;
        if (*head == NULL)
            *head = node;
        else
        {
            NODE *tail = *head;
            while (tail->next != NULL)
                tail = tail->next;
            tail->next = node;
        }
        (*counter)++;
    }
    fclose(dat);
    printf("\n===============================\n");
    printf("After reading data from .csv, there are %d students in the file.", *counter);
    printf("\n===============================\n");
}

void showDialog()
{
    printf("Do you want to add new student? ");
    printf("\n===============================\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("===============================\n");
    printf("Enter option number:");
}

void printStudentsNumber(int counter)
{
    printf("===============================\n");
    printf("After adding new student, there are %d students in the list.", counter);
    printf("\n===============================\n");
}

void addNewStudent(NODE *head, int *counter)
{
    int option;
    do
    {
        showDialog();
        scanf("%d", &option);
        if (option == 1)
        {
            addNode(head, insert());
            (*counter)++;
            printStudentsNumber(*counter);
        }
    } while (option != 2);
}

int checkIfExists(int *array, int i, int temp)
{
    for (int j = 0; j < i; j++)
        if (array[j] == temp)
            return 0;
    return 1;
}

void addStudentsToQueue(NODE *head, NODE **front, NODE **rear, int counter)
{
    printf("===============================\n");
    printf("Adding students to queue...");
    int *array = (int *)malloc(60 * sizeof(int));
    int temp;
    for (int i = 0; i < counter; i++)
    {
        do
        {
            temp = rand() % counter + 1;
            array[i] = temp;
        } while (checkIfExists(array, i, temp) != 1);
        NODE *n = findNode(head, temp);
        addInQueue(front, rear, &n->student);
    }
    printf("\n===============================\n");
    printf("Students are added to queue...\n");
}

void removeElementsFromQueueAndAddToStack(NODE **front, NODE **rear, NODE **tos)
{
    STUDENT student;
    printf("Deleting students from queue...");
    printf("\n===============================\n");
    while (removeElementFromQueue(front, rear, &student))
    {
        printf("Deleted student from queue is: %s, %s, %s\n", student.first_name, student.last_name, student.college_year);
        push(tos, &student);
    }
    printf("===============================\n");
    printf("Students are deleted from queue and added to the stack...");
    printf("\n===============================\n");
}

void deleteStudentsFromStack(NODE **tos)
{
    printf("Deleting students from stack...");
    printf("\n===============================\n");
    while (pop(tos))
        ;
    printf("Students are deleted from stack...");
    printf("\n===============================\n");
}

int main()
{
    NODE *head = NULL, *front = NULL, *rear = NULL, *tos = NULL;
    int counter = 0;

    time_t begin, end;
    srand(time(0));
    begin = clock();

    readCSV(&head, &counter);
    addNewStudent(head, &counter);
    addStudentsToQueue(head, &front, &rear, counter);
    emptyList(&head);
    removeElementsFromQueueAndAddToStack(&front, &rear, &tos);
    deleteStudentsFromStack(&tos);

    end = clock();
    double total_time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Duration of simulation is: %lf", total_time);
    printf("\n===============================\n");

    return 0;
}