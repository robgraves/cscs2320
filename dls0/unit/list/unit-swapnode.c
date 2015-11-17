#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *ltmp              = NULL;
	Node   *tmp, *tmp2;

	int     i                 = 0;
	int     j                 = 0;
	int     k                 = 0;
	int     data[]            = { 2, 4, 8, 16, 32, 48, 64 };
	int     testno            = 0;
	code_t  result            = 0;

	tmp                       = NULL;
	tmp2                      = NULL;
	
	fprintf(stdout, "UNIT TEST: list library swapnode() function\n");
	fprintf(stdout, "=======================================\n");

	fprintf(stdout, "Test %d: Checking NULL case ...\n", testno++);
	result                    = swapnode(NULL,  tmp, tmp2);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_INVALID | DLL_ERROR);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Running swapnode() on NULL list ...\n", testno++);
	result                    = swapnode(&ltmp, tmp, tmp2);
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

	fprintf(stdout, "\nTest %d: Running swapnode() on EMPTY list ...\n", testno++);
	result                    = swapnode(&ltmp, tmp, tmp2);
	if (ltmp                == NULL)
		fprintf(stdout, " you have: NULL list (problem)\n");
	else if ((ltmp -> first == NULL) &&
		     (ltmp -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY list\n");
	}
	else
		fprintf(stdout, " you have: non-NULL list (problem)\n");
	fprintf(stdout, "should be: EMPTY list\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_EMPTY | DLL_ERROR | DLN_NULL);
	fflush (stdout);

	mknode(&tmp,  1);

	fprintf(stdout, "\nTest %d: Checking EMPTY case ...\n", testno++);
	result                    = swapnode(&ltmp, tmp, tmp2);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_EMPTY | DLL_ERROR | DLN_NULL);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking NULL case [2/3] ...\n", testno++);
	result                    = swapnode(NULL,  tmp, tmp2);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_INVALID | DLL_ERROR);
	fflush (stdout);

	mknode(&tmp2, 2);

	fprintf(stdout, "\nTest %d: Checking NULL case [3/3] ...\n", testno++);
	result                    = swapnode(NULL,  tmp, tmp2);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_INVALID | DLL_ERROR);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Running swapnode() on EMPTY list ...\n", testno++);
	result                    = swapnode(&ltmp, tmp, tmp2);
	if (ltmp                 == NULL)
		fprintf(stdout, " you have: NULL list (problem)\n");
	else if ((ltmp -> first  == NULL) &&
		     (ltmp -> last   == NULL))
	{
		fprintf(stdout, " you have: EMPTY list\n");
	}
	else
		fprintf(stdout, " you have: non-NULL list (problem)\n");
	fprintf(stdout, "should be: EMPTY list\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_EMPTY | DLL_ERROR);
	fflush (stdout);

	for (i = 0; i < 7; i++)
	{
		tmp                   = NULL;
		mknode (&tmp,  data[i]);
		catnode(&ltmp, ltmp -> last, tmp);
	}

	fprintf(stdout, "\nCompleted list, before swapping starts::\n");
	fprintf(stdout, "           ");
	listcat(ltmp);

	tmp                       = ltmp -> first;
	tmp2                      = ltmp -> first;
	i                         = 0;
	j                         = 0;

	while (tmp2              != ltmp -> last)
	{
		tmp2                  = tmp2 -> after;
		j                     = j + 1;
	}

	while ((tmp              != NULL) &&
		   (tmp2             != NULL))
	{
		fprintf(stdout, "\nTest %d: Running swapnode(), swapping positions %d and %d ...\n", testno++, i, j);
		result                = swapnode(&ltmp, tmp, tmp2);
		fprintf(stdout, " you have: ");
		listcat(ltmp);
		fprintf(stdout, "should be: ");

		// Master copy swaperoo
		k                     = data[i];
		data[i]               = data[j];
		data[j]               = k;

		// Display master swapped copy
		for (k = 0; k < 7; k++)
			fprintf(stdout, "%d -> ", data[k]);
		fprintf(stdout, "NULL\n");
		fflush (stdout);

		fprintf(stdout, "\nTest %d: Verifying list integrity (reversal) ...\n", testno++);
		fprintf(stdout, " you have: ");
		listtac(ltmp);
		fprintf(stdout, "should be: ");

		for (k = 6; k >= 0; k--)
			fprintf(stdout, "%d -> ", data[k]);
		fprintf(stdout, "NULL\n");
		fflush (stdout);

		if ((ltmp -> first  == ltmp -> last) ||
			(tmp             == tmp2))
		{
			fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
			fprintf(stdout, " you have: ");
			lscodes(result);
			fprintf(stdout, "should be: ");
			lscodes(DLL_ERROR);
			fflush (stdout);
		}
		else
		{
			fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
			fprintf(stdout, " you have: ");
			lscodes(result);
			fprintf(stdout, "should be: ");
			lscodes(DLL_SUCCESS);
			fflush (stdout);
		}

		i                     = i + 1;
		j                     = j - 1;

		tmp                   = ltmp -> first;
		tmp2                  = ltmp -> last;
		for (k = 0; k < i; k++)
		{
			if (tmp          != NULL)
				tmp           = tmp  -> after;
			if (tmp2         != NULL)
				tmp2          = tmp2 -> prior;
		}

/*
		tmp2                  = ltmp -> last;
		for (k = i; k > j; k--)
		{
			if (tmp2         != NULL)
				tmp2          = tmp2 -> prior;
		}
		*/
	}

	return(0);
}
