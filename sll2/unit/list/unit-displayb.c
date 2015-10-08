#include <stdio.h>
#include "list.h"

#define   SHOWPOS       1
#define   NOPOS         0

int main()
{
	List *myList                     = NULL;
	int   i                          = 0;
	int   data[]                     = { 2, 4, 8, 16, 32, 64 };

	fprintf (stdout, "UNIT TEST: list library displayb() function\n");
	fprintf (stdout, "==========================================\n");

	fprintf (stdout, "Displaying NULL list without position values:\n");
	fprintf (stdout, " you have: ");
	displayb(myList, NOPOS);
	fprintf (stdout, "should be: NULL\n\n");

	fprintf (stdout, "Displaying NULL list with position values:\n");
	fprintf (stdout, " you have: ");
	displayb(myList, SHOWPOS);
	fprintf (stdout, "should be: NULL\n\n");

	myList                           = mklist();

	fprintf (stdout, "Displaying empty list without position values:\n");
	fprintf (stdout, " you have: ");
	displayb(myList, NOPOS);
	fprintf (stdout, "should be: NULL <-\n\n");

	fprintf (stdout, "Displaying empty list with position values:\n");
	fprintf (stdout, " you have: ");
	displayb(myList, SHOWPOS);
	fprintf (stdout, "should be: NULL <-\n\n");

	for (i = 0; i < 6; i++)
	{
		if (myList -> last          == NULL)
		{
			myList -> first          = mknode(data[i]);
			myList -> last           = myList -> first;

			fprintf (stdout, "Displaying populated list without position values:\n");
			fprintf (stdout, " you have: ");
			displayb(myList, NOPOS);
			fprintf (stdout, "should be: NULL <- 2\n\n");

			fprintf (stdout, "Displaying populated list with position values:\n");
			fprintf (stdout, " you have: ");
			displayb(myList, SHOWPOS);
			fprintf (stdout, "should be: NULL <- [0] 2\n");
		}
		else
		{
			myList -> last -> after  = mknode(data[i]);
			myList -> last           = myList -> last -> after;
		}

		if (i                       == 2)
		{
			fprintf (stdout, "Displaying populated list without position values:\n");
			fprintf (stdout, " you have: ");
			displayb(myList, NOPOS);
			fprintf (stdout, "should be: NULL <- 8 <- 4 <- 2\n\n");

			fprintf (stdout, "Displaying populated list with position values:\n");
			fprintf (stdout, " you have: ");
			displayb(myList, SHOWPOS);
			fprintf (stdout, "should be: NULL <- [2] 8 <- [1] 4 <- [0] 2\n");
		}
	}

	fprintf (stdout, "Displaying populated list without position values:\n");
	fprintf (stdout, " you have: ");
	displayb(myList, NOPOS);
	fprintf (stdout, "should be: NULL <- 64 <- 32 <- 16 <- 8 <- 4 <- 2\n\n");

	fprintf (stdout, "Displaying populated list with position values:\n");
	fprintf (stdout, " you have: ");
	displayb(myList, SHOWPOS);
	fprintf (stdout, "should be: NULL <- [5] 64 <- [4] 32 <- [3] 16 <- [2] 8 <- [1] 4 <- [0] 2\n");

	return(0);
}
