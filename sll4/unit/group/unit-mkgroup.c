#include <stdio.h>
#include <stdlib.h>
#include "group.h"

int main()
{
	Group *gtmp   = NULL;
	Group *gtmp2  = NULL;
	int    i      = 0;
	int    testno = 0;

	fprintf(stdout, "UNIT TEST: group library mkgroup() function\n");
	fprintf(stdout, "===========================================\n");

	fprintf(stdout, "Test %d: Creating new group ...\n", testno++);
	gtmp = gtmp2 = mkgroup();
	if ((gtmp   == NULL) && (gtmp2 == NULL))
		fprintf(stdout, " you have: NULL\n");
	else if ((gtmp -> first == NULL) && (gtmp -> last == NULL))
		fprintf(stdout, " you have: *NOT* NULL (success)\n");
	else
		fprintf(stdout, " you have: NULL\n");

	fprintf(stdout, "should be: *NOT* NULL (success)\n\n"); 
	fflush(stdout);

	for (i = 0; i < 4; i++)
	{
		fprintf(stdout, "Test %d: Creating another new group ...\n", testno++);
		gtmp2          = mkgroup();
		if ((gtmp     == gtmp2) && (gtmp == NULL))
			fprintf(stdout, " you have: NULL\n");
		else if (gtmp == gtmp2)
			fprintf(stdout, " you have: gtmp and gtmp2 still the same\n");
		else
			fprintf(stdout, " you have: gtmp and gtmp2 *NOT* the same (success)\n");

		fprintf(stdout, "should be: gtmp and gtmp2 *NOT* the same (success)\n\n"); 
		fflush(stdout);

		if ((i % 2)   == 0)
			gtmp       = gtmp2;
		else
			gtmp       = NULL;
	}

	return(0);
}
