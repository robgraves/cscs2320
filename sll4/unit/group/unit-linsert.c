#include <stdio.h>
#include <stdlib.h>
#include "group.h"

int main()
{
	Group *gtmp    = NULL;
	List  *ltmp    = NULL;
	List  *ltmp2   = NULL;
	Node  *ntmp    = NULL;

	int    i       = 0;
	int    j       = 0;
	int    k       = 1;
	long int result = 0;
	int    data[]  = { 0, 1, 2, 4, 8, 16, 32, 48, 64 };
	int    order[] = { 2, 3, 0, 1, 4, 0, 6, 1 };
	int    num     = 0;
	int    testno  = 0;

	char  *output[15];
	output[i++]    = "<0>: 0 -> 2 -> 1 -> NULL";
	output[i++]    = "<1>: -> NULL";
	output[i++]    = "<2>: 0 -> NULL";
	output[i++]    = "<3>: 0 -> 4 -> 2 -> 1 -> NULL";
	output[i++]    = "<4>: 0 -> 1 -> NULL";

	output[i++]    = "<0>: 0 -> 1 -> 2 -> 4 -> NULL";
	output[i++]    = "<1>: 1 -> 2 -> 4 -> 8 -> NULL";
	output[i++]    = "<2>: 2 -> 4 -> 8 -> 16 -> NULL";
	output[i++]    = "<4>: 8 -> 16 -> 32 -> 48 -> NULL";
	output[i++]    = "<7>: 48 -> 64 -> 0 -> 1 -> NULL";
	output[i++]    = "<9>: 1 -> 8 -> 4 -> 2 -> NULL";
	output[i++]    = "<7>: 2 -> 16 -> 8 -> 4 -> NULL";
	output[i++]    = "<5>: 4 -> 32 -> 16 -> 8 -> NULL";
	output[i++]    = "<3>: 16 -> 64 -> 48 -> 32 -> NULL";
	output[i++]    = "<1>: 64 -> 2 -> 1 -> 0 -> NULL";

	fprintf(stdout, "UNIT TEST: group library linsert() function\n");
	fprintf(stdout, "===========================================\n");

	// NULL group test
	fprintf(stdout,     "Test %d: Inserting NULL list to NULL group ...\n", testno++);
	gtmp                    = linsert(gtmp, NULL, NULL);
	if (gtmp               == NULL)
		fprintf(stdout, " you have: NULL\n"); 
	else
		fprintf(stdout, " you have: NOT NULL\n"); 
	fprintf(stdout,     "should be: NULL\n\n"); 
	fflush (stdout);

	fprintf(stdout,     "Test %d: Inserting EMPTY list to NULL group ...\n", testno++);
	ltmp                    = mklist();
	gtmp                    = linsert(gtmp, NULL, ltmp);
	if (gtmp               == NULL)
		fprintf(stdout, " you have: NULL\n"); 
	else
		fprintf(stdout, " you have: NOT NULL\n"); 
	fprintf(stdout,     "should be: NULL\n\n"); 
	fflush (stdout);

	gtmp                    = mkgroup();

	// EMPTY list test
	fprintf(stdout, "Test %d: Inserting NULL list to EMPTY group ...\n", testno++);
	gtmp                    = linsert(gtmp, gtmp -> last, NULL);
	if (gtmp               == NULL)
		fprintf(stdout, " you have: NULL group\n"); 
	else if (gtmp -> first == NULL)
		fprintf(stdout, " you have: EMPTY group\n"); 
	else
		fprintf(stdout, " you have: NON-EMPTY group\n"); 
	fprintf(stdout, "should be: EMPTY group\n\n"); 
	fflush (stdout);

	fprintf(stdout, "Test %d: Inserting EMPTY list to EMPTY group ...\n", testno++);
	gtmp                    = linsert(gtmp, gtmp -> last, ltmp);
	if (gtmp               == NULL)
		fprintf(stdout, " you have: NULL group\n"); 
	else if (gtmp -> first == NULL)
		fprintf(stdout, " you have: EMPTY group\n"); 
	else if (gtmp -> first == ltmp)
		fprintf(stdout, " you have: SUCCESS\n"); 
	else
		fprintf(stdout, " you have: something else\n"); 
	fprintf(stdout, "should be: SUCCESS\n\n"); 
	fflush (stdout);

	fprintf(stdout, "Test %d: Checking group attributes ...\n", testno++);
	if (gtmp               == NULL)
		fprintf(stdout, " you have: NULL group\n"); 
	else if (gtmp -> last  == NULL)
		fprintf(stdout, " you have: INVALID group last pointer\n"); 
	else if (gtmp -> last  == ltmp)
		fprintf(stdout, " you have: SUCCESS\n"); 
	else
		fprintf(stdout, " you have: something else\n"); 
	fprintf(stdout, "should be: SUCCESS\n\n"); 
	fflush (stdout);

	gtmp                 = mkgroup();
	
	// Building list group
	for(j = 0; j < 5; j++)
	{
		ltmp             = mklist();

		// Building list proper
		for(i = 0; i < order[j]; i++)
		{
			ntmp         = mknode (data[i]);

			if ((j % 20) == 0)
				ltmp     = append (ltmp, ltmp -> last,  ntmp);
			else
				ltmp     = append (ltmp, ltmp -> first, ntmp);
		}
		gtmp             = linsert(gtmp, gtmp -> last, ltmp);
	}

	fprintf(stdout, "Displaying entire group ...\n");
	ldisplay(gtmp, -1);
	fprintf(stdout, "\n");

	for(j = 0; j < 5; j++)
	{
		fprintf(stdout, "Test %d: Checking list #%d...\n", testno++, j);
		fprintf(stdout, " you have: ");
		ldisplay(gtmp, j);
		fprintf(stdout, "should be: %s\n\n", output[num++]); 
		fflush (stdout);
	}

	for(j = 0; j < 8; j+=k)
	{
		fprintf(stdout, "Test %d: Inserting before position #%d...\n", testno++, j);
		ltmp         = mklist();
		for (i = 0; i < 4; i++)
		{
			ntmp     = mknode (data[(i+j)%9]);
			ltmp     = append (ltmp, ltmp -> last, ntmp);
		}

		ltmp2        = lsetpos(gtmp, j);
		gtmp         = linsert(gtmp, ltmp2, ltmp);

		fprintf(stdout, " you have: ");
		result = ldisplay(gtmp, j);
		fprintf(stdout, "should be: %s\n\n", output[num++]); 
		fflush (stdout);
		fprintf(stdout, "Displaying entire group ...\n");
		ldisplay(gtmp, -1);
		fprintf(stdout, "\n");

		if (j > 1)
			k = k + 1;
	}

	k = 1;
	result = lgetpos(gtmp, gtmp -> last);
	for(j = 0; j < 8; j+=k)
	{
		fprintf(stdout, "Test %d: Inserting before position #%ld...\n", testno++, result);
		ltmp         = mklist();
		for (i = 0; i < 4; i++)
		{
			ntmp     = mknode (data[(i+j+1)%9]);
			ltmp     = append (ltmp, ltmp -> first, ntmp);
		}

		ltmp2        = lsetpos(gtmp, result);
		gtmp         = linsert(gtmp, ltmp2, ltmp);

		fprintf(stdout, " you have: ");
		ldisplay(gtmp, result);
		fprintf(stdout, "should be: %s\n\n", output[num++]); 
		fflush (stdout);
		fprintf(stdout, "Displaying entire group ...\n");
		ldisplay(gtmp, -1);
		fprintf(stdout, "\n");

		if (j > 1)
			k = k + 1;

		result = result - 2;
	}

	return(0);
}
