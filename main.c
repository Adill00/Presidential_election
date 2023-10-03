// main.c

#include "pw56.h"

int main()
{
    T_Elector head = NULL;
    T_Elector left = NULL;
    T_Elector right = NULL;
    T_Elector white = NULL;
    T_Elector merged = NULL;

    int choice;
    char name[50];
    long cin_num;
    int choice_num;

    do
    {
        printf("Menu\n");
        printf("1. Enter the voters\n");
        printf("2. Add voters\n");
        printf("3. Delete a voter\n");
        printf("4. Search for a voter\n");
        printf("5. Display the list of voters\n");
        printf("6. Calculate the number of voters\n");
        printf("7. Split and sort the list\n");
        printf("8. Calculate the left and right percentages for the 2nd round\n");
        printf("9. Free the lists\n");
        printf("10. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the voter's name: ");
            scanf("%s", name);

            printf("Enter the voter's ID number: ");
            scanf("%ld", &cin_num);

            printf("Enter the voter's choice (1-5): ");
            scanf("%d", &choice_num);

            addElector(&head, name, cin_num, choice_num);
            break;

        case 2:
            printf("Enter the voter's name: ");
            scanf("%s", name);

            printf("Enter the voter's ID number: ");
            scanf("%ld", &cin_num);

            printf("Enter the voter's choice (1-5): ");
            scanf("%d", &choice_num);

            addElector(&head, name, cin_num, choice_num);
            break;

        case 3:
            printf("Enter the voter's ID number: ");
            scanf("%ld", &cin_num);
            deleteElector(&head, cin_num);
            break;

        case 4:
            printf("Enter the voter's ID number: ");
            scanf("%ld", &cin_num);
            findElector(head, cin_num);
            break;

        case 5:
            displayList(head);
            break;

        case 6:
            printf("Total number of voters: %d\n", countElector(head));
            break;

        case 7:
            decomposeList(head, &left, &right, &white);
            sortList(left);
            sortList(right);
            sortList(white);

            printf("Left voters:\n");
            displayList(left);

            printf("Right voters:\n");
            displayList(right);

            printf("White voters:\n");
            displayList(white);

            merged = mergeLists(left, right);
            printf("Merged left and right voters:\n");
            displayList(merged);
            break;

        case 8:
            printf("Percentage of left and right voters in the merged list for the 2nd round: %.2f%%\n", (float)countLR(merged) / countElector(merged) * 100);
            break;

        case 9:
            freeList(head);
            freeList(left);
            freeList(right);
            freeList(white);
            freeList(merged);

            head = left = right = white = merged = NULL;
            printf("Lists have been freed.\n");
            break;

        case 10:
            printf("Quitting...\n");
            break;

        default:
            printf("Invalid choice, try again.\n");
        }

    } while (choice != 10);

    // Free the lists before exiting
    freeList(head);
    freeList(left);
    freeList(right);
    freeList(white);
    freeList(merged);

    return 0;
}
