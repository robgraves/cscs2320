#include <stdio.h>
#include "stack.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-mkstack.c  - unit test to evaluate stack create functionality.
//
//    prerequisites: to successfully run this unit test, the mkstack()
//                   function must be fully operational.
//
//                   any list manipulation is performed by provided
//                   support functions (src/support/)
//
int main()
{
    //////////////////////////////////////////////////////////////////
    //
    // Declare unit test variables
    //
    Stack  *stmp                     = NULL;
    int     testno                   = 0;
    code_t  result                   = 0;
    ulli    stack_size               = 7;

    //////////////////////////////////////////////////////////////////
    //
    // Display unit test header
    //
    fprintf(stdout, "===========================================\n");
    fprintf(stdout, "UNIT TEST: stack library mkstack() function\n");
    fprintf(stdout, "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = mkstack(NULL, stack_size);
    fprintf(stdout, "Test %d: Running mkstack() on NULL pointer ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_ERROR | DLS_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Actually create a new stack
    //
    result                           = mkstack(&stmp, stack_size);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Verify mkstack() status code(s)
    //
    fprintf(stdout, "Test %d: Creating new stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_SUCCESS | DLS_EMPTY | DLL_EMPTY | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Verify stack's data element exists, and is EMPTY
    //
    fprintf(stdout,     "Test %d: Checking stack data ...\n", testno++);
    if (stmp       -> data          == NULL)
        fprintf(stdout, " you have: NULL list element in stack (ERROR)\n");
    else if ((stmp -> data -> first == NULL) &&
                (stmp -> data -> last  == NULL))
        fprintf(stdout, " you have: EMPTY list (SUCCESS)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: EMPTY list (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Verify top exists, and is NULL (just like first)
    //
    fprintf(stdout,     "Test %d: Checking top in new stack ...\n", testno++);
    if (stmp       -> data          == NULL)
        fprintf(stdout, " you have: NULL list element in stack (ERROR)\n");
    else if (stmp  -> top           == stmp -> data -> first)
        fprintf(stdout, " you have: top exists (SUCCESS)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: top exists (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifth test: Checking stack size
    //
    fprintf(stdout, "Test %d: Checking size ...\n", testno++);
    fprintf(stdout, " you have: %llu\n",            stmp -> size);
    fprintf(stdout, "should be: %llu\n\n",          stack_size); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Create another stack
    //
    result                           = mkstack(&stmp, stack_size-stack_size);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Verify mkstack() status code(s)
    //
    fprintf(stdout, "Test %d: Creating another stack ...\n", testno++);
    fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLS_CREATE_FAIL | DLS_ERROR); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Verify stack's data element
    //
    fprintf(stdout,     "Test %d: Checking stack data ...\n", testno++);
    if (stmp       -> data          == NULL)
        fprintf(stdout, " you have: NULL list element in stack (ERROR)\n");
    else if ((stmp -> data -> first == NULL) &&
                (stmp -> data -> last  == NULL))
        fprintf(stdout, " you have: EMPTY list (SUCCESS)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: EMPTY list (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Verify top exists, and is NULL (just like first)
    //
    fprintf(stdout,     "Test %d: Checking top in stack ...\n", testno++);
    if (stmp       -> data          == NULL)
        fprintf(stdout, " you have: NULL list element in stack (ERROR)\n");
    else if (stmp  -> top           == stmp -> data -> first)
        fprintf(stdout, " you have: top exists (SUCCESS)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: top exists (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Checking stack size
    //
    fprintf(stdout, "Test %d: Checking size ...\n", testno++);
    fprintf(stdout, " you have: %llu\n",            stmp -> size);
    fprintf(stdout, "should be: %llu\n\n",          stack_size); 
    fflush (stdout);

    fprintf(stdout, "===========================================\n\n");

    return(0);
}
