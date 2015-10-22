#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	List *ltmp   = NULL;
	Node *ntmp   = NULL;
	int   i      = 0;
	int   data[] = { 0, 1, 2, 4, 8, 16, 32, 48, 64 };
	int   num    = 0;
	int   testno = 0;

	char *output[11];
	output[i++]  = "-> NULL";
	output[i++]  = "-> NULL";
	output[i++]  = "0 -> NULL";
	output[i++]  = "1 -> 0 -> NULL";
	output[i++]  = "2 -> 1 -> 0 -> NULL";
	output[i++]  = "4 -> 2 -> 1 -> 0 -> NULL";
	output[i++]  = "4 -> 2 -> 1 -> 8 -> 0 -> NULL";
	output[i++]  = "4 -> 2 -> 1 -> 16 -> 8 -> 0 -> NULL";
	output[i++]  = "4 -> 2 -> 1 -> 32 -> 16 -> 8 -> 0 -> NULL";
	output[i++]  = "4 -> 2 -> 48 -> 1 -> 32 -> 16 -> 8 -> 0 -> NULL";
	output[i++]  = "4 -> 64 -> 2 -> 48 -> 1 -> 32 -> 16 -> 8 -> 0 -> NULL";

	fprintf(stdout, "UNIT TEST: list library insert() function\n");
	fprintf(stdout, "=========================================\n");

	// NULL list test
	fprintf(stdout, "Test %d: Inserting on NULL list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	ltmp         = insert(ltmp, NULL, NULL);
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);

	ltmp         = mklist();

	// EMPTY list test
	fprintf(stdout, "Test %d: Inserting on empty list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	ltmp         = insert(ltmp, NULL, NULL);
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	
	fprintf(stdout, "Test %d: Checking list quantity ...\n", testno++);
	fprintf(stdout, " you have: %lu\n", ltmp -> qty); 
	fprintf(stdout, "should be: %d\n\n", 0); 
	fflush (stdout);

	// Building list
	for(i = 0; i < 4; i++)
	{
		fprintf(stdout, "Test %d: Inserting %d before start of list ...\n", testno++, data[i]);
		ntmp     = mknode(data[i]);
		fprintf(stdout, " you have: "); 
		ltmp     = insert(ltmp, ltmp -> first, ntmp);
		displayf(ltmp, 0);
		fprintf(stdout, "should be: %s\n\n", output[num++]); 
		fflush(stdout);
	
		fprintf(stdout, "Test %d: Checking list quantity ...\n", testno++);
		fprintf(stdout, " you have: %lu\n", ltmp -> qty); 
		fprintf(stdout, "should be: %d\n\n", (i+1)); 
		fflush (stdout);
	}

	i = 4;

	fprintf(stdout, "Test %d: Inserting %d before end of list ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp         = insert(ltmp, ltmp -> last, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;
	
	fprintf(stdout, "Test %d: Checking list quantity ...\n", testno++);
	fprintf(stdout, " you have: %lu\n", ltmp -> qty); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush (stdout);

	fprintf(stdout, "Test %d: Inserting %d before second to last node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ntmp         = setpos(ltmp, getpos(ltmp, ltmp -> last) - 1);
	ltmp         = insert(ltmp, ntmp, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;
	
	fprintf(stdout, "Test %d: Checking list quantity ...\n", testno++);
	fprintf(stdout, " you have: %lu\n", ltmp -> qty); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush (stdout);

	fprintf(stdout, "Test %d: Inserting %d before third to last node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ntmp         = setpos(ltmp, getpos(ltmp, ltmp -> last) - 2);
	ltmp         = insert(ltmp, ntmp, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;
	
	fprintf(stdout, "Test %d: Checking list quantity ...\n", testno++);
	fprintf(stdout, " you have: %lu\n", ltmp -> qty); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush (stdout);

	fprintf(stdout, "Test %d: Inserting %d before fifth to last node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ntmp         = setpos(ltmp, getpos(ltmp, ltmp -> last) - 4);
	ltmp         = insert(ltmp, ntmp, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;
	
	fprintf(stdout, "Test %d: Checking list quantity ...\n", testno++);
	fprintf(stdout, " you have: %lu\n", ltmp -> qty); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush (stdout);

	fprintf(stdout, "Test %d: Inserting %d before 2nd node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp         = insert(ltmp, ltmp -> first -> after, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;
	
	fprintf(stdout, "Test %d: Checking list quantity ...\n", testno++);
	fprintf(stdout, " you have: %lu\n", ltmp -> qty); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush (stdout);

	return(0);
}
