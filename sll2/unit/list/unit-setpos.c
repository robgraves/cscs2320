#include <stdio.h>
#include "list.h"

int main()
{
	List *myList = NULL;
	Node *tmp    = NULL;
	int   i      = 0;
	int   data[] = { 2, 4, 8, 16, 32, 64 };
	int   testno = 0;

	fprintf(stdout, "UNIT TEST: list library setpos() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "\nTest %d: Running setpos() on NULL list ...\n", testno++);
	tmp = setpos(myList, -1);
	if (tmp == NULL)
		fprintf(stdout, " you have: node at tmp is NULL\n");
	else
		fprintf(stdout, " you have: node at tmp is *NOT* NULL\n");
	fprintf(stdout, "should be: node at tmp is NULL\n");

	myList       = mklist();

	for (i = 0; i < 6; i++)
	{
		if (myList -> last == NULL)
		{
			myList -> first         = mknode(data[i]);
			myList -> last          = myList -> first;
		}
		else
		{
			myList -> last -> after = mknode(data[i]);
			myList -> last          = myList -> last -> after;
		}
	}

	fprintf(stdout, "\nDisplaying list, with position infos:\n");
	displayf(myList, 1);

	fprintf(stdout, "\nTest %d: Pointing tmp to node at position 3 ...\n", testno++);
	tmp = setpos(myList, 3);
	fprintf(stdout, " you have: node at tmp contains a %d\n", tmp -> info);
	fprintf(stdout, "should be: node at tmp contains a 16\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to node at position 0 ...\n", testno++);
	tmp = setpos(myList, 0);
	fprintf(stdout, " you have: node at tmp contains a %d\n", tmp -> info);
	fprintf(stdout, "should be: node at tmp contains a 2\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to node at position 5 ...\n", testno++);
	tmp = setpos(myList, 5);
	fprintf(stdout, " you have: node at tmp contains a %d\n", tmp -> info);
	fprintf(stdout, "should be: node at tmp contains a 64\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to node at position 1 ...\n", testno++);
	tmp = setpos(myList, 1);
	fprintf(stdout, " you have: node at tmp contains a %d\n", tmp -> info);
	fprintf(stdout, "should be: node at tmp contains a 4\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to node at invalid position ...\n", testno++);
	tmp = setpos(myList, -2);
	if (tmp == NULL)
		fprintf(stdout, " you have: node at tmp is NULL\n");
	else
		fprintf(stdout, " you have: node at tmp is *NOT* NULL\n");
	fprintf(stdout, "should be: node at tmp is NULL\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to node at invalid position ...\n", testno++);
	tmp = setpos(myList, 42);
	if (tmp == NULL)
		fprintf(stdout, " you have: node at tmp is NULL\n");
	else
		fprintf(stdout, " you have: node at tmp is *NOT* NULL\n");
	fprintf(stdout, "should be: node at tmp is NULL\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to node at position 4 ...\n", testno++);
	tmp = setpos(myList, 4);
	fprintf(stdout, " you have: node at tmp contains a %d\n", tmp -> info);
	fprintf(stdout, "should be: node at tmp contains a 32\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to node at position 2 ...\n", testno++);
	tmp = setpos(myList, 2);
	fprintf(stdout, " you have: node at tmp contains a %d\n", tmp -> info);
	fprintf(stdout, "should be: node at tmp contains a 8\n");

	return(0);
}
