#include "pw56.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

T_Elector createElector(void)
{
    T_Elector new_elector = (T_Elector)malloc(sizeof(elector));
    if (new_elector == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_elector->next = NULL;
    return new_elector;
}

void displayList(T_Elector head)
{
    T_Elector current = head;
    while (current != NULL)
    {
        printf("Name: %s, ID: %ld, Choice: %d\n", current->name, current->cin_num, current->choice);
        current = current->next;
    }
}

void addElector(T_Elector *head, char name[], long cin_num, int choice)
{
    T_Elector new_elector = createElector();
    strcpy(new_elector->name, name);
    new_elector->cin_num = cin_num;
    new_elector->choice = choice;

    if (*head == NULL || strcmp((*head)->name, name) > 0)
    {
        new_elector->next = *head;
        *head = new_elector;
    }
    else
    {
        T_Elector current = *head;
        while (current->next != NULL && strcmp(current->next->name, name) < 0)
        {
            current = current->next;
        }
        new_elector->next = current->next;
        current->next = new_elector;
    }
}

int countElector(T_Elector head)
{
    int count = 0;
    T_Elector current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int findElector(T_Elector head, long cin_num)
{
    T_Elector current = head;
    while (current != NULL)
    {
        if (current->cin_num == cin_num)
        {
            printf("Name: %s, ID: %ld, Choice: %d\n", current->name, current->cin_num, current->choice);
            return 1;
        }
        current = current->next;
    }
    printf("Elector not found.\n");
    return 0;
}

void deleteElector(T_Elector *head, long cin_num)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->cin_num == cin_num)
    {
        T_Elector temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    T_Elector current = *head;
    while (current->next != NULL && current->next->cin_num != cin_num)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Elector not found.\n");
        return;
    }

    T_Elector temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void decomposeList(T_Elector head, T_Elector *left, T_Elector *right, T_Elector *white)
{
    T_Elector current = head;
    while (current != NULL)
    {
        
        if (current->choice == 1 || current->choice == 3)
        {
            addElector(left, current->name, current->cin_num, current->choice);
        }
        else if (current->choice == 2 || current->choice == 4)
        {
            addElector(right, current->name, current->cin_num, current->choice);
        }
        else
        {
            addElector(white, current->name, current->cin_num, current->choice);
        }
        current = current->next;
    }
}


void sortList(T_Elector head)
{
    T_Elector i, j;
    long temp_cin_num;
    int temp_choice;
    char temp_name[50];

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->cin_num > j->cin_num)
            {
                temp_cin_num = i->cin_num;
                i->cin_num = j->cin_num;
                j->cin_num = temp_cin_num;

                temp_choice = i->choice;
                i->choice = j->choice;
                j->choice = temp_choice;

                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);
            }
        }
    }
}

T_Elector mergeLists(T_Elector left, T_Elector right)
{
    T_Elector merged = NULL;
    T_Elector *current = &merged;

    while (left != NULL && right != NULL)
    {
        if (left->cin_num < right->cin_num)
        {
            *current = left;
            left = left->next;
        }
        else
        {
            *current = right;
            right = right->next;
        }
        current = &((*current)->next);
    }

    if (left != NULL)
    {
        *current = left;
    }
    else
    {
        *current = right;
    }

    return merged;
}

int countLR(T_Elector head)
{
    int count = 0;
    T_Elector current = head;
    while (current != NULL)
    {
        if (current->choice == 1 || current->choice == 3)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}

void freeList(T_Elector head)
{
    T_Elector temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
