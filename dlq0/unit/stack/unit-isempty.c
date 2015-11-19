#include <stdio.h>
#include "stack.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-isempty.c  - unit test to evaluate isempty() functionality.
//
//    prerequisites: to successfully run this unit test, the
//                   mkstack() and isempty() functions must be
//                   fully operational.
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
    fprintf(stdout, "UNIT TEST: stack library isempty() function\n");
    fprintf(stdout, "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = isempty(NULL);
    fprintf(stdout, "Test %d: Running isempty() on NULL pointer ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL stack
    //
    result                           = isempty(stmp);
    fprintf(stdout, "Test %d: Running isempty() on NULL stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
	// Create a new stack
	//
	mkstack(&stmp, stack_size);
	fprintf(stdout, "Stack contains: ");
	listcat(stmp -> data);
	fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Evaluate EMPTY stack
    //
    result                           = isempty(stmp);
    fprintf(stdout, "Test %d: Running isempty() on EMPTY stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_EMPTY); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the stack with one node
    //
    ltmp                             = stmp -> data;
    for (i = 0; i < 1; i++)
    {
		ntmp                         = NULL;
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    stmp -> data                     = ltmp;
    stmp -> top                      = ltmp -> last;
	fprintf(stdout, "Stack contains: ");
	listcat(stmp -> data);
	fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Evaluate populated stack (one node)
    //
    result                           = isempty(stmp);
    fprintf(stdout, "Test %d: Running isempty() on non-EMPTY stack (1/2) ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_OVERFLOW); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the stack with additional nodes
    //
    ltmp                             = stmp -> data;
    for (i = 1; i < stack_size; i++)
    {
		ntmp                         = NULL;
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    stmp -> data                     = ltmp;
    stmp -> top                      = stmp -> data -> last;
	fprintf(stdout, "Stack contains: ");
	listcat(stmp -> data);
	fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Fifth test: Evaluate populated stack (many nodes)
    //
    result                           = isempty(stmp);
    fprintf(stdout, "Test %d: Running isempty() on non-EMPTY stack (2/2) ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_OVERFLOW); 
	fprintf(stdout, "\n");
    fflush (stdout);

    fprintf(stdout, "===========================================\n\n");

    return(0);
}
