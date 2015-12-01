#include <stdio.h>
#include "queue.h"
#include "support.h"

int main()
{
	Queue  *qtmp              = NULL;
	Node   *ntmp              = NULL;
	int     i                 = 0;
	int     data[]            = { 2, 4, 8, 16, 32, 64 };
	int     testno            = 0;
	code_t  result            = 0;
	
	fprintf(stdout, "UNIT TEST: queue library purge() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "Test %d: Checking NULL case ...\n", testno++);
	result                    = purge(NULL);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLQ_INVALID | DLQ_ERROR);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Running purge() on NULL queue ...\n", testno++);
	result                    = purge(&qtmp);
	if (qtmp                 == NULL)
		fprintf(stdout, " you have: NULL queue\n");
	else
		fprintf(stdout, " you have: non-NULL queue (problem)\n");
	fprintf(stdout, "should be: NULL queue\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLQ_NULL | DLQ_ERROR);
	fflush (stdout);

    mkqueue(&qtmp, 0);

	fprintf(stdout, "\nTest %d: Running purge() on EMPTY queue ...\n", testno++);
	result                    = purge(&qtmp);
	if (qtmp                == NULL)
		fprintf(stdout, " you have: NULL queue (problem)\n");
	else if ((qtmp -> front == NULL) &&
		     (qtmp -> back  == NULL))
	{
		fprintf(stdout, " you have: EMPTY queue\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY queue (problem)\n");
	fprintf(stdout, "should be: EMPTY queue\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLQ_EMPTY | DLQ_SUCCESS);
	fflush (stdout);

	for (i = 0; i < 6; i++)
	{
		ntmp                 = NULL;
		mknode (&ntmp, data[i]);
		catnode(&(qtmp -> data), qtmp -> data -> last, ntmp);
	}
	qtmp -> front  = qtmp -> data -> first;
	qtmp -> back   = qtmp -> data -> last;

	fprintf(stdout, "\nPopulated queue:\n");
	listcat(qtmp -> data);

	fprintf(stdout, "\nPopulated queue (reversed):\n");
	listtac(qtmp -> data);

	fprintf(stdout, "\nTest %d: Running purge() on populated queue ...\n", testno++);
	result                    = purge(&qtmp);
	if (qtmp                == NULL)
		fprintf(stdout, " you have: NULL queue (problem)\n");
	else if ((qtmp -> front == NULL) &&
		     (qtmp -> back  == NULL))
	{
		fprintf(stdout, " you have: EMPTY queue\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY queue (problem)\n");
	fprintf(stdout, "should be: EMPTY queue\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLQ_EMPTY | DLQ_SUCCESS | DLL_EMPTY | DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nFinal state of queue:\n");
	listcat(qtmp -> data);

	fprintf(stdout, "\nFinal state of queue (reversed):\n");
	listtac(qtmp -> data);

	return(0);
}
