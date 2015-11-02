#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *myList          = NULL;
	Node   *tmp             = NULL;
	int     i               = 0;
	int     data[]          = { 0, 1, 2, 4, 8, 16, 32, 64, 2, 2, 4, 37 };
	int     testno          = 0;
	code_t  result          = 0;

	fprintf(stdout, "UNIT TEST: list library find() function\n");
	fprintf(stdout, "=======================================\n");

	fprintf(stdout, "\nTest %d: Finding on NULL list ...\n", testno++);
	result                = find(myList, 17, &tmp);
	fprintf(stdout, " you have: ");
	if (tmp              == NULL)
		fprintf(stdout, "NULL\n");
	else
		fprintf(stdout, "(error)\n");

	fprintf(stdout, "should be: NULL\n");
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_NULL | DLL_ERROR);
	fflush (stdout);

	mklist(&myList);

	fprintf(stdout, "\nTest %d: Finding on EMPTY list ...\n", testno++);
	fprintf(stdout, " you have: ");
	result       = find(myList, 37, &tmp);
	if (tmp    == NULL)
		fprintf(stdout, "NULL\n");
	else
		fprintf(stdout, "(error)\n");

	fprintf(stdout, "should be: NULL\n");
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_EMPTY | DLL_ERROR);
	fflush (stdout);

	for (i = 0; i < 12; i++)
	{
		tmp       = NULL;
		mknode(&tmp, data[i]);
		catnode(&myList, myList -> last, tmp);
	}

	fprintf(stdout, "\nTest %d: Finding value that is in first node ...\n", testno++);
	fprintf(stdout, " you have: ");
	tmp           = NULL;
	result        = find(myList, data[0], &tmp);
	if (tmp      == NULL)
		fprintf(stdout, "NULL\n");
	else if (tmp != NULL)
		fprintf(stdout, "%hhd\n", tmp -> VALUE);

	fprintf(stdout, "should be: %hhd\n", data[0]);
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	if (tmp      != NULL)
		lscodes(DLN_SUCCESS);
	else
		lscodes(DLN_NULL);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Finding value that is in second node ...\n", testno++);
	fprintf(stdout, " you have: ");
	tmp         = NULL;
	result      = find(myList, data[1], &tmp);
	if (tmp    == NULL)
		fprintf(stdout, "NULL\n");
	else if (tmp != NULL)
		fprintf(stdout, "%hhd\n", tmp -> VALUE);

	fprintf(stdout, "should be: %hhd\n", data[1]);
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	if (tmp      != NULL)
		lscodes(DLN_SUCCESS);
	else
		lscodes(DLN_NULL);
	fflush (stdout);

	for (i = 5; i >= 2; i--)
	{
		fprintf(stdout, "\nTest %d: Looking for %hhd in list ...\n", testno++, data[i]);
		fprintf(stdout, " you have: ");
		tmp         = NULL;
		result      = find(myList, data[i], &tmp);
		if (tmp    == NULL)
			fprintf(stdout, "NULL\n");
		else if (tmp != NULL)
			fprintf(stdout, "%hhd\n", tmp -> VALUE);

		fprintf(stdout, "should be: %hhd\n", data[i]);
		fflush(stdout);

		fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
		fprintf(stdout, " you have: ");
		lscodes(result);
		fprintf(stdout, "should be: ");
		if (tmp      != NULL)
			lscodes(DLN_SUCCESS);
		else
			lscodes(DLN_NULL);
		fflush (stdout);
	}

	fprintf(stdout, "\nTest %d: Finding 2nd of 3 '2's ...\n", testno++);
	fprintf(stdout, " you have: ");
	tmp         = NULL;
	find(myList, 2, &tmp);
	result      = find(myList, 2, &tmp);
	if (tmp    == NULL)
		fprintf(stdout, "NULL\n");
	else if (tmp != NULL)
		fprintf(stdout, "%hhd\n", tmp -> VALUE);

	fprintf(stdout, "should be: %hhd\n", 2);
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	if (tmp      != NULL)
		lscodes(DLN_SUCCESS);
	else
		lscodes(DLN_NULL);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Finding 3rd of 3 '2's ...\n", testno++);
	fprintf(stdout, " you have: ");
	result      = find(myList, 2, &tmp);
	if (tmp    == NULL)
		fprintf(stdout, "NULL\n");
	else if (tmp != NULL)
		fprintf(stdout, "%hhd\n", tmp -> VALUE);

	fprintf(stdout, "should be: %hhd\n", 2);
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	if (tmp      != NULL)
		lscodes(DLN_SUCCESS);
	else
		lscodes(DLN_NULL);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking for non-existent remaining '2' ...\n", testno++);
	fprintf(stdout, " you have: ");
	result      = find(myList, 2, &tmp);
	if (tmp    == NULL)
		fprintf(stdout, "NULL\n");
	else if (tmp != NULL)
		fprintf(stdout, "%hhd\n", tmp -> VALUE);

	fprintf(stdout, "should be: NULL\n");
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	if (tmp      != NULL)
		lscodes(DLN_SUCCESS);
	else
		lscodes(DLN_NULL);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Finding value that is in second to last ...\n", testno++);
	fprintf(stdout, " you have: ");
	tmp         = NULL;
	result      = find(myList, data[6], &tmp);
	if (tmp    == NULL)
		fprintf(stdout, "NULL\n");
	else if (tmp != NULL)
		fprintf(stdout, "%hhd\n", tmp -> VALUE);

	fprintf(stdout, "should be: %hhd\n", data[6]);
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	if (tmp      != NULL)
		lscodes(DLN_SUCCESS);
	else
		lscodes(DLN_NULL);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Finding value that is in last node ...\n", testno++);
	fprintf(stdout, " you have: ");
	tmp         = NULL;
	result      = find(myList, data[7], &tmp);
	if (tmp    == NULL)
		fprintf(stdout, "NULL\n");
	else if (tmp != NULL)
		fprintf(stdout, "%hhd\n", tmp -> VALUE);

	fprintf(stdout, "should be: %hhd\n", data[7]);
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	if (tmp      != NULL)
		lscodes(DLN_SUCCESS);
	else
		lscodes(DLN_NULL);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Looking for value (73) not in list ...\n", testno++);
	fprintf(stdout, " you have: ");
	tmp         = NULL;
	result      = find(myList, 73, &tmp);
	if (tmp    == NULL)
		fprintf(stdout, "NULL\n");
	else if (tmp != NULL)
		fprintf(stdout, "%hhd\n", tmp -> VALUE);

	fprintf(stdout, "should be: NULL\n");
	fflush(stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	if (tmp      != NULL)
		lscodes(DLN_SUCCESS);
	else
		lscodes(DLN_NULL);
	fflush (stdout);

	return(0);
}
