#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *ltmp   = NULL;
	List   *ltmp2  = NULL;
	int     i      = 0;
	code_t  result = 0;
	int     testno = 0;

	fprintf(stdout, "UNIT TEST: list library mklist() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "\nTest %d: Creating new list with NULL ...\n", testno++);
	result       = mklist(NULL);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_ERROR       | DLL_INVALID);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Creating new list ...\n", testno++);
	result       = mklist(&ltmp);
	ltmp2        = ltmp;
	if ((ltmp   == NULL) && (ltmp2 == NULL))
		fprintf(stdout, " you have: NULL\n");
	else if ((ltmp -> first == NULL) && (ltmp -> last == NULL))
		fprintf(stdout, " you have: *NOT* NULL (success)\n");
	else
		fprintf(stdout, " you have: NULL\n");

	fprintf(stdout, "should be: *NOT* NULL (success)\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_EMPTY         | DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking list quantity ...\n", testno++);
	fprintf(stdout, " you have: %llu\n", ltmp -> qty); 
	fprintf(stdout, "should be: %d\n", 0); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Running mklist() on existing list ...\n", testno++);
	result = mklist(&ltmp);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_ALREADY_ALLOC | DLL_ERROR);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking list quantity ...\n", testno++);
	fprintf(stdout, " you have: %llu\n", ltmp -> qty); 
	fprintf(stdout, "should be: %d\n", 0); 
	fflush (stdout);

	for (i = 0; i < 4; i++)
	{
		fprintf(stdout, "\nTest %d: Creating another new list ...\n", testno++);
		result         = mklist(&ltmp2);
		if ((ltmp     == ltmp2) && (ltmp == NULL))
			fprintf(stdout, " you have: NULL\n");
		else if (ltmp == ltmp2)
			fprintf(stdout, " you have: ltmp and ltmp2 still the same\n");
		else
			fprintf(stdout, " you have: ltmp and ltmp2 *NOT* the same\n");

		if (i         == 0)
			fprintf(stdout, "should be: ltmp and ltmp2 still the same\n"); 
		else if ((i % 2)   == 0)
			fprintf(stdout, "should be: ltmp and ltmp2 *NOT* the same\n"); 
		else
			fprintf(stdout, "should be: ltmp and ltmp2 still the same\n"); 
		fflush(stdout);

		fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
		fprintf(stdout, " you have: ");
		lscodes(result);

		fprintf(stdout, "should be: ");
		if ((i % 2)   == 0)
		{
			ltmp       = ltmp2;
			if (i == 0)
				lscodes(DLL_ALREADY_ALLOC | DLL_ERROR);
			else
				lscodes(DLL_EMPTY         | DLL_SUCCESS);
		}
		else
		{
			ltmp2      = NULL;
			lscodes(DLL_ALREADY_ALLOC | DLL_ERROR);
		}
		fflush (stdout);

		fprintf(stdout, "\nTest %d: Checking list quantity ...\n", testno++);
		fprintf(stdout, " you have: %llu\n", ltmp -> qty); 
		fprintf(stdout, "should be: %d\n", 0); 
		fflush (stdout);
	}

	return(0);
}
