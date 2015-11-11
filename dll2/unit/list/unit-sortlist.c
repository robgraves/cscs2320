#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *ltmp          = NULL;
	List   *ltmp2         = NULL;
	Node   *ntmp          = NULL;
	int     i             = 0;
	int     j             = 0;
	int     data[]        = { 64, 0, 48, 1, 32, 2, 16, 4, 8 };
	int     num           = 0;
	int     testno        = 0;
	code_t  result        = 0;

	char *output[14];
	output[i++]           = "64 -> NULL";
	output[i++]           = "64 -> NULL";
	output[i++]           = "64 -> NULL";
	output[i++]           = "0 -> 1 -> 32 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 32 -> 1 -> 0 -> NULL";
	output[i++]           = "32 -> 1 -> 48 -> 0 -> 64 -> NULL";
	output[i++]           = "0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 -> 0 -> NULL";
	output[i++]           = "8 -> 4 -> 16 -> 2 -> 32 -> 1 -> 48 -> 0 -> 64 -> NULL";

	fprintf(stdout, "UNIT TEST: list library sortlist() function\n");
	fprintf(stdout, "===========================================\n");

	fprintf(stdout, "\nTest %d: Checking NULL case ...\n", testno++);
	result                = sortlist(NULL, 0);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_ERROR | DLL_INVALID);
	fflush (stdout);

	// NULL list tests
	for (j = 0; j <= 4; j++)
	{
		fprintf(stdout, "\nTest %d: Sorting on NULL list, mode %d ...\n", testno++, j);
		fprintf(stdout, " you have: "); 
		result            = sortlist(&ltmp, j);
		listcat(ltmp);
		fprintf(stdout, "should be: NULL\n"); 
		fflush (stdout);

		fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
		fprintf(stdout, " you have: ");
		lscodes(result);
		fprintf(stdout, "should be: ");
		lscodes(DLL_ERROR | DLL_NULL);
		fflush (stdout);
	}

	// EMPTY list tests
	for (j = 0; j <= 4; j++)
	{
		mklist(&ltmp);
		fprintf(stdout, "\nTest %d: Sorting on empty list, mode %d ...\n", testno++, j);
		fprintf(stdout, " you have: "); 
		result            = sortlist(&ltmp, j);
		listcat(ltmp);
		fprintf(stdout, "should be: NULL\n"); 
		fflush (stdout);

		fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
		fprintf(stdout, " you have: ");
		lscodes(result);
		fprintf(stdout, "should be: ");
		lscodes(DLL_EMPTY | DLL_ERROR);
		fflush (stdout);
	}

	ltmp                         = NULL;
	mklist(&ltmp);

	// Building list
	for (i = 0; i <= 8; i++)
	{
		ntmp                     = NULL;
		mknode (&ntmp, data[i]);
		catnode(&ltmp, ltmp -> last, ntmp);

// HERE
		if ((i % 4)             == 0)
		{
			for (j = 0; j < 3; j++)
			{
				// Restore pristine list
				//
				ltmp2            = NULL;
				cplist(ltmp, &ltmp2);

				// Display current list for visual comparison
				//
				fprintf(stdout, "\nCurrent list (before sorting):\n           ");
				listcat(ltmp2);

				// Standard sort verification
				//
				fprintf(stdout, "\nTest %d: Sorting %d-node list, mode %d ...\n", testno++,(i+1),j);
				fprintf(stdout, " you have: "); 
				result            = sortlist(&ltmp2, j);
				listcat(ltmp2);
				fprintf(stdout, "should be: %s\n", output[num++]); 
				fflush (stdout);

				// Checking status code
				//
				fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
				fprintf(stdout, " you have: ");
				lscodes(result);
				fprintf(stdout, "should be: ");
				lscodes(DLL_SUCCESS);
				fflush (stdout);

				// Check aspects of underlying list integrity
				//
				fprintf(stdout, "\nTest %d: Checking list integrity ...\n", testno++);
				if (ltmp                == NULL)
					fprintf(stdout, " you have: *NULL* list (error)\n"); 
				else if (ltmp2          == NULL)
					fprintf(stdout, " you have: *NULL* source list (error)\n"); 
				else if (ltmp  -> first == ltmp2 -> first)
					fprintf(stdout, " you have: *SAME* list (error)\n"); 
				else
					fprintf(stdout, " you have: unique lists\n"); 
				fprintf(stdout, "should be: unique lists\n"); 
				fflush (stdout);
			}
		}
	}

	return(0);
}
