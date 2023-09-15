#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void saveCodeRecursive(NODE *p, NODE *root, char sign)
{
    if (root != NULL)
    {
        if (sign == '0')
            strcpy(root->array, "");
        else
        {
            strcpy(root->array, p->array);
            if (sign == '1')
                strcat(root->array, ".");
            else if (sign == '2')
                strcat(root->array, "-");
        }
        saveCodeRecursive(root, root->left_child, '1');
        saveCodeRecursive(root, root->right_child, '2');
    }
}

void saveCode(NODE *root)
{
    if (root != NULL)
        saveCodeRecursive(NULL, root, '0');
}

void showDialog()
{
    printf("===============================\n");
    printf("Choose one option\n");
    printf("1. Code new word\n");
    printf("2. Code words from file\n");
    printf("3. Pronunciation\n");
    printf("4. End\n");
    printf("===============================\n");
    printf("Enter option number:");
}

void findCodeForWord(NODE *root, char sign)
{
    int a = 1;
    if (root != NULL)
    {
        if (root->sign == sign)
        {
            printf("%s", root->array);
            a = 0;
        }
        if (a == 1)
        {
            findCodeForWord(root->left_child, sign);
            findCodeForWord(root->right_child, sign);
        }
    }
}

void codeWord(NODE *root, char *word)
{
    if (root != NULL && word != NULL)
    {
        char c;
        printf("%s -> ", word);
        for (int i = 0; i < strlen(word); i++)
        {
            c = *(word + i);
            if (c >= 'a' && c <= 'z')
                c -= 32;
            if (c == ' ')
                printf(" ");
            findCodeForWord(root, c);
        }
    }
    printf("\n");
}

void deleteNewLine(char *word)
{
    int len;
    if ((len = strlen(word)) > 0)
        if (word[len - 1] == '\n')
            word[len - 1] = '\0';
}

void codeFile(NODE *root)
{
    char *array1 = (char *)malloc(10000 * sizeof(char));
    if (array1 == NULL)
    {
        printf("Cannot allocate array!\n");
        return;
    }
    FILE *dat = fopen("words.txt", "r+");
    if (dat == NULL)
    {
        printf("Cannot open the file!\n");
        return;
    }
    while (fgets(array1, 200, dat))
    {
        deleteNewLine(array1); // Sets '\0' instead new line '\n'
        codeWord(root, array1);
    }
    free(array1);
    fclose(dat);
}

void pronounceWord(char word)
{
    char *morseCode[] = {
        "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxfort", "Golf", "Hotel", "India", "Lima",
        "Klio", "Lima", "Mike", "November", "Oscar", "Papa", "Qeuebec", "Romeo", "Sierra", "Tango",
        "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu", "Zero", "One", "Two", "Three",
        "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    if (word >= 'A' && word <= 'Z')
    {
        int index = word - 'A';
        if (index >= 0 && index < 26)
            printf("%s ", morseCode[index]);
    }
    else if (word >= '0' && word <= '9')
    {
        int index = word - '0' + 26;
        if (index >= 26 && index < 36)
            printf("%s ", morseCode[index]);
    }
}

void printWord(NODE *root, char *word)
{
    if (root != NULL && word != NULL)
    {
        char w;
        printf("%s -> ", word);
        for (int i = 0; i < strlen(word); i++)
        {
            w = *(word + i);
            if (w >= 'a' && w <= 'z')
                w -= 32;
            pronounceWord(w);
        }
    }
}

void processOption1(NODE *root)
{
    char c1, temp[100], word[100];
    printf("===============================\n");
    printf("What do you want to code?\nEnter word: ");
    scanf("%c", &c1);
    gets(word);
    strcpy(temp, word);
    codeWord(root, temp);
}

void processOption3(NODE *root)
{
    char c;
    char temp[100];
    char word[100];
    printf("===============================\n");
    printf("Enter the word you want to print in its original format: ");
    scanf("%c", &c);
    gets(word);
    strcpy(temp, word);
    printWord(root, temp);
    printf("\n");
}

int main()
{
    NODE *root = createNode(' ');
    makeTree(root);
    saveCode(root);
    int option;
    do
    {
        showDialog();
        scanf("%d", &option);
        if (option == 1)
            processOption1(root);
        else if (option == 2)
            codeFile(root);
        else if (option == 3)
            processOption3(root);
    } while (option != 4);
    deleteTree(&root);
    return 0;
}
