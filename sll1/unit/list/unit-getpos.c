#include <stdio.h>
#include "list.h"

int main()
{
	List *myList = NULL;
	Node *tmp    = NULL;
	int   i      = 0;
	int   data[] = { 2, 4, 8, 16, 32, 64 };
	int   testno = 0;

	fprintf(stdout, "UNIT TEST: list library getpos() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "\nTest %d: Running on NULL list ...\n", testno++);
	tmp = NULL;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position -1\n");

	myList       = mklist();

	for (i = 0; i < 6; i++)
	{
		if (myList -> last == NULL)
		{
			myList -> first          = mknode(data[i]);
			myList -> last           = myList -> first;
		}
		else
		{
			myList -> last -> after  = mknode(data[i]);
			myList -> last           = myList -> last -> after;
		}
	}

	fprintf(stdout, "\nDisplaying list, with position values:\n");
	displayf(myList, 1);

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> first -> after ...\n", testno++);
	tmp = myList -> first -> after;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 1\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> last ...\n", testno++);
	tmp = myList -> last;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 5\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> first -> after -> after -> after ...\n", testno++);
	tmp = myList -> first -> after -> after -> after;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 3\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> first -> after -> after ...\n", testno++);
	tmp = myList -> first -> after -> after;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 2\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> first ...\n", testno++);
	tmp = myList -> first;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 0\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to invalid node (not in list) ...\n", testno++);
	tmp = mknode(37);
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position -2\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> first -> after -> after -> after -> after ...\n", testno++);
	tmp = myList -> first -> after -> after -> after -> after;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 4\n");

	return(0);
}
