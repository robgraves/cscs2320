#include <stdio.h>
#include <stdlib.h>
#include "group.h"

int main()
{
	Group *group1             = NULL;

	int   i                   = 0;
	int   testno              = 0;
	
	fprintf(stdout, "UNIT TEST: group library rmgroup() function\n");
	fprintf(stdout, "===========================================\n");

	fprintf(stdout, "Test %d: Running rmgroup() on NULL list ...\n", testno++);
	group1                     = rmgroup(group1);
	if (group1                == NULL)
		fprintf(stdout, " you have: NULL group\n");
	else
		fprintf(stdout, " you have: non-NULL group (problem)\n");
	fprintf(stdout, "should be: NULL group\n\n");
	fflush (stdout);

	group1                     = mkgroup();

	fprintf(stdout, "Test %d: Running rmgroup() on EMPTY group ...\n", testno++);
	group1                     = rmgroup(group1);
	if (group1                == NULL)
		fprintf(stdout, " you have: NULL group\n");
	else if ((group1 -> first == NULL) &&
		     (group1 -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY group (problem)\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY group (problem)\n");
	fprintf(stdout, "should be: NULL group\n\n");
	fflush (stdout);

	group1                     = mkgroup();

	for (i = 0; i < 6; i++)
	{
		group1                 = lappend(group1, group1 -> last, mklist());
	}

	fprintf(stdout, "Populated group:\n");
	ldisplay(group1, -1);

	fprintf(stdout, "\nTest %d: Running rmgroup() on populated group ...\n", testno++);
	group1                     = rmgroup(group1);
	if (group1                == NULL)
		fprintf(stdout, " you have: NULL group\n");
	else if ((group1 -> first == NULL) &&
		     (group1 -> last  == NULL))
	{
		fprintf(stdout, " you have: EMPTY group (problem)\n");
	}
	else
		fprintf(stdout, " you have: non-NULL yet non-EMPTY group (problem)\n");
	fprintf(stdout, "should be: NULL group\n\n");
	fflush (stdout);

	fprintf(stdout, "Final state of group:\n");
	ldisplay(group1, -1);

	// Clean up
	//
//	group1 = rmgroup(group1);

	return(0);
}
