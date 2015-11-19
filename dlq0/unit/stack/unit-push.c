#include <stdio.h>
#include "stack.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-push.c     - unit test to evaluate stack push functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkstack() and push() functions must be fully
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
    Node   *ntmp                     = NULL;
    int     testno                   = 0;
    code_t  result                   = 0;

    //////////////////////////////////////////////////////////////////
    //
    // Display unit test header
    //
    fprintf(stdout, "========================================\n");
    fprintf(stdout, "UNIT TEST: stack library push() function\n");
    fprintf(stdout, "========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = push(NULL, NULL);
    fprintf(stdout, "Test %d: Running push() on NULL pointers ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL stack, non-existent node
    //
    result                           = push(&stmp, NULL);
    fprintf(stdout, "Test %d: Running push() on NULL stack, non-existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Evaluate NULL stack, existent node
    //
    result                           = push(NULL, ntmp);
    fprintf(stdout, "Test %d: Running push() on non-existent stack, existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Evaluate NULL stack, NULL node
    //
    result                           = push(&stmp, ntmp);
    fprintf(stdout, "Test %d: Running push() on NULL stack, NULL node ...\n", testno++);
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
    mkstack(&stmp, 2);
    result                           = push(&stmp, NULL);
    fprintf(stdout, "Test %d: Running push() on EMPTY stack, non-existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Evaluate EMPTY stack (existent node)
    //
    result                           = push(&stmp, ntmp);
    fprintf(stdout, "Test %d: Running push() on EMPTY stack, existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Evaluate transition to populated state
    //
	mknode(&ntmp,  12);
    result                           = push(&stmp, ntmp);
    fprintf(stdout, "Test %d: Running push() to populate stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Check stack
    //
    fprintf(stdout,     "Test %d: Checking stack (1/2) ...\n", testno++);
    if (stmp -> top                 == NULL)
        fprintf(stdout, " you have: NULL node (ERROR)\n");
    else
        fprintf(stdout, " you have: non-NULL node (SUCCESS)\n");
    fprintf(stdout,     "should be: non-NULL node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Check stack 2
    //
    fprintf(stdout, "Test %d: Checking stack (2/2) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   stmp -> top  -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", 12); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Evaluate populated stack (non-existent node)
    //
    result                           = push(&stmp, NULL);
    fprintf(stdout, "Test %d: Running push() on stack, non-existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eleventh test: Evaluate populated state -- second try
    //
	ntmp                             = NULL;
	mknode(&ntmp,  24);
    result                           = push(&stmp, ntmp);
    fprintf(stdout, "Test %d: Running push() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Twelfth test: Check stack -- second try
    //
    fprintf(stdout,     "Test %d: Checking stack (1/2) ...\n", testno++);
    if (stmp -> top                 == NULL)
        fprintf(stdout, " you have: NULL node (ERROR)\n");
    else
        fprintf(stdout, " you have: non-NULL node (SUCCESS)\n");
    fprintf(stdout,     "should be: non-NULL node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Thirteenth test: Check stack 2 -- second try
    //
    fprintf(stdout, "Test %d: Checking stack (2/2) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   stmp -> top  -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", 24); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourteenth test: Instigate stack overflow
    //
	ntmp                             = NULL;
	mknode(&ntmp,  36);
    result                           = push(&stmp, ntmp);
    fprintf(stdout, "Test %d: Running push() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLS_OVERFLOW); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Hack stack size to infinite
    //
	stmp -> size                     = 0;

    //////////////////////////////////////////////////////////////////
    //
    // Fifteenth test: Evaluate populated state (many nodes)
    //
    result                           = push(&stmp, ntmp);
    fprintf(stdout, "Test %d: Running push() on populated stack ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixteenth test: Check stack
    //
    fprintf(stdout,     "Test %d: Checking stack (1/2) ...\n", testno++);
    if (stmp -> top                 == NULL)
        fprintf(stdout, " you have: NULL node (ERROR)\n");
    else
        fprintf(stdout, " you have: non-NULL node (SUCCESS)\n");
    fprintf(stdout,     "should be: non-NULL node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventeenth test: Check stack 2
    //
    fprintf(stdout, "Test %d: Checking stack (2/2) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   stmp -> top  -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", 36); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighteenth test: Evaluate stack (non-existent node)
    //
    result                           = push(&stmp, NULL);
    fprintf(stdout, "Test %d: Running push() on stack, non-existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLS_ERROR | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    fprintf(stdout, "========================================\n\n");

    return(0);
}
