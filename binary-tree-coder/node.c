#include <stdio.h>
#include <stdlib.h>
#include "node.h"

NODE *createNode(char sign)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->sign = sign;
    node->left_child = node->right_child = 0;
    return node;
}

NODE *addLeftChild(NODE *node, char sign)
{
    NODE *new_node = createNode(sign);
    if (node->left_child)
    {
        new_node->left_child = node->left_child;
        new_node->left_child->parent = new_node;
    }
    node->left_child = new_node;
    new_node->parent = node;
    return new_node;
}

NODE *addRightChild(NODE *node, char sign)
{
    NODE *new_node = createNode(sign);
    if (node->right_child)
    {
        new_node->right_child = node->right_child;
        new_node->right_child->parent = new_node;
    }
    node->right_child = new_node;
    new_node->parent = node;
    return new_node;
}

void makeTree(NODE *root)
{
    // Right subtree
    NODE *t = addRightChild(root, 'T'), *m = addRightChild(t, 'M'), *n = addLeftChild(t, 'N');
    NODE *d = addLeftChild(n, 'D'), *k = addRightChild(n, 'K'), *g = addLeftChild(m, 'G'), *o = addRightChild(m, 'O');
    NODE *b = addLeftChild(d, 'B'), *x = addRightChild(d, 'X'), *c = addLeftChild(k, 'C'), *y = addRightChild(k, 'Y');
    NODE *z = addLeftChild(g, 'Z'), *q = addRightChild(g, 'Q'), *pom = addLeftChild(o, ' '), *pom2 = addRightChild(o, ' ');
    addLeftChild(b, '6'), addLeftChild(z, '7'), addLeftChild(pom, '8'), addLeftChild(pom2, '9'), addRightChild(pom2, '0');
    // Left subtree
    NODE *e = addLeftChild(root, 'E'), *i = addLeftChild(e, 'I'), *a = addRightChild(e, 'A');
    NODE *s = addLeftChild(i, 'S'), *u = addRightChild(i, 'U'), *r = addLeftChild(a, 'R'), *w = addRightChild(a, 'W');
    NODE *h = addLeftChild(s, 'H'), *v = addRightChild(s, 'V'), *f = addLeftChild(u, 'F'), *pom3 = addRightChild(u, ' ');
    NODE *l = addLeftChild(r, 'L'), *p = addLeftChild(w, 'P'), *j = addRightChild(w, 'J');
    addLeftChild(h, '5'), addRightChild(h, '4'), addRightChild(v, '3'), addRightChild(pom3, '2'), addRightChild(j, '1');
}

void deleteTree(NODE **root)
{
    if (*root != NULL)
    {
        deleteTree(&(*root)->left_child);
        deleteTree(&(*root)->right_child);
        free(*root);
        *root = NULL;
    }
}