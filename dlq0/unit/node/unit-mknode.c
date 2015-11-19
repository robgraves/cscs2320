#include <stdio.h>
#include "node.h"
#include "support.h"

int main()
{
	Node   *tmp    = NULL;
	Node   *tmp2   = NULL;
	code_t  result = 0;
	int     testno = 0;

	fprintf(stdout, "UNIT TEST: node library mknode() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "\nTest %d: Checking for NULL handling ...\n", testno++);
	result         = mknode(NULL, 0);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLN_INVALID);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Creating a new node ...\n", testno++);
	result         = mknode(&tmp, 24);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking new node ...\n", testno++);
	if (tmp == NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: something (success)\n");
	fprintf(stdout, "should be: something (success)\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking new node's value ...\n", testno++);
	fprintf(stdout, " you have: %hhd\n", tmp -> VALUE);
	fprintf(stdout, "should be: 24\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking new node's after pointer ...\n", testno++);
	if (tmp -> after== NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: something else\n");
	fprintf(stdout, "should be: NULL\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking new node's prior pointer ...\n", testno++);
	if (tmp -> prior== NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: something else\n");
	fprintf(stdout, "should be: NULL\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Creating an existing node ...\n", testno++);
	result         = mknode(&tmp, 36);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLN_ALREADY_ALLOC);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Creating another new node ...\n", testno++);
	result         = mknode(&tmp2, 48);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking new node ...\n", testno++);
	if (tmp2 == NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: something (success)\n");
	fprintf(stdout, "should be: something (success)\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking new node's value ...\n", testno++);
	fprintf(stdout, " you have: %hhd\n", tmp2 -> VALUE);
	fprintf(stdout, "should be: 48\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking new node's after pointer ...\n", testno++);
	if (tmp2 -> after == NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: something else\n");
	fprintf(stdout, "should be: NULL\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking new node's prior pointer ...\n", testno++);
	if (tmp2 -> prior == NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: something else\n");
	fprintf(stdout, "should be: NULL\n"); 
	fflush (stdout);

	return(0);
}
