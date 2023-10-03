# Presidential_election
using simply linked list for the presidential election


Define the structure elector which contains the following fields:
- The name of type string,
- The cin_num of type long (=ID number),
- The choice of type integer
- A pointer to the next voter.

**To limit the computation, we define the choice as follows-> NAME1:1 ;NAME2:2 ;NAME3:3 ;NAME4:4 and any other:5**

Defined the type T_Elector as a pointer to the structure struct elector.

+T_Elector creationelector(void)  --- a function to create a voter
+void displaylist(T_Elector) --- displays the list of voters
+void addelector(T_Elector *, char [], long, int ) --- adds a voter in alphabetical order (number of voters is incremented through the day)

+int countelector(T_Elector) --- returns the number of voters in the list
+int findelector(T_Elector, long) --- searches for a voter with his ID number and displays all the data about him
+void deletelector(T_Elector *,long) --- function removing voter using his ID from any position of list
there are voters not meets the election requirements.they must be removed from list. 

+Void decomposelist(T_Elector,T_Elector *,T_Elector *,T_Elector*) --- function decomposing list of voters into three sub-lists:left,right,white according to candidate choice 
a. In the left list if they have chosen NAME1 or NAME3
b. In the right list if they chose NAME2 or NAME4 
c. And in the white list if they made the other choices

+void sortlist(T_Elector ) --- After separating the three lists,sorted them by ID number
+T_Elector mergelists(T_Elector, T_Elector) --- creates new list by merging only left and
right sublists.This merging keeps order of voters according to ID

+int countLR(T_Elector) --- function that returns the number of left voters in the merged list.To make an estimate for the second round,calculated the percentage in the merged list of left and right voters.For this calculation, wrote a function returning number of left voters in
the merged list.

+void freelist(T_Elector) --- function to free a list


wrote a program to manage a menu that contains the following features:
1. Enter the voters,
2. Add voters,
3. Delete a voter,
4. Search for a voter,
5. Display the list of voters,
6. Calculate the number of voters,
7. Split the list into three sub-lists according to the choices: right, left and white
a. Sort the sub-lists
b. Display the sub-lists,
c. Merge the two sub-lists: left and right
8. Calculate the left and right percentages for the 2nd round,
9. Free the lists
10. Quit
