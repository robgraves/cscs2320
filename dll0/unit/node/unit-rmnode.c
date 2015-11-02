#include <stdio.h>
#include "node.h"
#include "support.h"

int main()
{
	Node   *tmp     = NULL;
	int     testno  = 0;
	code_t  result  = 0;

	fprintf(stdout, "UNIT TEST: node library rmnode() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "\nTest %d: Checking NULL case ...\n", testno++);
	result          = rmnode(NULL);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLN_INVALID);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Removing NULL node ...\n", testno++);
	result          = rmnode(&tmp);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLN_NULL);
	fflush (stdout);

	mknode(&tmp, 37);
	if (tmp == NULL)
	{
		fprintf(stderr, "ERROR: node is NULL\n");
		exit(1);
	}

	fprintf(stdout, "\nTest %d: Removing node ...\n", testno++);
	result          = rmnode(&tmp);
	if (tmp == NULL)
		fprintf(stdout, " you have: NULL (success)\n");
	else
		fprintf(stdout, " you have: something\n");

	fprintf(stdout, "should be: NULL (success)\n"); 
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_SUCCESS | DLN_NULL);
	fflush (stdout);

	return(0);
}
