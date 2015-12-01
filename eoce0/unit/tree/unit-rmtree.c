#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
	Tree   *myTree           = NULL;
    int     testno           = 0;
	int     i                = 0;
	code_t  result           = 0;

    fprintf(stdout,     "UNIT TEST: tree library rmtree() function\n");
    fprintf(stdout,     "=========================================\n");

    fprintf(stdout,     "Test %d: Removing NULL tree ...\n", testno++);
    result                   = rmtree(&myTree);
    if (myTree              == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: something\n");

    fprintf(stdout,     "should be: NULL\n\n"); 
    fflush (stdout);

	fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,     " you have: ");
	showcode(result);
	fprintf(stdout,     "should be: ");
	showcode(DLT_FAIL | DLT_NULL);
	fprintf(stdout,     "\n");

    fflush (stdout);

    fprintf(stdout,     "Test %d: Removing empty tree ...\n", testno++);
    mktree(&myTree, 17);
    result                   = rmtree(&myTree);
    if (myTree              == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: something\n");

    fprintf(stdout,     "should be: NULL\n\n"); 
    fflush (stdout);

	fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,     " you have: ");
	showcode(result);
	fprintf(stdout,     "should be: ");
	showcode(DLT_FAIL | DLT_SUCCESS);
	fprintf(stdout,     "\n");
    fflush (stdout);

    fprintf(stdout,     "Test %d: Removing populated tree ...\n", testno++);
    mktree(&myTree, 17);

	for (i = 0; i < 9; i++)
		addnode(&myTree, mknode(i));

    result                   = rmtree(&myTree);
    if (myTree              == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: something\n");

    fprintf(stdout,     "should be: NULL\n\n"); 
    fflush (stdout);

	fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,     " you have: ");
	showcode(result);
	fprintf(stdout,     "should be: ");
	showcode(DLT_FAIL | DLT_SUCCESS);
	fprintf(stdout,     "\n");
    fflush (stdout);

    return(0);
}
