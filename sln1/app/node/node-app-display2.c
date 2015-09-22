#include <stdio.h>
#include "node.h"

void display(Node *);

int main()
{
	// rewrite node-app-display to use the node library functions
	// (mknode(), specifically). The resulting output
	// should be IDENTICAL to the original node-app-display program.
	
	// Display list from start to end by calling the display() 
	// function, passing in a pointer to the start of the list.

    Node *tmp;
    Node *tmp2;
    tmp = NULL;
    tmp2 = NULL;
    int input = 0;


    fprintf(stdout, "Enter a info (-1 to quit): ");
    fscanf(stdin, "%d", &input);

    tmp = mknode(input);

    while (input != -1)
    {
        tmp2 = mknode(input);


        if (input == -1)
        {
            free(tmp2 -> after);
            tmp2 -> after = NULL;
        }
        else
            tmp2 = tmp2 -> after;
    }

    display(tmp *);

	return(0);
}

void display(Node *start)
{
	// implement your display list function here, and call it from
	// main() -- you may use the same code implemented previously 
	// for displaying the list.
	
	// This is a test to see if you can modularize your code.
    
    //tmp = (Node *)malloc(sizeof(Node)*1);
    
    Node *tmp;
    tmp = NULL;

    tmp = start;

    while (tmp->after != NULL)
    {
        printf("%d -> ", tmp->info);
        tmp = tmp->after;
    }
    printf("%d -> ",tmp->info);
    printf("NULL\n");
}
