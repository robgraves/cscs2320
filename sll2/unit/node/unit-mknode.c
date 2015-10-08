#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
	Node *tmp    = NULL;
	Node *tmp2   = NULL;
	int   testno = 0;

	fprintf(stdout, "UNIT TEST: node library mknode() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "Test %d: Creating new node ...\n", testno++);
	tmp          = mknode(24);
	if (tmp == NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: something (success)\n");

	fprintf(stdout, "should be: something (success)\n\n"); 
	fflush(stdout);

	fprintf(stdout, "Test %d: Creating another node ...\n", testno++);
	tmp2         = mknode(37);
	if (tmp2 == NULL)
		fprintf(stdout, " you have: NULL\n");
	else if (tmp == tmp2)
		fprintf(stdout, " you have: the same node from the first test\n");
	else
		fprintf(stdout, " you have: something (success)\n");

	fprintf(stdout, "should be: something (success)\n\n"); 
	fflush(stdout);

	fprintf(stdout, "Test %d: Checking value in node ...\n", testno++);
	if (tmp == NULL)
		fprintf(stdout, " you have: NULL\n");
	else if (tmp -> info == 24)
		fprintf(stdout, " you have: correct value (success)\n");
	else
		fprintf(stdout, " you have: something else\n");

	fprintf(stdout, "should be: correct value (success)\n\n"); 
	fflush(stdout);

	fprintf(stdout, "Test %d: Checking state of after ...\n", testno++);
	if (tmp == NULL)
		fprintf(stdout, " you have: NULL node\n");
	else if (tmp -> after == NULL)
		fprintf(stdout, " you have: after is NULL (success)\n");
	else
		fprintf(stdout, " you have: something else\n");

	fprintf(stdout, "should be: after is NULL (success)\n\n"); 
	fflush(stdout);

	return(0);
}
