#ifndef NODE_H
#define NODE_H

typedef struct node
{
    struct node *parent;
    struct node *left_child;
    struct node *right_child;
    char array[100];
    char sign;
} NODE;

NODE *createNode(char sign);
NODE *addLeftChild(NODE *node, char sign);
NODE *addRightChild(NODE *node, char sign);
void makeTree(NODE *root);
void deleteTree(NODE **root);

#endif