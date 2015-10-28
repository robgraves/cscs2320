#include <stdio.h>
#include "group.h"

int main()
{
	Group    *myListGroup             = NULL;
	List     *tmp                     = NULL;
	long int i                        = 0;
	long int j                        = 0;
	long int data[]                   = { 2, 3, 0, 1, 4, 0, 6, 1 };
	long int result                   = 0;
	int      testno                   = 0;

	char *output[8];
	output[i++]  = "<0>: 4 -> 6 -> NULL";
	output[i++]  = "<1>: 5 -> 7 -> 1 -> NULL";
	output[i++]  = "<2>: -> NULL";
	output[i++]  = "<3>: 7 -> NULL";
	output[i++]  = "<4>: 8 -> 10 -> 4 -> 6 -> NULL";
	output[i++]  = "<5>: -> NULL";
	output[i++]  = "<6>: 10 -> 12 -> 6 -> 8 -> 14 -> 6 -> NULL";
	output[i++]  = "<7>: 11 -> NULL";

	fprintf (stdout, "UNIT TEST: group library ldisplay() function\n");
	fprintf (stdout, "============================================\n");

	fprintf (stdout, "Test %d: Displaying NULL group ...\n", testno++);
	fprintf (stdout, " you have: ");
	result                            = ldisplay(myListGroup, -1);
	fprintf (stdout, "should be: <NULL>\n\n");
	fflush  (stdout);

	fprintf (stdout, "Test %d: Checking ldisplay() output (NULL group) ...\n", testno++);
	fprintf (stdout, " you have: %ld\n",    result);
	fprintf (stdout, "should be: %d\n\n", -1);
	fflush  (stdout);

	myListGroup                       = mkgroup();

	fprintf (stdout, "Test %d: Displaying EMPTY group ...\n", testno++);
	fprintf (stdout, " you have: ");
	result                            = ldisplay(myListGroup, -1);
	fprintf (stdout, "should be: <EMPTY>\n\n");
	fflush  (stdout);

	fprintf (stdout, "Test %d: Checking ldisplay() output (EMPTY group) ...\n", testno++);
	fprintf (stdout, " you have: %ld\n",    result);
	fprintf (stdout, "should be: %d\n\n", 0);
	fflush  (stdout);

	if (myListGroup -> first         == NULL)
	{
		myListGroup -> first          = mklist();
		myListGroup -> last           = myListGroup -> first;
	}

	tmp                               = myListGroup -> first;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < data[i]; j++)
			tmp                       = append(tmp, tmp -> last, mknode(data[j]*2+i));

		if (i                        != 7)
		{
			myListGroup -> last -> after  = mklist();
			myListGroup -> last           = myListGroup -> last -> after;
		}
		tmp                           = myListGroup -> last;
		myListGroup -> last -> after  = NULL;
	}

	tmp                               = myListGroup -> first;
	for (i = 0; i < 8; i++)
	{
		fprintf (stdout, "Test %d: Displaying group, list %ld of 7 ...\n", testno++, i);
		fprintf (stdout, " you have: ");
		result                        = ldisplay(myListGroup, i);
		fprintf (stdout, "should be: %s\n\n", output[i]);
		fflush  (stdout);

		fprintf (stdout, "Test %d: Checking ldisplay() output, list %ld of 7 ...\n", testno++, i);
		fprintf (stdout, " you have: %ld\n",    result);
		fprintf (stdout, "should be: %d\n\n", 1);
		fflush  (stdout);

		fprintf (stdout, "Test %d: Checking list quantity, list %ld of 7 ...\n", testno++, i);
		fprintf (stdout, " you have: %lu\n",    tmp -> qty);
		fprintf (stdout, "should be: %ld\n\n", data[i]);
		fflush  (stdout);

		tmp                           = tmp -> after;
	}

	fprintf (stdout, "Displaying entire group:\n");
	result                            = ldisplay(myListGroup, -1);

	fprintf (stdout, "\nTest %d: Verifying display of entire group ...\n", testno++);
	fprintf (stdout, " you have: %ld\n", result);
	fprintf (stdout, "should be: 8\n\n");
	fflush  (stdout);

	fprintf (stdout, "Test %d: Checking ldisplay() output on invalid position ...\n", testno++);
	fprintf (stdout, " you have: ");
	result                            = ldisplay(myListGroup, 73);
	fprintf (stdout, "should be: %s\n\n", "<ERROR>");
	fflush  (stdout);

	fprintf (stdout, "Test %d: Checking result of ldisplay() on invalid position ...\n", testno++);
	fprintf (stdout, " you have: %ld\n",    result);
	fprintf (stdout, "should be: %d\n\n", -2);
	fflush  (stdout);

	return(0);
}
