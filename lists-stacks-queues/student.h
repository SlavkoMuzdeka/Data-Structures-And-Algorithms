#ifndef STUDENT_H
#define STUDENT_H

typedef struct student
{
    char first_name[20];
    char last_name[20];
    char index[8];
    char study_program[30];
    char college_year[7];
} STUDENT;

STUDENT insert();

#endif
