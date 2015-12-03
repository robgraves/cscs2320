#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "support.h"

int main()
{
	Tree  *myTree                     = NULL;
	Node  *tmp                        = NULL;
	char   data[]                     = { 11, 9, 13, 11, 7, 6, 4, 2, 8, 33 };
    int    testno                     = 0;
	int    i                          = 0;
	code_t result                     = 0;

    fprintf(stdout,         "UNIT TEST: tree library searchtree() function\n");
    fprintf(stdout,         "=============================================\n");

    fprintf(stdout,         "Test %d: Searching for %hhd in NULL tree ...\n", testno++, data[i]);
    result                            = searchtree(myTree, &tmp, data[i]);
    if (tmp                          == NULL)
        fprintf(stdout,     " you have: NULL\n");
    else
        fprintf(stdout,     " you have: something\n");

    fprintf(stdout,         "should be: NULL\n\n"); 
    fflush (stdout);

	fprintf(stdout,         "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,         " you have: ");
	lscodes(result);
	fprintf(stdout,         "should be: ");
	lscodes(DLT_NULL  | DLT_ERROR);
    fflush (stdout);

    mktree(&myTree, 4);

    fprintf(stdout,         "Test %d: Searching for %hhd in empty tree ...\n", testno++, data[i+1]);
    result                            = searchtree(myTree, &tmp, data[i+1]);
    if (tmp                          == NULL)
        fprintf(stdout,     " you have: NULL\n");
    else
        fprintf(stdout,     " you have: something\n");

    fprintf(stdout,         "should be: NULL\n\n"); 
    fflush (stdout);

	fprintf(stdout,         "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,         " you have: ");
	lscodes(result);
	fprintf(stdout,         "should be: ");
	lscodes(DLT_EMPTY | DLT_ERROR);
    fflush (stdout);

	for (i = 0; i < 9; i++)
	{
		tmp                           = NULL;
		mknode(&tmp, data[i]);
		addnode(&myTree, tmp);
	}

	for (i = 0; i < 10; i++)
	{
		fprintf(stdout,     "Test %d: Searching for %hhd in tree ...\n", testno++, data[i]);
		if (i                        == 3)
			tmp                       = myTree -> root;
		else
			tmp                       = NULL;

		result                        = searchtree(myTree, &tmp, data[i]);

		if (tmp                      == NULL)
			fprintf(stdout, " you have: NULL\n");
		else
			fprintf(stdout, " you have: %hhd\n", tmp -> VALUE);

		if ((data[i]                 != 2) &&
			(data[i]                 != 33))
		{
			fprintf(stdout, "should be: %hhd\n\n", data[i]); 
		}
		else
			fprintf(stdout, "should be: NULL\n\n"); 

		fflush (stdout);

		if (i                        == 3)
		{
			fprintf(stdout, "Test %d: Checking duplicate functionality (2nd 11) ...\n", testno++);
			fprintf(stdout, " you have: %p\n", tmp);
			fprintf(stdout, "should be: %p\n\n", myTree -> root -> prior -> after);
			fflush (stdout);
		}

		fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
		fprintf(stdout,     " you have: ");
		lscodes(result);

		fprintf(stdout,     "should be: ");
		if ((data[i]                  == 2) ||
			(data[i]                  == 33))
		{
			lscodes(DLT_EMPTY);
		}
		else
			lscodes(DLT_SUCCESS);
		fflush (stdout);
	}

    return(0);
}
