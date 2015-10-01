#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
	Node *tmp    = NULL;
	int   testno = 0;

	fprintf(stdout, "UNIT TEST: node library rmnode() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "Test %d: Removing NULL node ...\n", testno++);
	tmp          = rmnode(tmp);
	if (tmp == NULL)
		fprintf(stdout, " you have: NULL (success)\n");
	else
		fprintf(stdout, " you have: something\n");

	fprintf(stdout, "should be: NULL (success)\n\n"); 
	fflush(stdout);

	tmp          = mknode(37);
	if (tmp == NULL)
	{
		fprintf(stderr, "ERROR: node is NULL\n");
		exit(1);
	}

	fprintf(stdout, "Test %d: Removing node ...\n", testno++);
	tmp          = rmnode(tmp);
	if (tmp == NULL)
		fprintf(stdout, " you have: NULL (success)\n");
	else
		fprintf(stdout, " you have: something\n");

	fprintf(stdout, "should be: NULL (success)\n\n"); 
	fflush(stdout);

	return(0);
}
