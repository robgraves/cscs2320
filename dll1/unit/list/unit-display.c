#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *myList = NULL;
	Node   *tmp    = NULL;
	int     i      = 0;
	int     data[] = { 2, 4, 8, 16, 32, 64 };
	int     testno = 0;
	code_t  result = 0;

	fprintf(stdout, "UNIT TEST: list library display() function\n");
	fprintf(stdout, "==========================================\n");

	fprintf(stdout, "Test %d: Displaying list forward, without position values:\n", testno++);
	fprintf(stdout, " you have: ");
	result = display(myList, DISPLAY_FORWARD|DISPLAY_NOPOSVALS);
	fprintf(stdout, "should be: NULL\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results:\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_NULL);
	fflush (stdout);

	mklist(&myList);

	fprintf(stdout, "\nTest %d: Displaying list forward, without position values:\n", testno++);
	fprintf(stdout, " you have: ");
	result = display(myList, DISPLAY_FORWARD | DISPLAY_NOPOSVALS);
	fprintf(stdout, "should be: -> NULL\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results:\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_EMPTY);
	fflush (stdout);

	for (i = 0; i < 6; i++)
	{
		tmp                          = NULL;
		mknode(&tmp, data[i]);
		catnode(&myList, myList -> last, tmp);
	}

	fprintf(stdout, "\nTest %d: Displaying list forward, without position values:\n", testno++);
	fprintf(stdout, " you have: ");
	result = display(myList, DISPLAY_FORWARD | DISPLAY_NOPOSVALS);
	fprintf(stdout, "should be: 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> NULL\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results:\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Displaying list forward, with position values:\n", testno++);
	fprintf(stdout, " you have: ");
	result = display(myList, DISPLAY_FORWARD| DISPLAY_POSVALS);
	fprintf(stdout, "should be: [0] 2 -> [1] 4 -> [2] 8 -> [3] 16 -> [4] 32 -> [5] 64 -> NULL\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results:\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Displaying list backward, without position values:\n", testno++);
	fprintf(stdout, " you have: ");
	result = display(myList, DISPLAY_BACKWARD | DISPLAY_NOPOSVALS);
	fprintf(stdout, "should be: 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> NULL\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results:\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Displaying list backward, with position values:\n", testno++);
	fprintf(stdout, " you have: ");
	result = display(myList, DISPLAY_BACKWARD | DISPLAY_POSVALS);
	fprintf(stdout, "should be: [5] 64 -> [4] 32 -> [3] 16 -> [2] 8 -> [1] 4 -> [0] 2 -> NULL\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results:\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	return(0);
}
