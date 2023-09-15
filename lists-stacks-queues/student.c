#include "student.h"
#include <stdio.h>
#include <stdlib.h>

STUDENT insert()
{
    char c;
    STUDENT student;

    printf("First name:");
    scanf("%s", student.first_name);

    printf("Last name:");
    scanf("%s", student.last_name);

    printf("Index:");
    scanf("%s", student.index);

    printf("Study program:");
    scanf("%c", &c);
    gets(student.study_program);

    printf("College year:");
    scanf("%s", student.college_year);
}
