#include <stdio.h>
#include "stack.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-rmstack.c  - unit test to evaluate stack remove functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkstack() and rmstack() functions must be fully
//                   operational.
//
//                   list manipulation is performed by provided
//                   support functions (src/support/)
//
int main()
{
    //////////////////////////////////////////////////////////////////
    //
    // Declare unit test variables
    //
    Stack  *stmp                     = NULL;
	List   *ltmp                     = NULL;
	Node   *ntmp                     = NULL;
    int     testno                   = 0;
	int     i                        = 0;
    code_t  result                   = 0;
    ulli    stack_size               = 7;

    //////////////////////////////////////////////////////////////////
    //
    // Display unit test header
    //
    fprintf(stdout, "===========================================\n");
    fprintf(stdout, "UNIT TEST: stack library rmstack() function\n");
    fprintf(stdout, "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = rmstack(NULL);
    fprintf(stdout, "Test %d: Running rmstack() on NULL pointer ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL stack
    //
    result                           = rmstack(&stmp);
    fprintf(stdout, "Test %d: Running rmstack() on NULL stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Actually create a new (EMPTY) stack, and call rmstack() on it
    //
    mkstack(&stmp, stack_size);
	fprintf(stdout, "(Before) contents of stack -> data:\n\t");
	listcat(stmp -> data);
	fprintf(stdout, "\n");
    result                           = rmstack(&stmp);
	fprintf(stdout, "(After)  contents of stack -> data:\n\t");
	if (stmp                        == NULL)
		listcat(NULL);
	else
		listcat(stmp -> data);
	fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Verify rmstack() status code(s)
    //
    fprintf(stdout, "Test %d: Checking rmstack() status on EMPTY stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_NULL | DLL_NULL | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: verify that stack is now NULL
    //
    fprintf(stdout,     "Test %d: Checking stack ...\n", testno++);
    if (stmp                        == NULL)
        fprintf(stdout, " you have: NULL stack (SUCCESS)\n");
    else if (stmp -> data           == NULL)
        fprintf(stdout, " you have: Stack still exists (ERROR)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: NULL stack (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Create another stack, and populate it (one node), and then
	// run rmstack() on it
    //
	stmp                             = NULL;
    mkstack(&stmp, stack_size-stack_size);
	ltmp                             = stmp -> data;
	for (i = 0; i < 1; i++)
	{
		ntmp                         = NULL;
		mknode(&ntmp,  i);
		catnode(&ltmp, ltmp -> last, ntmp);
	}
	stmp -> data                     = ltmp;
	stmp -> top                      = stmp -> data -> last;
	fprintf(stdout, "(Before) contents of stack -> data:\n\t");
	listcat(stmp -> data);
	fprintf(stdout, "\n");
    result                           = rmstack(&stmp);
	fprintf(stdout, "(After)  contents of stack -> data:\n\t");
	if (stmp                        == NULL)
		listcat(NULL);
	else
		listcat(stmp -> data);
	fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Fifth test: Verify rmstack() status code(s)
    //
    fprintf(stdout, "Test %d: Checking rmstack() status on EMPTY stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_NULL | DLL_NULL | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Verify that stack is now NULL
    //
    fprintf(stdout,     "Test %d: Checking stack ...\n", testno++);
    if (stmp                        == NULL)
        fprintf(stdout, " you have: NULL stack (SUCCESS)\n");
    else if (stmp -> data           == NULL)
        fprintf(stdout, " you have: Stack still exists (ERROR)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: NULL stack (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Create another stack, and populate it (two nodes), and then
	// run rmstack() on it
    //
	stmp                             = NULL;
    mkstack(&stmp, stack_size-stack_size);
	ltmp                             = stmp -> data;
	for (i = 0; i < 2; i++)
	{
		ntmp                         = NULL;
		mknode(&ntmp,  i);
		catnode(&ltmp, ltmp -> last, ntmp);
	}
	stmp -> data                     = ltmp;
	stmp -> top                      = stmp -> data -> last;
	fprintf(stdout, "(Before) contents of stack -> data:\n\t");
	listcat(stmp -> data);
	fprintf(stdout, "\n");
    result                           = rmstack(&stmp);
	fprintf(stdout, "(After)  contents of stack -> data:\n\t");
	if (stmp                        == NULL)
		listcat(NULL);
	else
		listcat(stmp -> data);
	fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Verify rmstack() status code(s)
    //
    fprintf(stdout, "Test %d: Checking rmstack() status on EMPTY stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_NULL | DLL_NULL | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Verify that stack is now NULL
    //
    fprintf(stdout,     "Test %d: Checking stack ...\n", testno++);
    if (stmp                        == NULL)
        fprintf(stdout, " you have: NULL stack (SUCCESS)\n");
    else if (stmp -> data           == NULL)
        fprintf(stdout, " you have: Stack still exists (ERROR)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: NULL stack (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Create another stack, and populate it (many nodes), and then
	// run rmstack() on it
    //
    mkstack(&stmp, stack_size-stack_size);
	ltmp                             = stmp -> data;
	for (i = 0; i < stack_size; i++)
	{
		ntmp                         = NULL;
		mknode(&ntmp,  i);
		catnode(&ltmp, ltmp -> last, ntmp);
	}
	stmp -> data                     = ltmp;
	stmp -> top                      = stmp -> data -> last;
	fprintf(stdout, "(Before) contents of stack -> data:\n\t");
	listcat(stmp -> data);
	fprintf(stdout, "\n");
    result                           = rmstack(&stmp);
	fprintf(stdout, "(After)  contents of stack -> data:\n\t");
	if (stmp                        == NULL)
		listcat(NULL);
	else
		listcat(stmp -> data);
	fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Verify rmstack() status code(s)
    //
    fprintf(stdout, "Test %d: Checking rmstack() status on EMPTY stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_NULL | DLL_NULL | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Verify that stack is now NULL
    //
    fprintf(stdout,     "Test %d: Checking stack ...\n", testno++);
    if (stmp                        == NULL)
        fprintf(stdout, " you have: NULL stack (SUCCESS)\n");
    else if (stmp -> data           == NULL)
        fprintf(stdout, " you have: Stack still exists (ERROR)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: NULL stack (SUCCESS)\n\n"); 
    fflush (stdout);

    fprintf(stdout, "===========================================\n\n");

    return(0);
}
