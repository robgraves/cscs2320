#include <stdio.h>
#include "queue.h"
#include "support.h"

int main()
{
    Queue  *qtmp          = NULL;
    int     testno        = 0;
    code_t  result        = 0;

    fprintf(stdout, "UNIT TEST: queue library mkqueue() function\n");
    fprintf(stdout, "===========================================\n");

    fprintf(stdout, "Test %d: Attempting non-existant queue ...\n", testno++);
    result                = mkqueue(NULL, 7);
	fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLQ_ERROR | DLQ_INVALID);
	fprintf(stdout, "\n"); 
    fflush (stdout);

    fprintf(stdout, "Test %d: Creating new queue ...\n", testno++);
    result                = mkqueue(&qtmp, 7);
    if (qtmp             == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: *NOT* NULL (success)\n");
    fprintf(stdout, "should be: *NOT* NULL (success)\n\n"); 
    fflush(stdout);

    fprintf(stdout, "Test %d: Checking front ...\n", testno++);
    if (qtmp -> data     == NULL)
        fprintf(stdout, " you have: NULL list element in queue\n");
    else if (qtmp -> front == qtmp -> data -> first)
        fprintf(stdout, " you have: SUCCESS\n");
    else
        fprintf(stdout, " you have: ERROR\n");
    fprintf(stdout, "should be: SUCCESS\n\n"); 
    fflush(stdout);

    fprintf(stdout, "Test %d: Checking back ...\n", testno++);
    if (qtmp -> data     == NULL)
        fprintf(stdout, " you have: NULL list element in queue\n");
    else if (qtmp -> back == qtmp -> data -> last)
        fprintf(stdout, " you have: SUCCESS\n");
    else
        fprintf(stdout, " you have: ERROR\n");
    fprintf(stdout, "should be: SUCCESS\n\n"); 
    fflush(stdout);

    fprintf(stdout, "Test %d: Checking buffer ...\n", testno++);
    if (qtmp -> buffer     == 7)
        fprintf(stdout, " you have: SUCCESS\n");
    else
        fprintf(stdout, " you have: ERROR\n");

    fprintf(stdout, "should be: SUCCESS\n\n"); 
    fflush(stdout);

    fprintf(stdout, "Test %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
    fprintf(stdout, "should be: ");
	lscodes(DLQ_SUCCESS | DLQ_EMPTY | DLL_EMPTY | DLL_SUCCESS);
	fprintf(stdout, "\n"); 
    fflush (stdout);

    return(0);
}
