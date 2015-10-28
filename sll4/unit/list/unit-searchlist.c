#include <stdio.h>
#include "list.h"

int main()
{
	List *myList     = NULL;
	Node *tmp        = NULL;
	int   i          = 0;
	char  data[]     = { 1, 2, 4, 8, 16, 32, 48, 64 };
	int   testno     = 0;

	fprintf(stdout, "UNIT TEST: list library searchlist() function\n");
	fprintf(stdout, "=============================================\n");

	fprintf(stdout, "\nTest %d: Searching on a NULL list ...\n", testno++);
	tmp              = searchlist(myList, 37);
	if (tmp         == NULL)
		fprintf(stdout, " you have: *NULL* NODE (not found)!\n");
	else
		fprintf(stdout, " you have: %hhd found at position %d\n", tmp -> info, getpos(myList, tmp));
	fprintf(stdout, "should be: *NULL* NODE (not found)!\n");

	myList           = mklist();

	fprintf(stdout, "\nTest %d: Searching on as empty list ...\n", testno++);
	tmp              = searchlist(myList, 37);
	if (tmp         == NULL)
		fprintf(stdout, " you have: *NULL* NODE (not found)!\n");
	else
		fprintf(stdout, " you have: %hhd found at position %d\n", tmp -> info, getpos(myList, tmp));
	fprintf(stdout, "should be: *NULL* NODE (not found)!\n");

	for (i = 7; i >= 0; i--)
	{
		myList   = insert(myList, myList -> first,  mknode(data[i]));
	}

	fprintf(stdout, "\nDisplaying list:\n");
	displayf(myList, 1);

	for (i = 7; i >= 0; i--)
	{
		fprintf(stdout, "\nTest %d: Searching for a %hhd in list ...\n", testno++, (data[i]));
		tmp = searchlist(myList, data[i]);
		if (tmp     == NULL)
			fprintf(stdout, " you have: *NULL* NODE (not found)!\n");
		else
			fprintf(stdout, " you have: %hhd found at position %d\n", tmp->info, getpos(myList,tmp));
		fprintf(stdout, "should be: %hhd found at position %d\n", data[i], i);
	}

	fprintf(stdout, "\nTest %d: Searching for a %hhd in list ...\n", testno++, 37);
	tmp = searchlist(myList, 37);
	if (tmp     == NULL)
		fprintf(stdout, " you have: *NULL* NODE (not found)!\n");
	else
		fprintf(stdout, " you have: %hhd found at position %d\n", tmp -> info, getpos(myList, tmp));
	fprintf(stdout, "should be: *NULL* NODE (not found)!\n");

	return(0);
}
