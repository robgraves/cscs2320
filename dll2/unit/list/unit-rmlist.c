#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	List   *ltmp              = NULL;
	Node   *ntmp              = NULL;
	int     i                 = 0;
	int     data[]            = { 2, 4, 8, 16, 32, 64 };
	int     testno            = 0;
	code_t  result            = 0;

	//////////////////////////////////////////////////////////////////
	//
	// Display unit test banner
	//
	fprintf(stdout, "UNIT TEST: list library rmlist() function\n");
	fprintf(stdout, "=========================================\n");

	//////////////////////////////////////////////////////////////////
	//
	// First test: NULL pointer (nonexistent list)
	//
	fprintf(stdout, "Test %d: Checking NULL case ...\n", testno++);
	result                    = rmlist(NULL);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_INVALID | DLL_ERROR);
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Second test: NULL list
	//
	fprintf(stdout, "\nTest %d: Running rmlist() on NULL list ...\n", testno++);
	result                    = rmlist(&ltmp);
	if (ltmp                == NULL)
		fprintf(stdout, " you have: NULL list\n");
	else
		fprintf(stdout, " you have: non-NULL list (problem)\n");
	fprintf(stdout, "should be: NULL list\n");
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Third test: verify status code(s)
	//
	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_NULL | DLL_ERROR);
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Create a list
	//
    mklist(&ltmp);

	//////////////////////////////////////////////////////////////////
	//
	// Fourth test: verify result
	//
	fprintf(stdout, "\nTest %d: Running rmlist() on EMPTY list ...\n", testno++);
	result                    = rmlist(&ltmp);
	if (ltmp                == NULL)
		fprintf(stdout, " you have: NULL list\n");
	else if ((ltmp -> first == NULL) &&
		     (ltmp -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY list (problem)\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY list (problem)\n");
	fprintf(stdout, "should be: NULL list\n");
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Fifth test: verify status code(s)
	//
	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_NULL | DLL_SUCCESS);
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Create a new list (EMPTY)
	//
	mklist(&ltmp);

	//////////////////////////////////////////////////////////////////
	//
	// Populate said list
	//
	for (i = 0; i < 6; i++)
	{
		ntmp                 = NULL;
		mknode (&ntmp, data[i]);
		catnode(&ltmp, ltmp -> last, ntmp);
	}

	//////////////////////////////////////////////////////////////////
	//
	// Display the built list
	//
	fprintf(stdout, "\nPopulated list:\n");
	listcat(ltmp);

	//////////////////////////////////////////////////////////////////
	//
	// Sixth test: verify result
	//
	fprintf(stdout, "\nTest %d: Running rmlist() on populated list ...\n", testno++);
	result                    = rmlist(&ltmp);
	if (ltmp                == NULL)
		fprintf(stdout, " you have: NULL list\n");
	else if ((ltmp -> first == NULL) &&
		     (ltmp -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY list (problem)\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY list (problem)\n");
	fprintf(stdout, "should be: NULL list\n");
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Seventh test: verify status code(s)
	//
	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_NULL | DLL_SUCCESS);
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Display final state of list
	//
	fprintf(stdout, "\nFinal state of list:\n");
	listcat(ltmp);

	return(0);
}
