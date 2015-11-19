#include <stdio.h>
#include "queue.h"
#include "support.h"

//////////////////////////////////////////////////////////////////////
//
// unit-dequeue.c  - unit test to evaluate queue dequeue
//                   functionality.
//
//    prerequisites: to successfully run this unit test, both the
//                   mkqueue() and dequeue() functions must be
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
    Queue  *qtmp                     = NULL;
    List   *ltmp                     = NULL;
    Node   *ntmp                     = NULL;
    int     testno                   = 0;
    int     i                        = 0;
    code_t  result                   = 0;
    ulli    queue_size               = 3;

    //////////////////////////////////////////////////////////////////
    //
    // Display unit test header
    //
    fprintf(stdout, "=======================================\n");
    fprintf(stdout, "UNIT TEST: queue library dequeue() function\n");
    fprintf(stdout, "=======================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // First test: Evaluate NULL pointer
    //
    result                           = dequeue(NULL, NULL);
    fprintf(stdout, "Test %d: Running dequeue() on NULL pointers ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Second test: Evaluate NULL queue, non-existent dequeueNode
    //
    result                           = dequeue(&qtmp, NULL);
    fprintf(stdout, "Test %d: Running dequeue() on NULL queue, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_NULL); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Third test: Evaluate NULL queue, existent dequeueNode
    //
	ntmp                             = NULL;
    result                           = dequeue(NULL, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on non-existent queue, existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourth test: Evaluate NULL queue, NULL destination
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on NULL queue, NULL destination ...\n", testno++);
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
    mkqueue(&qtmp, 0);
    result                           = dequeue(&qtmp, NULL);
    fprintf(stdout, "Test %d: Running dequeue() on EMPTY queue, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLN_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixth test: Evaluate EMPTY queue (existent destination)
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on EMPTY queue, existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_UNDERRUN); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the queue (one node)
    //
    ltmp                             = qtmp -> data;
    for (i = 0; i < 1; i++)
    {
		ntmp                         = NULL;
        mknode(&ntmp,  i);
        catnode(&ltmp, ltmp -> last, ntmp);
    }
    qtmp -> data                     = ltmp;
    qtmp -> front                    = ltmp -> first;
    qtmp -> back                     = ltmp -> last;

    //////////////////////////////////////////////////////////////////
    //
    // Seventh test: Evaluate populated queue (non-existent destination)
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, NULL);
    fprintf(stdout, "Test %d: Running dequeue() on queue, non-existent destination ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLN_INVALID); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighth test: Evaluate populated state (1 node)
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on populated queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLQ_EMPTY | DLL_EMPTY | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Ninth test: Check dequeued node
    //
    fprintf(stdout, "Test %d: Checking node ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", 0); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Tenth test: Check front (should be NULL)
    //
    fprintf(stdout, "Test %d: Checking front ...\n", testno++);
	if (qtmp -> front               == NULL)
		fprintf(stdout, " you have: queue is empty (SUCCESS)\n");
	else
		fprintf(stdout, " you have: queue is NOT empty (ERROR)\n");
    fprintf(stdout, "should be: queue is empty (SUCCESS)\n\n"); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eleventh test: Evaluate populated state (EMPTY)
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on emptied queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_UNDERRUN); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Populate the queue (many nodes)
    //
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
	i                                = 0;

    //////////////////////////////////////////////////////////////////
    //
    // Twelfth test: Evaluate populated state (many nodes)
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on populated queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Thirteenth test: Check node
    //
    fprintf(stdout, "Test %d: Checking dequeued node ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", i++); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fourteenth test: Evaluate populated state (many nodes)
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on populated queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Fifteenth test: Check node
    //
    fprintf(stdout, "Test %d: Checking dequeued node ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", i++); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Sixteenth test: Evaluate populated state (last node in queue)
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on populated queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_SUCCESS | DLQ_EMPTY | DLL_EMPTY | DLL_SUCCESS); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Seventeenth test: Check node
    //
    fprintf(stdout, "Test %d: Checking dequeued node ...\n", testno++);
    fprintf(stdout, " you have: %hhd\n",   ntmp -> VALUE);
    fprintf(stdout, "should be: %hhd\n\n", i--); 
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Eighteenth test: Evaluate populated state (EMPTY queue)
    //
	ntmp                             = NULL;
    result                           = dequeue(&qtmp, &ntmp);
    fprintf(stdout, "Test %d: Running dequeue() on populated queue ...\n", testno++);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(DLQ_ERROR | DLQ_UNDERRUN); 
	fprintf(stdout, "\n");
    fflush (stdout);

    //////////////////////////////////////////////////////////////////
    //
    // Nineteenth test: Check node
    //
    fprintf(stdout, "Test %d: Checking dequeued node ...\n", testno++);
	if (ntmp                        == NULL)
		fprintf(stdout, " you have: NULL (SUCCESS)\n");
	else
		fprintf(stdout, " you have: node is NOT NULL (ERROR)\n");
    fprintf(stdout, "should be: NULL (SUCCESS)\n\n"); 
    fflush (stdout);

    fprintf(stdout, "=======================================\n\n");

    return(0);
}
