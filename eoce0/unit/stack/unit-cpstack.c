#include <stdio.h>
#include "stack.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-cpstack.c  - unit test to evaluate stack copy functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkstack() and cpstack() functions must be fully
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
    Stack  *stmp2                    = NULL;
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
    fprintf(stdout, "UNIT TEST: stack library cpstack() function\n");
    fprintf(stdout, "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = cpstack(NULL, NULL);
    fprintf(stdout, "Test %d: Running cpstack() on NULL pointers ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL stack, non-existent destination
    //
    result                           = cpstack(stmp, NULL);
    fprintf(stdout, "Test %d: Running cpstack() on NULL stack, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Evaluate NULL stack, NULL destination
    //
    result                           = cpstack(stmp, &stmp2);
    fprintf(stdout, "Test %d: Running cpstack() on NULL stack, NULL destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Evaluate NULL stack (empty destination)
    //
    mkstack(&stmp2, 0);
    result                           = cpstack(stmp, &stmp2);
    fprintf(stdout, "Test %d: Running cpstack() on NULL stack, EMPTY destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifth test: Evaluate empty stack (empty destination)
    //
    mkstack(&stmp, 0);
    result                           = cpstack(stmp, &stmp2);
    fprintf(stdout, "Test %d: Running cpstack() on EMPTY stack, EMPTY destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_ERROR | DLS_CREATE_FAIL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Evaluate empty stack (NULL destination)
    //
    stmp2                            = NULL;
    result                           = cpstack(stmp, &stmp2);
    fprintf(stdout, "Test %d: Running cpstack() on EMPTY stack, NULL destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_EMPTY | DLL_SUCCESS | DLL_EMPTY); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Verify cpstack() operations
    //
    fprintf(stdout,     "Test %d: Checking copied stack ...\n", testno++);
	if (stmp2                        == NULL)
		fprintf(stdout, " you have: NULL stack (ERROR)\n");
	else if (stmp2 -> data           == stmp -> data)
		fprintf(stdout, " you have: same data element (ERROR)\n");
	else if (stmp2 -> data           != stmp -> data)
		fprintf(stdout, " you have: different data elements (SUCCESS)\n");
	else
		fprintf(stdout, " you have: some other error state\n");
	fprintf(stdout,     "should be: different data elements (SUCCESS)\n\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the stack and perform a copy
    //
    ltmp                             = stmp -> data;
    for (i = 0; i < stack_size; i++)
    {
		ntmp                         = NULL;
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    stmp -> data                     = ltmp;
    stmp -> top                      = stmp -> data -> last;
	stmp2                            = NULL;
	result                           = cpstack(stmp, &stmp2);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Verify cpstack() status code(s)
    //
    fprintf(stdout, "Test %d: Checking cpstack() status code(s) ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Verify that stack has been copied
    //
    fprintf(stdout, "Test %d: Displaying stacks ...\n", testno++);
	fprintf(stdout, " you have: ");
    listcat(stmp  -> data);
    fprintf(stdout, "should be: "); 
    listcat(stmp2 -> data);
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Verify that stacks are indeed different
    //
	i                                = stmp -> data -> first -> after -> VALUE;
	stmp -> data -> first -> after -> VALUE  = 29;
    fprintf(stdout,     "Test %d: Checking stacks (1 of 2) ...\n", testno++);
    if (stmp2 -> data -> first -> after -> VALUE == i)
        fprintf(stdout, " you have: difference detected (SUCCESS)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: difference detected (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eleventh test: Verify that stacks are indeed different
    //
    fprintf(stdout,     "Test %d: Checking stacks (2 of 2) ...\n", testno++);
    if (stmp -> data -> first -> after -> VALUE == 29)
        fprintf(stdout, " you have: difference detected (SUCCESS)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: difference detected (SUCCESS)\n\n"); 
    fflush (stdout);

    fprintf(stdout, "===========================================\n\n");

    return(0);
}
