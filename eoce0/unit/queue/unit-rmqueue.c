#include <stdio.h>
#include "queue.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-rmqueue.c  - unit test to evaluate queue remove functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkqueue() and rmqueue() functions must be fully
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
    fprintf(stdout, "UNIT TEST: queue library rmqueue() function\n");
    fprintf(stdout, "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = rmqueue(NULL);
    fprintf(stdout, "Test %d: Running rmqueue() on NULL pointer ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_INVALID); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL queue
    //
    result                           = rmqueue(&qtmp);
    fprintf(stdout, "Test %d: Running rmqueue() on NULL queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_NULL); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Actually create a new (EMPTY) queue, and call rmqueue() on it
    //
    mkqueue(&qtmp, queue_size);
    fprintf(stdout, "(Before) contents of queue -> data:\n\t");
    listcat(qtmp -> data);
    fprintf(stdout, "\n");
    result                           = rmqueue(&qtmp);
    fprintf(stdout, "(After)  contents of queue -> data:\n\t");
    if (qtmp                        == NULL)
        listcat(NULL);
    else
        listcat(qtmp -> data);
    fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Verify rmqueue() status code(s)
    //
    fprintf(stdout, "Test %d: Checking rmqueue() status on EMPTY queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLQ_NULL | DLL_NULL | DLL_SUCCESS); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: verify that queue is now NULL
    //
    fprintf(stdout,     "Test %d: Checking queue ...\n", testno++);
    if (qtmp                        == NULL)
        fprintf(stdout, " you have: NULL queue (SUCCESS)\n");
    else if (qtmp -> data           == NULL)
        fprintf(stdout, " you have: Queue still exists (ERROR)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: NULL queue (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Create another queue, and populate it (one node), and then
    // run rmqueue() on it
    //
    qtmp                             = NULL;
    mkqueue(&qtmp, queue_size-queue_size);
    ltmp                             = qtmp -> data;
    for (i = 0; i < 1; i++)
    {
        ntmp                         = NULL;
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    qtmp -> data                     = ltmp;
    qtmp -> front                    = qtmp -> data -> first;
    qtmp -> back                     = qtmp -> data -> last;

    fprintf(stdout, "(Before) contents of queue -> data:\n\t");
    listcat(qtmp -> data);
    fprintf(stdout, "\n");
    result                           = rmqueue(&qtmp);
    fprintf(stdout, "(After)  contents of queue -> data:\n\t");
    if (qtmp                        == NULL)
        listcat(NULL);
    else
        listcat(qtmp -> data);
    fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Fifth test: Verify rmqueue() status code(s)
    //
    fprintf(stdout, "Test %d: Checking rmqueue() status on EMPTY queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLQ_NULL | DLL_NULL | DLL_SUCCESS); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Verify that queue is now NULL
    //
    fprintf(stdout,     "Test %d: Checking queue ...\n", testno++);
    if (qtmp                        == NULL)
        fprintf(stdout, " you have: NULL queue (SUCCESS)\n");
    else if (qtmp -> data           == NULL)
        fprintf(stdout, " you have: Queue still exists (ERROR)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: NULL queue (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Create another queue, and populate it (two nodes), and then
    // run rmqueue() on it
    //
    qtmp                             = NULL;
    mkqueue(&qtmp, queue_size-queue_size);
    ltmp                             = qtmp -> data;
    for (i = 0; i < 2; i++)
    {
        ntmp                         = NULL;
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    qtmp -> data                     = ltmp;
    qtmp -> front                    = qtmp -> data -> first;
    qtmp -> back                     = qtmp -> data -> last;
    fprintf(stdout, "(Before) contents of queue -> data:\n\t");
    listcat(qtmp -> data);
    fprintf(stdout, "\n");
    result                           = rmqueue(&qtmp);
    fprintf(stdout, "(After)  contents of queue -> data:\n\t");
    if (qtmp                        == NULL)
        listcat(NULL);
    else
        listcat(qtmp -> data);
    fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Verify rmqueue() status code(s)
    //
    fprintf(stdout, "Test %d: Checking rmqueue() status on EMPTY queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLQ_NULL | DLL_NULL | DLL_SUCCESS); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Verify that queue is now NULL
    //
    fprintf(stdout,     "Test %d: Checking queue ...\n", testno++);
    if (qtmp                        == NULL)
        fprintf(stdout, " you have: NULL queue (SUCCESS)\n");
    else if (qtmp -> data           == NULL)
        fprintf(stdout, " you have: Queue still exists (ERROR)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: NULL queue (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Create another queue, and populate it (many nodes), and then
    // run rmqueue() on it
    //
    mkqueue(&qtmp, queue_size-queue_size);
    ltmp                             = qtmp -> data;
    for (i = 0; i < queue_size; i++)
    {
        ntmp                         = NULL;
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    qtmp -> data                     = ltmp;
    qtmp -> front                    = qtmp -> data -> first;
    qtmp -> back                     = qtmp -> data -> last;
    fprintf(stdout, "(Before) contents of queue -> data:\n\t");
    listcat(qtmp -> data);
    fprintf(stdout, "\n");
    result                           = rmqueue(&qtmp);
    fprintf(stdout, "(After)  contents of queue -> data:\n\t");
    if (qtmp                        == NULL)
        listcat(NULL);
    else
        listcat(qtmp -> data);
    fprintf(stdout, "\n");

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Verify rmqueue() status code(s)
    //
    fprintf(stdout, "Test %d: Checking rmqueue() status on EMPTY queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLQ_NULL | DLL_NULL | DLL_SUCCESS); 
    fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Verify that queue is now NULL
    //
    fprintf(stdout,     "Test %d: Checking queue ...\n", testno++);
    if (qtmp                        == NULL)
        fprintf(stdout, " you have: NULL queue (SUCCESS)\n");
    else if (qtmp -> data           == NULL)
        fprintf(stdout, " you have: Queue still exists (ERROR)\n");
    else
        fprintf(stdout, " you have: ERROR state\n");

    fprintf(stdout,     "should be: NULL queue (SUCCESS)\n\n"); 
    fflush (stdout);

    fprintf(stdout, "===========================================\n\n");

    return(0);
}
