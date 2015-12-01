#include <stdio.h>
#include "queue.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-cpqueue.c  - unit test to evaluate queue copy functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkqueue() and cpqueue() functions must be fully
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
    Queue  *qtmp2                    = NULL;
    List   *ltmp                     = NULL;
    Node   *ntmp                     = NULL;
    int     testno                   = 0;
    int     i                        = 0;
    code_t  result                   = 0;
    ulli    queue_size               = 7;

    //////////////////////////////////////////////////////////////////
    //
    // Display unit test header
    //
    fprintf(stdout, "===========================================\n");
    fprintf(stdout, "UNIT TEST: queue library cpqueue() function\n");
    fprintf(stdout, "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = cpqueue(NULL, NULL);
    fprintf(stdout, "Test %d: Running cpqueue() on NULL pointers ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_INVALID); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL queue, non-existent destination
    //
    result                           = cpqueue(qtmp, NULL);
    fprintf(stdout, "Test %d: Running cpqueue() on NULL queue, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_INVALID); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Evaluate NULL queue, NULL destination
    //
    result                           = cpqueue(qtmp, &qtmp2);
    fprintf(stdout, "Test %d: Running cpqueue() on NULL queue, NULL destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_NULL); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Evaluate NULL queue (empty destination)
    //
    mkqueue(&qtmp2, 0);
    result                           = cpqueue(qtmp, &qtmp2);
    fprintf(stdout, "Test %d: Running cpqueue() on NULL queue, EMPTY destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_CREATE_FAIL); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifth test: Evaluate empty queue (empty destination)
    //
    mkqueue(&qtmp, 0);
    result                           = cpqueue(qtmp, &qtmp2);
    fprintf(stdout, "Test %d: Running cpqueue() on EMPTY queue, EMPTY destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_CREATE_FAIL); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Evaluate empty queue (NULL destination)
    //
    qtmp2                            = NULL;
    result                           = cpqueue(qtmp, &qtmp2);
    fprintf(stdout, "Test %d: Running cpqueue() on EMPTY queue, NULL destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLQ_EMPTY | DLL_SUCCESS | DLL_EMPTY); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Verify cpqueue() operations
    //
    fprintf(stdout,     "Test %d: Checking copied queue ...\n", testno++);
    if (qtmp2                        == NULL)
        fprintf(stdout, " you have: NULL queue (ERROR)\n");
    else if (qtmp2 -> data           == qtmp -> data)
        fprintf(stdout, " you have: same data element (ERROR)\n");
    else if (qtmp2 -> data           != qtmp -> data)
        fprintf(stdout, " you have: different data elements (SUCCESS)\n");
    else
        fprintf(stdout, " you have: some other error state\n");
    fprintf(stdout,     "should be: different data elements (SUCCESS)\n\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the queue and perform a copy
    //
    ltmp                             = qtmp -> data;
    for (i = 0; i < queue_size; i++)
    {
        ntmp                         = NULL;
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    qtmp -> data                     = ltmp;
    qtmp -> back                     = qtmp -> data -> last;
    qtmp -> front                    = qtmp -> data -> first;
    qtmp2                            = NULL;
    result                           = cpqueue(qtmp, &qtmp2);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Verify cpqueue() status code(s)
    //
    fprintf(stdout, "Test %d: Checking cpqueue() status code(s) ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLL_SUCCESS); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Verify that queue has been copied
    //
    fprintf(stdout, "Test %d: Displaying queues ...\n", testno++);
    fprintf(stdout, " you have: ");
    listcat(qtmp  -> data);
    fprintf(stdout, "should be: "); 
    listcat(qtmp2 -> data);
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Verify that queues are indeed different
    //
    i                                = qtmp -> data -> first -> after -> VALUE;
    qtmp -> data -> first -> after -> VALUE  = 29;
    fprintf(stdout,     "Test %d: Checking queues (1 of 2) ...\n", testno++);
    if (qtmp2 -> data -> first -> after -> VALUE == i)
        fprintf(stdout, " you have: difference detected (SUCCESS)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: difference detected (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eleventh test: Verify that queues are indeed different
    //
    fprintf(stdout,     "Test %d: Checking queues (2 of 2) ...\n", testno++);
    if (qtmp -> data -> first -> after -> VALUE == 29)
        fprintf(stdout, " you have: difference detected (SUCCESS)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: difference detected (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Twelfth test: Check front pointer (address)
    //
    fprintf(stdout,     "Test %d: Checking front pointer (1 of 3) ...\n", testno++);
    if (qtmp -> front == qtmp2 -> front)
        fprintf(stdout, " you have: Same pointer destination (ERROR)\n");
    else
        fprintf(stdout, " you have: Different pointer destination (SUCCESS)\n");

    fprintf(stdout,     "should be: Different pointer destination (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Thirteenth test: Check front pointer (contents)
    //
    fprintf(stdout,     "Test %d: Checking front pointer (2 of 3) ...\n", testno++);
    if (qtmp -> front -> VALUE != qtmp2 -> front -> VALUE)
        fprintf(stdout, " you have: Different node contents (ERROR)\n");
    else
        fprintf(stdout, " you have: Same node contents (SUCCESS)\n");

    fprintf(stdout,     "should be: Same node contents (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourteenth test: Check front pointer (list tracking)
    //
    fprintf(stdout,     "Test %d: Checking front pointer (3 of 3) ...\n", testno++);
    if (qtmp2 -> front != qtmp2 -> data -> first)
        fprintf(stdout, " you have: Not tracking list start (ERROR)\n");
    else
        fprintf(stdout, " you have: Tracking start of list (SUCCESS)\n");

    fprintf(stdout,     "should be: Tracking start of list (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifteenth test: Check back pointer (address)
    //
    fprintf(stdout,     "Test %d: Checking back pointer (1 of 3) ...\n", testno++);
    if (qtmp -> back == qtmp2 -> back)
        fprintf(stdout, " you have: Same pointer destination (ERROR)\n");
    else
        fprintf(stdout, " you have: Different pointer destination (SUCCESS)\n");

    fprintf(stdout,     "should be: Different pointer destination (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixteenth test: Check back pointer (contents)
    //
    fprintf(stdout,     "Test %d: Checking back pointer (2 of 3) ...\n", testno++);
    if (qtmp -> back -> VALUE != qtmp2 -> back -> VALUE)
        fprintf(stdout, " you have: Different node contents (ERROR)\n");
    else
        fprintf(stdout, " you have: Same node contents (SUCCESS)\n");

    fprintf(stdout,     "should be: Same node contents (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventeenth test: Check back pointer (list tracking)
    //
    fprintf(stdout,     "Test %d: Checking back pointer (3 of 3) ...\n", testno++);
    if (qtmp2 -> back != qtmp2 -> data -> last)
        fprintf(stdout, " you have: Not tracking list end (ERROR)\n");
    else
        fprintf(stdout, " you have: Tracking end of list (SUCCESS)\n");

    fprintf(stdout,     "should be: Tracking end of list (SUCCESS)\n\n"); 
    fflush (stdout);

    fprintf(stdout, "===========================================\n\n");

    return(0);
}
