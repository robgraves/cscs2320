#include <stdio.h>
#include "queue.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-enqueue.c  - unit test to evaluate queue enqueue
//                   functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkqueue() and enqueue() functions must be fully
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
    Queue  *qtmp                     = NULL;
    Node   *ntmp                     = NULL;
    int     testno                   = 0;
    code_t  result                   = 0;

    //////////////////////////////////////////////////////////////////
    //
    // Display unit test header
    //
    fprintf(stdout, "===========================================\n");
    fprintf(stdout, "UNIT TEST: queue library enqueue() function\n");
    fprintf(stdout, "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = enqueue(NULL, NULL);
    fprintf(stdout, "Test %d: Running enqueue() on NULL pointers ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL queue, non-existent node
    //
    result                           = enqueue(&qtmp, NULL);
    fprintf(stdout, "Test %d: Running enqueue() on NULL queue, non-existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Evaluate NULL queue, existent node
    //
    result                           = enqueue(NULL, ntmp);
    fprintf(stdout, "Test %d: Running enqueue() on non-existent queue, existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Evaluate NULL queue, NULL node
    //
    result                           = enqueue(&qtmp, ntmp);
    fprintf(stdout, "Test %d: Running enqueue() on NULL queue, NULL node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifth test: Evaluate EMPTY queue (non-existent destination)
    //
    mkqueue(&qtmp, 2);
    result                           = enqueue(&qtmp, NULL);
    fprintf(stdout, "Test %d: Running enqueue() on EMPTY queue, non-existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Evaluate EMPTY queue (existent node)
    //
    result                           = enqueue(&qtmp, ntmp);
    fprintf(stdout, "Test %d: Running enqueue() on EMPTY queue, existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Evaluate transition to populated state
    //
	mknode(&ntmp,  12);
    result                           = enqueue(&qtmp, ntmp);
    fprintf(stdout, "Test %d: Running enqueue() to populate queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Check queue
    //
    fprintf(stdout,     "Test %d: Checking queue (1/2) ...\n", testno++);
    if (qtmp -> front              == NULL)
        fprintf(stdout, " you have: NULL node (ERROR)\n");
    else
        fprintf(stdout, " you have: non-NULL node (SUCCESS)\n");
    fprintf(stdout,     "should be: non-NULL node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Check queue 2
    //
    fprintf(stdout, "Test %d: Checking queue (2/2) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   qtmp -> front -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", 12); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Evaluate populated queue (non-existent node)
    //
    result                           = enqueue(&qtmp, NULL);
    fprintf(stdout, "Test %d: Running enqueue() on queue, non-existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eleventh test: Evaluate populated state -- second try
    //
	ntmp                             = NULL;
	mknode(&ntmp,  24);
    result                           = enqueue(&qtmp, ntmp);
    fprintf(stdout, "Test %d: Running enqueue() on populated queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Twelfth test: Check queue -- second try
    //
    fprintf(stdout,     "Test %d: Checking queue (1/2) ...\n", testno++);
    if (qtmp -> back                 == NULL)
        fprintf(stdout, " you have: NULL node (ERROR)\n");
    else
        fprintf(stdout, " you have: non-NULL node (SUCCESS)\n");
    fprintf(stdout,     "should be: non-NULL node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Thirteenth test: Check queue 2 -- second try
    //
    fprintf(stdout, "Test %d: Checking queue (2/2) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   qtmp -> back -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", 24); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourteenth test: Instigate queue overflow
    //
	ntmp                             = NULL;
	mknode(&ntmp,  36);
    result                           = enqueue(&qtmp, ntmp);
    fprintf(stdout, "Test %d: Running enqueue() on populated queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_OVERRUN); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Hack queue size to infinite
    //
	qtmp -> buffer                   = 0;

    //////////////////////////////////////////////////////////////////
    //
    // Fifteenth test: Evaluate populated state (many nodes)
    //
    result                           = enqueue(&qtmp, ntmp);
    fprintf(stdout, "Test %d: Running enqueue() on populated queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixteenth test: Check queue
    //
    fprintf(stdout,     "Test %d: Checking queue (1/2) ...\n", testno++);
    if (qtmp -> front                 == NULL)
        fprintf(stdout, " you have: NULL node (ERROR)\n");
    else
        fprintf(stdout, " you have: non-NULL node (SUCCESS)\n");
    fprintf(stdout,     "should be: non-NULL node (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventeenth test: Check queue 2
    //
    fprintf(stdout, "Test %d: Checking queue (2/2) ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   qtmp -> front -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", 12); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighteenth test: Evaluate queue (non-existent node)
    //
    result                           = enqueue(&qtmp, NULL);
    fprintf(stdout, "Test %d: Running enqueue() on queue, non-existent node ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLN_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    fprintf(stdout, "===========================================\n\n");

    return(0);
}
