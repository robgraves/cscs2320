#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
	Node *tmp1, *tmp2;
	
	fprintf(stdout, "Before calling cpnode() ... \n");
	fprintf(stdout, "---------------------------------------------\n");
	fprintf(stdout, "tmp1 has an address of:        %p\n", &tmp1);
	fprintf(stdout, "tmp1 points to:                %p\n",  tmp1);
	fprintf(stdout, "tmp2 has an address of:        %p\n", &tmp2);
	fprintf(stdout, "tmp2 points to:                %p\n",  tmp2);

	tmp1 = mknode(8);

	if (tmp1 == NULL)
	{
		fprintf(stderr, "Error creating new node (tmp1).\n");
		exit(1);
	}

	tmp1 -> after = mknode(13);

	if (tmp1 -> after == NULL)
	{
		fprintf(stderr, "Error creating new node (tmp1 -> after).\n");
		exit(1);
	}

	tmp2 = cpnode(tmp1);

	if (tmp2 == NULL)
	{
		fprintf(stderr, "Error copying node (tmp2).\n");
		exit(1);
	}

	tmp2 -> after = tmp1;
 
	fprintf(stdout, "\nAfter calling cpnode() ... \n");
	fprintf(stdout, "---------------------------------------------\n");
	fprintf(stdout, "tmp1 has an address of:        %p\n",   &tmp1);
	fprintf(stdout, "tmp1 points to:                %p\n",    tmp1);
	fprintf(stdout, "tmp1 contains a info of:      %d\n",    tmp1 -> info);
	fprintf(stdout, "tmp1's after pointer points to: %p\n\n",  tmp1 -> after);

	fprintf(stdout, "tmp1's after contains info:    %d\n",    tmp1 -> after -> info);
	fprintf(stdout, "tmp1 after's after points to:    %p\n\n",  tmp1 -> after -> after);
 
	fprintf(stdout, "tmp2 has an address of:        %p\n",   &tmp2);
	fprintf(stdout, "tmp2 points to:                %p\n",    tmp2);
	fprintf(stdout, "tmp2 contains a info of:      %d\n",    tmp2 -> info);
	fprintf(stdout, "tmp2's after pointer points to: %p\n\n",  tmp2 -> after);

	fprintf(stdout, "draw this collection of nodes\n\n");

	return(0);
}
