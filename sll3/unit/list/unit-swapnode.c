#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	List *list1               = NULL;
	Node *tmp, *tmp2;

	int   i                   = 0;
	int   j                   = 0;
	int   k                   = 0;
	int   data[]              = { 2, 4, 8, 16, 32, 48, 64 };
	int   testno              = 0;

	tmp                       = NULL;
	tmp2                      = NULL;
	
	fprintf(stdout, "UNIT TEST: list library swapnode() function\n");
	fprintf(stdout, "===========================================\n");

	fprintf(stdout, "Test %d: Running swapnode() on NULL list ...\n", testno++);
	list1                     = swapnode(list1, tmp, tmp2);
	if (list1                == NULL)
		fprintf(stdout, " you have: NULL list\n");
	else
		fprintf(stdout, " you have: non-NULL list (problem)\n");
	fprintf(stdout, "should be: NULL list\n\n");
	fflush (stdout);

	list1                     = mklist();

	fprintf(stdout, "Test %d: Running swapnode() on EMPTY list ...\n", testno++);
	list1                     = swapnode(list1, tmp, tmp2);
	if (list1                == NULL)
		fprintf(stdout, " you have: NULL list (problem)\n");
	else if ((list1 -> first == NULL) &&
		     (list1 -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY list\n");
	}
	else
		fprintf(stdout, " you have: non-NULL list (problem)\n");
	fprintf(stdout, "should be: EMPTY list\n\n");
	fflush (stdout);

	for (i = 0; i < 7; i++)
	{
		list1                 = append(list1, list1 -> last, mknode(data[i]));
	}

	fprintf(stdout, "Completed list, before swapping starts::\n");
	fprintf(stdout, "           ");
	displayf(list1, 0);
	fprintf(stdout, "\n");

	tmp                       = list1 -> first;
	tmp2                      = list1 -> last;
	i                         = getpos(list1, tmp);
	j                         = getpos(list1, tmp2);
	while ((tmp              != NULL) &&
		   (tmp2             != NULL))
	{
		fprintf(stdout, "Test %d: Running swapnode(), swapping positions %d and %d ...\n", testno++, i, j);
		list1                 = swapnode(list1, tmp, tmp2);
		fprintf(stdout, " you have: ");
		displayf(list1, 0);
		fprintf(stdout, "should be: ");

		// Master copy swaperoo
		k                     = data[i];
		data[i]               = data[j];
		data[j]               = k;

		// Display master swapped copy
		for (k = 0; k < 7; k++)
			fprintf(stdout, "%d -> ", data[k]);
		fprintf(stdout, "NULL\n\n");
		fflush (stdout);

		tmp                   = setpos(list1, ++i);
		tmp2                  = setpos(list1, --j);
	}

	// Cleaning up...
	//
	list1 = rmlist(list1);
	tmp   = rmnode(tmp);
	tmp2  = rmnode(tmp2);

	return(0);
}
