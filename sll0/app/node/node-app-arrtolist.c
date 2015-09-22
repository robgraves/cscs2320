#include <stdio.h>
#include "node.h"

int main()
{
    //given code for array
	char data[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7 };
	int i;

	fprintf(stdout, "Array: ");
	for(i = 0; i < 14; i++)
		fprintf(stdout, "%hhd ", *(data+i));
	fprintf(stdout, "\n");
    //end given code for array

	Node *current;	//declaring Node for current pointer
	Node *start;	//declaring Node for start pointer
	Node *tmp;      //declaring Node for tmp pointer

	current=(Node *)malloc(sizeof(Node));   //allocating memory for current pointer
	start=(Node *)malloc(sizeof(Node));     //allocating memory for start pointer
	tmp=(Node *)malloc(sizeof(Node));       //allocating memory for tmp pointer

    start=mknode(data[0]);          //setting start pointer to the first element of the array's node

	tmp=start;	                    //setting tmp to start pointer

	fprintf(stdout, "List:  ");     //print statement for List
	for(i = 1; i < 14; i++)     //for loop to iterate through array and create connecting nodes from it
	{
		current=mknode(data[i]);    //setting current pointer to mknode to iteration of array's element
		tmp->after=current;		    //setting tmp's after to current				
		current=current->after;     //moving current down the list
		tmp=tmp->after;	            //moving tmp down the list
	}

	current = start;                //setting current back to the start of the list

	while (current != NULL)         //while loop checking for current to not equal NULL
	{
		fprintf(stdout,"%hhd ",current->info);  //output current info value
		current = current->after;               //moves current down the list
	}
	fprintf(stdout, "\n");                      //prints newline

	return(0);
}
