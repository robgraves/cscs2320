#include <stdio.h>
#include "node.h"

int main()
{
    //given code
	Node *tmp, *tmp2;
	char input;

	tmp          = tmp2 = (Node *) malloc (sizeof(Node)*1);
	tmp -> info = 0;
	tmp -> after  = NULL;

	fprintf(stdout, "Enter a info (-1 to quit): ");
	fscanf(stdin, "%hhd", &input);

	while (input != -1)
	{
		tmp2 -> info = input;

		tmp2 -> after = (Node *) malloc (sizeof(Node)*1);
		tmp2 -> after -> info = 0;
		tmp2 -> after -> after  = NULL;

		fprintf(stdout, "Enter a info (-1 to quit): ");
		fscanf(stdin, "%hhd", &input);

		if (input == -1)
		{
			free(tmp2 -> after);
			tmp2 -> after = NULL;
		}
		else
			tmp2 = tmp2 -> after;
	}
    //end given code

    tmp2 = tmp;     //setting tmp2 pointer to tmp pointers location

    while (tmp2->after != NULL)     //while loop for tmp2's after pointer is not equal to NULL
    {
        printf("%d -> ", tmp2->info);   //print tmp's value
        tmp2 = tmp2->after;             //move tmp2 down the list
    }
    printf("%d -> ",tmp2->info);        //prints last value
    printf("NULL\n");                   //prints NULL

	return(0);
}
