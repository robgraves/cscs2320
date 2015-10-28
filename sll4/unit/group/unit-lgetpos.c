#include <stdio.h>
#include "group.h"

int main()
{
	Group    *myListGroup             = NULL;
	List     *tmp                     = NULL;
	long int i                        = 0;
	long int j                        = 0;
	long int data[]                   = { 2, 3, 0, 1, 4, 0, 6, 1 };
	long int order[]                  = { 2, 3, 0, 1, 4, 7, 6, 5, -3, 9 };
	long int result                   = 0;
	int      testno                   = 0;

	fprintf (stdout, "UNIT TEST: group library lgetpos() function\n");
	fprintf (stdout, "===========================================\n");

	fprintf (stdout, "Test %d: Processing on NULL group, NULL list ...\n", testno++);
	result                            = lgetpos(myListGroup, tmp);
	fprintf (stdout, " you have: %ld\n", result);
	fprintf (stdout, "should be: -1\n\n");
	fflush  (stdout);

	tmp = mklist();

	fprintf (stdout, "Test %d: Processing on NULL group, EMPTY list ...\n", testno++);
	result                            = lgetpos(myListGroup, tmp);
	fprintf (stdout, " you have: %ld\n",    result);
	fprintf (stdout, "should be: %d\n\n", -1);
	fflush  (stdout);

	myListGroup                       = mkgroup();

	fprintf (stdout, "Test %d: Processing on EMPTY group, NULL list ...\n", testno++);
	result                            = lgetpos(myListGroup, NULL);
	fprintf (stdout, " you have: %ld\n",    result);
	fprintf (stdout, "should be: -1\n\n");
	fflush  (stdout);

	fprintf (stdout, "Test %d: Processing on EMPTY group, EMPTY list ...\n", testno++);
	result                            = lgetpos(myListGroup, tmp);
	fprintf (stdout, " you have: %ld\n",    result);
	fprintf (stdout, "should be: -2\n\n");
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
		tmp                               = myListGroup -> last;
		myListGroup -> last -> after      = NULL;
	}

	for (i = 0; i < 10; i++)
	{
		tmp                               = myListGroup -> first;
		for (j = 0; j < order[i]; j++)
		{
			if (tmp                      != NULL)
				tmp                       = tmp -> after;
		}

		if ((order[i] < 0) || (order[i] > 7))
			tmp                           = mklist();

		fprintf (stdout, "Test %d: Testing lgetpos() [%ld/9] ...\n", testno++, i);
		fprintf (stdout, " you have: %ld\n", lgetpos(myListGroup, tmp));
		if ((order[i] < 0) || (order[i] > 7))
			fprintf (stdout, "should be: %d\n\n", -2);
		else
			fprintf (stdout, "should be: %ld\n\n", order[i]);
		fflush  (stdout);

	}

	return(0);
}
