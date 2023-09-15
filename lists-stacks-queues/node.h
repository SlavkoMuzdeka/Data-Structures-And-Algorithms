#ifndef NODE_H
#define NODE_H
#include "student.h"

typedef struct node
{
    STUDENT student;
    struct node *next;
} NODE;

NODE *findNode(NODE *head, int temp);
void addNode(NODE *head, STUDENT s);
void addInQueue(NODE **front, NODE **rear, STUDENT *s);
void emptyList(NODE **head);
void push(NODE **tos, STUDENT *s);
int removeElementFromQueue(NODE **front, NODE **rear, STUDENT *s);
int pop(NODE **tos);

#endif