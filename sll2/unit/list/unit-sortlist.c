#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	List *ltmp   = NULL;
	List *ltmp2  = NULL;
	List *ltmp3  = NULL;
	int   i      = 0;
	int   j      = 0;
	int   data[] = { 64, 0, 48, 1, 32, 2, 16, 4, 8 };
	int   num    = 0;
	int   testno = 0;

	char *output[14];
	output[i++]  = "64 -> NULL";
	output[i++]  = "64 -> NULL";
	output[i++]  = "64 -> NULL";
	output[i++]  = "0 -> 1 -> 32 -> 48 -> 64 -> NULL";
	output[i++]  = "64 -> 48 -> 32 -> 1 -> 0 -> NULL";
	output[i++]  = "32 -> 1 -> 48 -> 0 -> 64 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]  = "64 -> 48 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 -> 0 -> NULL";
	output[i++]  = "8 -> 4 -> 16 -> 2 -> 32 -> 1 -> 48 -> 0 -> 64 -> NULL";

	fprintf(stdout, "UNIT TEST: list library sortlist() function\n");
	fprintf(stdout, "===========================================\n");

	// NULL list tests
	for (j = 0; j < 3; j++)
	{
		fprintf(stdout, "Test %d: Sorting on NULL list, mode %d ...\n", testno++, j);
		fprintf(stdout, " you have: "); 
		ltmp2                    = sortlist(ltmp, j);
		displayf(ltmp2, 0);
		fprintf(stdout, "should be: NULL\n\n"); 
		fflush (stdout);
	}

	ltmp                         = mklist();

	// EMPTY list tests
	for (j = 0; j < 3; j++)
	{
		fprintf(stdout, "Test %d: Sorting on empty list, mode %d ...\n", testno++, j);
		fprintf(stdout, " you have: "); 
		ltmp2                    = sortlist(ltmp, j);
		displayf(ltmp2, 0);
		fprintf(stdout, "should be: -> NULL\n\n"); 
		fflush (stdout);

		fprintf(stdout, "Test %d: Checking list integrity ...\n", testno++);
		if (ltmp2               == NULL)
			fprintf(stdout, " you have: *NULL* list (error)\n"); 
		else if (ltmp           == NULL)
			fprintf(stdout, " you have: *NULL* source list (error)\n"); 
		else if (ltmp2 -> first == NULL)
		{
			if (ltmp   -> first == NULL)
			{
				if (ltmp2 -> first == ltmp -> first)
				{
					if (ltmp2      != ltmp)
						fprintf(stdout, " you have: different empty lists\n"); 
					else
						fprintf(stdout, " you have: *SAME* empty list (error)\n"); 
				}
				else
					fprintf(stdout, " you have: error\n"); 
			}
			else
				fprintf(stdout, " you have: error\n"); 
		}
		else if (ltmp2 -> first == ltmp -> first)
			fprintf(stdout, " you have: *SAME* list (error)\n"); 
		else
			fprintf(stdout, " you have: unique lists (error)\n"); 
		fprintf(stdout, "should be: different empty lists\n\n"); 
		fflush (stdout);
	}

	// Building list
	for (i = 0; i <= 8; i++)
	{
		ltmp  = append(ltmp, ltmp -> last,  mknode(data[i]));

		if ((i % 4)                     == 0)
		{
			for (j = 0; j < 3; j++)
			{
				// Restore pristine list
				//
				ltmp3 = cplist(ltmp);

				// Display current list for visual comparison
				//
				fprintf(stdout, "Current list (before sorting):\n           ");
				displayf(ltmp3, 0);

				// Standard sort verification
				//
				fprintf(stdout, "\nTest %d: Sorting %d-node list, mode %d ...\n", testno++,(i+1),j);
				fprintf(stdout, " you have: "); 
				ltmp2 = sortlist(ltmp3, j);
				displayf(ltmp2, 0);
				fprintf(stdout, "should be: %s\n\n", output[num++]); 
				fflush (stdout);

				// Check aspects of underlying list integrity
				//
				fprintf(stdout, "Test %d: Checking list integrity ...\n", testno++);
				if (ltmp2               == NULL)
					fprintf(stdout, " you have: *NULL* list (error)\n"); 
				else if (ltmp3          == NULL)
					fprintf(stdout, " you have: *NULL* source list (error)\n"); 
				else if (ltmp2 -> first == ltmp3 -> first)
					fprintf(stdout, " you have: *SAME* list (error)\n"); 
				else
					fprintf(stdout, " you have: unique lists\n"); 
				fprintf(stdout, "should be: unique lists\n\n"); 
				fflush (stdout);

				// Avoid memory leak, clean up
				//
				ltmp3 = rmlist(ltmp3);
			}
		}
	}

	// Cleaning up...
	//
	ltmp  = rmlist(ltmp);
	ltmp2 = rmlist(ltmp2);
	ltmp3 = rmlist(ltmp3);

	return(0);
}
