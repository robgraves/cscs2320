#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *ltmp              = NULL;
	Node   *ntmp              = NULL;
	int     i                 = 0;
	int     data[]            = { 2, 4, 8, 16, 32, 64 };
	int     testno            = 0;
	code_t  result            = 0;
	
	fprintf(stdout, "UNIT TEST: list library empty() function\n");
	fprintf(stdout, "========================================\n");

	fprintf(stdout, "Test %d: Checking NULL case ...\n", testno++);
	result                    = empty(NULL);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_INVALID | DLL_ERROR);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Running empty() on NULL list ...\n", testno++);
	result                    = empty(&ltmp);
	if (ltmp                 == NULL)
		fprintf(stdout, " you have: NULL list\n");
	else
		fprintf(stdout, " you have: non-NULL list (problem)\n");
	fprintf(stdout, "should be: NULL list\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_NULL | DLL_ERROR);
	fflush (stdout);

    mklist(&ltmp);

	fprintf(stdout, "\nTest %d: Running empty() on EMPTY list ...\n", testno++);
	result                    = empty(&ltmp);
	if (ltmp                == NULL)
		fprintf(stdout, " you have: NULL list (problem)\n");
	else if ((ltmp -> first == NULL) &&
		     (ltmp -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY list\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY list (problem)\n");
	fprintf(stdout, "should be: EMPTY list\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_EMPTY | DLL_SUCCESS);
	fflush (stdout);

	for (i = 0; i < 6; i++)
	{
		ntmp                 = NULL;
		mknode (&ntmp, data[i]);
		catnode(&ltmp, ltmp -> last, ntmp);
	}

	fprintf(stdout, "\nPopulated list:\n");
	listcat(ltmp);

	fprintf(stdout, "\nPopulated list (reversed):\n");
	listtac(ltmp);

	fprintf(stdout, "\nTest %d: Running empty() on populated list ...\n", testno++);
	result                    = empty(&ltmp);
	if (ltmp                == NULL)
		fprintf(stdout, " you have: NULL list (problem)\n");
	else if ((ltmp -> first == NULL) &&
		     (ltmp -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY list\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY list (problem)\n");
	fprintf(stdout, "should be: EMPTY list\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_EMPTY | DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nFinal state of list:\n");
	listcat(ltmp);

	fprintf(stdout, "\nFinal state of list (reversed):\n");
	listtac(ltmp);

	return(0);
}
