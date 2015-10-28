#include <stdio.h>
#include <stdlib.h>
#include "group.h"

int main()
{
 	Group *gtmp   = NULL;
	List  *ltmp   = NULL;
	List  *ltmp2  = NULL;
	int    i      = 0;
	int    num    = 0;
	int    testno = 0;

	char *output[14];
	output[i++]   = "<NULL>";
	output[i++]   = "<EMPTY>";
	output[i++]   = "1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 0 -> NULL";
	output[i++]   = "1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 0 -> NULL";
	output[i++]   = "8 -> 9 -> 10 -> 11 -> 12 -> 13 -> 14 -> 15 -> NULL";
	output[i++]   = "1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 0 -> NULL";
	output[i++]   = "8 -> 9 -> 10 -> 11 -> 12 -> 13 -> 14 -> 15 -> NULL";
	output[i++]   = "17 -> 18 -> 19 -> 20 -> 21 -> 22 -> 23 -> 16 -> NULL";
	output[i++]   = "24 -> 25 -> 26 -> 27 -> 28 -> 29 -> 30 -> 31 -> NULL";
	output[i++]   = "33 -> 34 -> 35 -> 36 -> 37 -> 38 -> 39 -> 32 -> NULL";
	output[i++]   = "40 -> 41 -> 42 -> 43 -> 44 -> 45 -> 46 -> 47 -> NULL";
	output[i++]   = "49 -> 50 -> 51 -> 52 -> 53 -> 54 -> 55 -> 48 -> NULL";
	output[i++]   = "NULL";

	fprintf(stdout, "UNIT TEST: group library lobtain() function\n");
	fprintf(stdout, "===========================================\n");

	// NULL list test
	fprintf(stdout, "Test %d: Obtaining on NULL group ...\n", testno++);
	fprintf(stdout, " you have: "); 
	gtmp         = lobtain(gtmp, &ltmp);
	ldisplay(gtmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush (stdout);

	gtmp         = mkgroup();

	// EMPTY list test
	fprintf(stdout, "Test %d: Obtaining on empty group ...\n", testno++);
	fprintf(stdout, " you have: "); 
	gtmp         = lobtain(gtmp, &ltmp);
	ldisplay(gtmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush (stdout);
	
	// Building list
	for (i = 0; i < 64; i++)
	{
		if ((i % 8)  == 0)
		{
			if (i > 0)
			{
				gtmp  = lappend(gtmp, gtmp -> last, ltmp);

				if ((i / 8) == 1)
				{
					fprintf(stdout, "Test %d: Obtaining from one-list group ...\n", testno++);
					fprintf(stdout, " you have: "); 
					ltmp     = gtmp -> first;
					gtmp     = lobtain(gtmp, &ltmp);
					displayf(ltmp, 0);
					fprintf(stdout, "should be: %s\n\n", output[num++]); 
					fflush (stdout);
					gtmp     = lappend(gtmp, gtmp -> last, ltmp);
				}
				else if ((i / 8) == 2)
				{
					fprintf(stdout, "Test %d: Obtaining from two-list group (1/2) ...\n", testno++);
					fprintf(stdout, " you have: "); 
					ltmp     = gtmp -> first;
					gtmp     = lobtain(gtmp, &ltmp);
					displayf(ltmp, 0);
					fprintf(stdout, "should be: %s\n\n", output[num++]); 
					fflush (stdout);

					// Verify list integrity
					fprintf(stdout, "Test %d: Is last now first? ...\n", testno++);
					fprintf(stdout, " you have: %p\n",   gtmp -> last); 
					fprintf(stdout, "should be: %p\n\n", gtmp -> first); 
					fflush (stdout);

					// Put list back into group
					gtmp     = linsert(gtmp, gtmp -> first, ltmp);

					fprintf(stdout, "Test %d: Obtaining from two-list group (2/2) ...\n", testno++);
					fprintf(stdout, " you have: "); 
					ltmp     = gtmp -> last;
					gtmp     = lobtain(gtmp, &ltmp);
					displayf(ltmp, 0);
					fprintf(stdout, "should be: %s\n\n", output[num++]); 
					fflush (stdout);

					// Verify list integrity
					fprintf(stdout, "Test %d: Is first now last? ...\n", testno++);
					fprintf(stdout, " you have: %p\n",   gtmp -> first); 
					fprintf(stdout, "should be: %p\n\n", gtmp -> last); 
					fflush (stdout);

					gtmp     = lappend(gtmp, gtmp -> last, ltmp);
				}
			}
			ltmp      = mklist();
		}

		if ((i % 16) >  7)
			ltmp      = append(ltmp, ltmp -> last,  mknode(i));
		else
			ltmp      = insert(ltmp, ltmp -> last,  mknode(i));
	}

	fprintf(stdout, "Displaying entire list group:\n");
	ldisplay(gtmp, -1);
	fprintf(stdout, "\n"); 

	for (i = 0; i < 8; i++)
	{
		// Tag the list
		ltmp          = lsetpos(gtmp, i);

		// Grab it from the group
		gtmp          = lobtain(gtmp, &ltmp);
		
		// Tag the new list in its place
		ltmp2         = lsetpos(gtmp, i);

		fprintf(stdout, "Displaying entire list group:\n");
		ldisplay(gtmp, -1);
		fprintf(stdout, "\n"); 

		fprintf(stdout, "Test %d: Checking group integrity (pos %d/7) ...\n", testno++, i);
		fprintf(stdout, " you have: "); 
		displayf(ltmp, 0);
		fprintf(stdout, "should be: %s\n\n", output[num++]); 
		fflush (stdout);

		// Return list to group
		gtmp          = linsert(gtmp, ltmp2, ltmp);
	}

	return(0);
}
