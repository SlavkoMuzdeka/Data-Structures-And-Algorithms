#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void addNode(NODE *head, STUDENT s)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->student = s;
    node->next = NULL;
    if (head->next == NULL)
        head->next = node;
    else
    {
        NODE *pom = head;
        while (pom->next != NULL)
            pom = pom->next;
        pom->next = node;
    }
}

NODE *findNode(NODE *head, int temp)
{
    for (int i = 1; i < temp; i++)
        head = head->next;
    return head;
}

void addInQueue(NODE **front, NODE **rear, STUDENT *s)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (node == NULL)
    {
        printf("It is not possible to allocate node!\n");
        return;
    }
    node->student = *s;
    node->next = NULL;
    if (*front == NULL)
        *front = *rear = node;
    else
    {
        (*rear)->next = node;
        *rear = node;
    }
}

void emptyList(NODE **head)
{
    printf("===============================\n");
    printf("Deleting elements from list...");
    printf("\n===============================\n");
    if (*head == NULL)
    {
        printf("List is still empty!\n");
        return;
    }
    while (*head)
    {
        NODE *node = (*head)->next;
        free(*head);
        *head = node;
    }
    if (*head == NULL)
    {
        printf("The list is empty...");
        printf("\n===============================\n");
    }
}

int removeElementFromQueue(NODE **front, NODE **rear, STUDENT *s)
{
    if (*front == NULL)
        return 0;
    NODE *node = *front;
    *s = node->student;
    if (*front == *rear)
        *front = *rear = NULL;
    else
        (*front) = node->next;
    free(node);
    return 1;
}

void push(NODE **tos, STUDENT *s)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (node == NULL)
    {
        printf("Cannot create new node!\n");
        return;
    }
    node->student = *s;
    node->next = *tos;
    *tos = node;
    printf("Student %s, %s, %s is added to the stack\n", s->first_name, s->last_name, s->college_year);
}

int pop(NODE **tos)
{
    if (*tos == NULL)
        return 0;
    NODE *node = *tos;
    *tos = node->next;
    free(node);
    return 1;
}
