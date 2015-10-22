#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	List *list1               = NULL;

	int   i                   = 0;
	int   data[]              = { 2, 4, 8, 16, 32, 64 };
	int   testno              = 0;
	
	fprintf(stdout, "UNIT TEST: list library rmlist() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "Test %d: Running rmlist() on NULL list ...\n", testno++);
	list1                     = rmlist(list1);
	if (list1                == NULL)
		fprintf(stdout, " you have: NULL list\n");
	else
		fprintf(stdout, " you have: non-NULL list (problem)\n");
	fprintf(stdout, "should be: NULL list\n\n");
	fflush (stdout);

	list1                     = mklist();

	fprintf(stdout, "Test %d: Running rmlist() on EMPTY list ...\n", testno++);
	list1                     = rmlist(list1);
	if (list1                == NULL)
		fprintf(stdout, " you have: NULL list\n");
	else if ((list1 -> first == NULL) &&
		     (list1 -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY list (problem)\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY list (problem)\n");
	fprintf(stdout, "should be: NULL list\n\n");
	fflush (stdout);

	list1                     = mklist();

	for (i = 0; i < 6; i++)
	{
		list1                 = append(list1, list1 -> last, mknode(data[i]));
	}

	fprintf(stdout, "Populated list:\n");
	displayf(list1, 0);

	fprintf(stdout, "\nTest %d: Running rmlist() on populated list ...\n", testno++);
	list1                     = rmlist(list1);
	if (list1                == NULL)
		fprintf(stdout, " you have: NULL list\n");
	else if ((list1 -> first == NULL) &&
		     (list1 -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY list (problem)\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY list (problem)\n");
	fprintf(stdout, "should be: NULL list\n\n");
	fflush (stdout);

	fprintf(stdout, "Final state of list:\n");
	displayf(list1, 0);

	// Clean up
	//
	list1 = rmlist(list1);

	return(0);
}
