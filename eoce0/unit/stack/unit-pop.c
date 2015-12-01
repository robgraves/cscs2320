#include <stdio.h>
#include "stack.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-pop.c      - unit test to evaluate stack pop functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkstack() and pop() functions must be fully
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
    ulli    stack_size               = 3;

    //////////////////////////////////////////////////////////////////
    //
    // Display unit test header
    //
    fprintf(stdout, "=======================================\n");
    fprintf(stdout, "UNIT TEST: stack library pop() function\n");
    fprintf(stdout, "=======================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = pop(NULL, NULL);
    fprintf(stdout, "Test %d: Running pop() on NULL pointers ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL stack, non-existent popNode
    //
    result                           = pop(&stmp, NULL);
    fprintf(stdout, "Test %d: Running pop() on NULL stack, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Evaluate NULL stack, existent popNode
    //
	ntmp                             = NULL;
    result                           = pop(NULL, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on non-existent stack, existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Evaluate NULL stack, NULL destination
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on NULL stack, NULL destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifth test: Evaluate EMPTY stack (non-existent destination)
    //
    mkstack(&stmp, 0);
    result                           = pop(&stmp, NULL);
    fprintf(stdout, "Test %d: Running pop() on EMPTY stack, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLN_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Evaluate EMPTY stack (existent destination)
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on EMPTY stack, existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_EMPTY | DLS_UNDERFLOW | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the stack (one node)
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

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Evaluate populated stack (non-existent destination)
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, NULL);
    fprintf(stdout, "Test %d: Running pop() on stack, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLN_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Evaluate populated state (1 node)
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS | DLS_EMPTY); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Check popped node
    //
    fprintf(stdout, "Test %d: Checking node ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", 0); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Check top (should be NULL)
    //
    fprintf(stdout, "Test %d: Checking top ...\n", testno++);
	if (stmp -> top                 == NULL)
		fprintf(stdout, " you have: stack is empty (SUCCESS)\n");
	else
		fprintf(stdout, " you have: stack is NOT empty (ERROR)\n");
    fprintf(stdout, "should be: stack is empty (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eleventh test: Evaluate populated state (EMPTY)
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on emptied stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_EMPTY | DLS_UNDERFLOW | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the stack (many nodes)
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
	i                                = stack_size - 1;

    //////////////////////////////////////////////////////////////////
    //
    // Twelfth test: Evaluate populated state (many nodes)
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Thirteenth test: Check node
    //
    fprintf(stdout, "Test %d: Checking popped node ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", i--); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourteenth test: Evaluate populated state (many nodes)
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifteenth test: Check node
    //
    fprintf(stdout, "Test %d: Checking popped node ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", i--); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixteenth test: Evaluate populated state (last node in stack)
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS | DLS_EMPTY); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventeenth test: Check node
    //
    fprintf(stdout, "Test %d: Checking popped node ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", i--); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighteenth test: Evaluate populated state (EMPTY stack)
    //
	ntmp                             = NULL;
    result                           = pop(&stmp, &ntmp);
    fprintf(stdout, "Test %d: Running pop() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_EMPTY | DLS_UNDERFLOW | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Nineteenth test: Check node
    //
    fprintf(stdout, "Test %d: Checking popped node ...\n", testno++);
	if (ntmp                        == NULL)
		fprintf(stdout, " you have: NULL (SUCCESS)\n");
	else
		fprintf(stdout, " you have: node is NOT NULL (ERROR)\n");
    fprintf(stdout, "should be: NULL (SUCCESS)\n\n"); 
    fflush (stdout);

    fprintf(stdout, "=======================================\n\n");

    return(0);
}
