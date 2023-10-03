#ifndef PW56_H
#define PW56_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elector {
    char name[50];
    long cin_num;
    int choice;
    struct elector *next;
} elector;

typedef elector *T_Elector;

T_Elector createElector(void);
void displayList(T_Elector head);
void addElector(T_Elector *head, char name[], long cin_num, int choice);
int countElector(T_Elector head);
int findElector(T_Elector head, long cin_num);
void deleteElector(T_Elector *head, long cin_num);
void decomposeList(T_Elector head, T_Elector *left, T_Elector *right, T_Elector *white);
void sortList(T_Elector head);
T_Elector mergeLists(T_Elector left, T_Elector right);
int countLR(T_Elector head);
void freeList(T_Elector head);

#endif