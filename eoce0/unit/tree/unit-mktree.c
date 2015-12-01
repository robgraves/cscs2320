#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
	Tree   *myTree           = NULL;
    int     testno           = 0;
	code_t  result           = 0;

    fprintf(stdout,     "UNIT TEST: tree library mktree() function\n");
    fprintf(stdout,     "=========================================\n");

    fprintf(stdout,     "Test %d: NULL test ...\n", testno++);
    result                   = mktree(NULL, 15);
	fprintf(stdout,     " you have: ");
	showcode(result);
	fprintf(stdout,     "should be: ");
	showcode(DLT_FAIL | DLT_NULL);
	fprintf(stdout,     "\n");
	fflush (stdout);

    fprintf(stdout,     "Test %d: Creating new tree ...\n", testno++);
    result                   = mktree(&myTree, 17);
    if (myTree              == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: something (success)\n");

    fprintf(stdout,     "should be: something (success)\n\n"); 
    fflush (stdout);

	fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,     " you have: ");
	showcode(result);
	fprintf(stdout,     "should be: ");
	showcode(DLT_SUCCESS | DLT_EMPTY);
	fprintf(stdout,     "\n");
	fflush (stdout);

    fprintf(stdout,     "Test %d: Checking root ...\n", testno++);
    if (myTree -> root      == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: something\n");

    fprintf(stdout,     "should be: NULL\n\n"); 
    fflush (stdout);

    fprintf(stdout,     "Test %d: Checking tree maximum height ...\n", testno++);
    if (myTree -> max_height == 17)
        fprintf(stdout, " you have: 17 (correct)\n");
    else
        fprintf(stdout, " you have: something else\n");

    fprintf(stdout,     "should be: 17 (correct)\n\n"); 
    fflush (stdout);

    fprintf(stdout,     "Test %d: Creating new tree on existing tree pointer ...\n", testno++);
    result                   = mktree(&myTree, 19);
    if (myTree              == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: something (success)\n");

    fprintf(stdout,     "should be: NULL\n\n"); 
    fflush (stdout);

	fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,     " you have: ");
	showcode(result);
	fprintf(stdout,     "should be: ");
	showcode(DLT_FAIL | DLT_NULL | DLT_CREATE_FAIL);
	fprintf(stdout,     "\n");
	fflush (stdout);

    return(0);
}
