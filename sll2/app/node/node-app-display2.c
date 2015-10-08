#include <stdio.h>
#include "node.h"

void display(Node *);

int main()
{
    //declaring pointers and input variable
    Node *tmp;
    Node *tmp2;
    tmp = NULL;
    tmp2 = NULL;
    int input = 0;

    //initial prompt
    fprintf(stdout, "Enter a info (-1 to quit): ");
    fscanf(stdin, "%d", &input);

    //setting up initial node with tmp pointing to it
    tmp = mknode(input);
    tmp -> after = NULL;
    tmp2 = tmp;         //setting tmp2 to same location as tmp

    while (input != -1)                 //while loop checking for input not being sentinel value of -1
    {
        tmp2 -> after = mknode(input);  
        tmp2 -> after -> after = NULL;

        //looped prompt
        fprintf(stdout, "Enter a info (-1 to quit): ");
        fscanf(stdin, "%d", &input);
        
        tmp2->after = mknode(input);

        //if statement checking for -1 and deallocating after pointer on last node and setting to NULL
        if (input == -1)
        {
            free(tmp2 -> after);
            tmp2 -> after = NULL;
        }
        else
            tmp2 = tmp2 -> after;   //moving tmp2 down the list
    }

    display(tmp); //passing tmp pointer to display function

	return(0);
}

void display(Node *start)
{
    //declaring local tmp pointer (essentially start pointer) and setting to NULL
    Node *tmp;
    tmp = NULL;

    //setting tmp to passed pointer
    tmp = start;

    while (tmp->after != NULL)      //while loop as long as tmp's after isn't NULL
    {
        printf("%d -> ", tmp->info);    //print tmp's info
        tmp = tmp->after;               //move tmp pointer down list
    }
    printf("%d -> ",tmp->info);         //print last value
    printf("NULL\n");                   //print a NULL for output
}
