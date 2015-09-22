#include <stdio.h>
#include "list.h"

#define   SHOWPOS       1
#define   NOPOS         0

int main()
{
	List *myList                     = NULL;
	int   i                          = 0;
	int   data[]                     = { 2, 4, 8, 16, 32, 64 };

	fprintf (stdout, "UNIT TEST: list library displayf() function\n");
	fprintf (stdout, "==========================================\n");

	fprintf (stdout, "Displaying list without position values:\n");
	fprintf (stdout, " you have: ");
	displayf(myList, NOPOS);
	fprintf (stdout, "should be: NULL\n\n");

	myList                           = mklist();

	fprintf (stdout, "Displaying list without position values:\n");
	fprintf (stdout, " you have: ");
	displayf(myList, NOPOS);
	fprintf (stdout, "should be: -> NULL\n\n");

	for (i = 0; i < 6; i++)
	{
		if (myList -> last          == NULL)
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

	fprintf (stdout, "Displaying list without position values:\n");
	fprintf (stdout, " you have: ");
	displayf(myList, NOPOS);
	fprintf (stdout, "should be: 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> NULL\n\n");

	fprintf (stdout, "Displaying list with position values:\n");
	fprintf (stdout, " you have: ");
	displayf(myList, SHOWPOS);
	fprintf (stdout, "should be: [0] 2 -> [1] 4 -> [2] 8 -> [3] 16 -> [4] 32 -> [5] 64 -> NULL\n\n");

	return(0);
}
