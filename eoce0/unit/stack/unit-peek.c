#include <stdio.h>
#include "stack.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-peek.c     - unit test to evaluate stack peek functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkstack() and peek() functions must be fully
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
    fprintf(stdout, "========================================\n");
    fprintf(stdout, "UNIT TEST: stack library peek() function\n");
    fprintf(stdout, "========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = peek(NULL, NULL);
    fprintf(stdout, "Test %d: Running peek() on NULL pointers ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL stack, non-existent peekNode
    //
    result                           = peek(stmp, NULL);
    fprintf(stdout, "Test %d: Running peek() on NULL stack, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Evaluate NULL stack, existent peekNode
    //
    result                           = peek(NULL, &ntmp);
    fprintf(stdout, "Test %d: Running peek() on non-existent stack, existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Evaluate NULL stack, NULL destination
    //
    result                           = peek(stmp, &ntmp);
	fprintf(stdout, "Test %d: Running peek() on NULL stack, NULL destination ...\n", testno++);
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
    result                           = peek(stmp, NULL);
    fprintf(stdout, "Test %d: Running peek() on EMPTY stack, non-existent destination ...\n", testno++);
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
    result                           = peek(stmp, &ntmp);
    fprintf(stdout, "Test %d: Running peek() on EMPTY stack, existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS | DLS_EMPTY); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the stack (one node)
    //
    ltmp                             = stmp -> data;
    for (i = 0; i < 1; i++)
    {
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    stmp -> data                     = ltmp;
    stmp -> top                      = ltmp -> last;

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Evaluate populated state (1 node)
    //
    result                           = peek(stmp, &ntmp);
    fprintf(stdout, "Test %d: Running peek() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Check peeked node
    //
    fprintf(stdout, "Test %d: Checking node (1/1) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", stmp -> top -> VALUE); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Check peeked node 2
    //
    fprintf(stdout, "Test %d: Checking node (2/2) ...\n", testno++);
	if (ntmp                        == stmp -> top)
		fprintf(stdout, " you have: same node (ERROR)\n");
	else
		fprintf(stdout, " you have: different node (SUCCESS)\n");
    fprintf(stdout, "should be: different node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Evaluate populated stack (non-existent destination)
    //
    result                           = peek(stmp, NULL);
    fprintf(stdout, "Test %d: Running peek() on stack, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLN_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Intentionally modify ntmp (should have no impact on stack)
    //
	ntmp -> VALUE                    = 52;
	ntmp -> prior                    = ntmp;
	ntmp -> after                    = ntmp;

    //////////////////////////////////////////////////////////////////
    //
    // Eleventh test: Evaluate populated state (1 node) -- second try
    //
    result                           = peek(stmp, &ntmp);
    fprintf(stdout, "Test %d: Running peek() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Twelfth test: Check peeked node -- second try
    //
    fprintf(stdout, "Test %d: Checking node (1/2) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", stmp -> top -> VALUE); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Thirteenth test: Check peeked node 2 -- second try
    //
    fprintf(stdout, "Test %d: Checking node (2/2) ...\n", testno++);
	if (ntmp                        == stmp -> top)
		fprintf(stdout, " you have: same node (ERROR)\n");
	else
		fprintf(stdout, " you have: different node (SUCCESS)\n");
    fprintf(stdout, "should be: different node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the stack (many nodes)
    //
    ltmp                             = stmp -> data;
    for (i = 1; i < stack_size; i++)
    {
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    stmp -> data                     = ltmp;
    stmp -> top                      = ltmp -> last;

    //////////////////////////////////////////////////////////////////
    //
    // Fourteenth test: Evaluate populated state (many nodes)
    //
    result                           = peek(stmp, &ntmp);
    fprintf(stdout, "Test %d: Running peek() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifteenth test: Check peeked node
    //
    fprintf(stdout, "Test %d: Checking node (1/2) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", stmp -> top -> VALUE); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixteenth test: Check peeked node 2
    //
    fprintf(stdout, "Test %d: Checking node (2/2) ...\n", testno++);
	if (ntmp                        == stmp -> top)
		fprintf(stdout, " you have: same node (ERROR)\n");
	else
		fprintf(stdout, " you have: different node (SUCCESS)\n");
    fprintf(stdout, "should be: different node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventeenth test: Evaluate stack (non-existent destination)
    //
    result                           = peek(stmp, NULL);
    fprintf(stdout, "Test %d: Running peek() on stack, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLN_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Intentionally modify ntmp (should have no impact on stack)
    //
	ntmp -> VALUE                    = 37;
	ntmp -> prior                    = stmp -> data -> last;
	ntmp -> after                    = stmp -> data -> first;

    //////////////////////////////////////////////////////////////////
    //
    // Eighteenth test: Evaluate populated state (many) -- 2nd try
    //
    result                           = peek(stmp, &ntmp);
    fprintf(stdout, "Test %d: Running peek() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Nineteenth test: Check peeked node -- second try
    //
    fprintf(stdout, "Test %d: Checking node (1/1) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", stmp -> top -> VALUE); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Twentieth test: Check peeked node 2 -- second try
    //
    fprintf(stdout, "Test %d: Checking node (2/2) ...\n", testno++);
	if (ntmp                        == stmp -> top)
		fprintf(stdout, " you have: same node (ERROR)\n");
	else
		fprintf(stdout, " you have: different node (SUCCESS)\n");
    fprintf(stdout, "should be: different node (SUCCESS)\n\n"); 
    fflush (stdout);

    fprintf(stdout, "========================================\n\n");

    return(0);
}
