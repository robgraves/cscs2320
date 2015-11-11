#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *myList = NULL;
	Node   *tmp    = NULL;
	int     i      = 0;
	int     mode   = 0;
	int     data[] = { 84, 97, 67, 111, 67, 97, 116, 0, 3, 7, 12, 19 };
	int     testno = 0;
	code_t  result = 0;

	fprintf(stdout, "==========================================\n");
	fprintf(stdout, "UNIT TEST: list library display() function\n");
	fprintf(stdout, "==========================================\n");

	fprintf(stdout, "NULL List ...\n\n");

	for (i = 7; i < 12; i++)
	{
		mode = data[i];

		fprintf(stdout, "Test %d: Displaying ", testno++);
		if (mode > 15)
			fprintf(stdout, "(invalid mode) ");
		else
			fprintf(stdout, "list ");

		if ((mode & DISPLAY_BACKWARD) == DISPLAY_BACKWARD)
			fprintf(stdout, "backward, ");
		else
			fprintf(stdout, "forward,  ");

		if ((mode & DISPLAY_NOSEPS) == DISPLAY_NOSEPS)
			fprintf(stdout, "w/o separators, ");
		else
			fprintf(stdout, "w/  separators, ");

		if ((mode & DISPLAY_ASCII) == DISPLAY_ASCII)
			fprintf(stdout, "in ASCII,  ");
		else
			fprintf(stdout, "in values, ");

		if ((mode & DISPLAY_POSVALS) == DISPLAY_POSVALS)
			fprintf(stdout, "w/  position values:\n");
		else
			fprintf(stdout, "w/o position values:\n");

		fprintf(stdout, " you have: ");
		result = display(myList, mode);
		fprintf(stdout, "should be: ");
		echolst(myList, mode);
		fprintf(stdout, "\n");
		fflush (stdout);

		fprintf(stdout, "Test %d: Checking results:\n", testno++);
		fprintf(stdout, " you have: ");
		lscodes(result);
		fprintf(stdout, "should be: ");
		lscodes(DLL_NULL);
		fprintf(stdout, "\n");
		fflush (stdout);
	}

	fprintf(stdout, "EMPTY List ...\n\n");
	mklist(&myList);

	for (i = 7; i < 12; i++)
	{
		mode = data[i] + 1;

		fprintf(stdout, "Test %d: Displaying ", testno++);
		if (mode > 15)
			fprintf(stdout, "(invalid mode) ");
		else
			fprintf(stdout, "list ");

		if ((mode & DISPLAY_BACKWARD) == DISPLAY_BACKWARD)
			fprintf(stdout, "backward, ");
		else
			fprintf(stdout, "forward,  ");

		if ((mode & DISPLAY_NOSEPS) == DISPLAY_NOSEPS)
			fprintf(stdout, "w/o separators, ");
		else
			fprintf(stdout, "w/  separators,    ");

		if ((mode & DISPLAY_ASCII) == DISPLAY_ASCII)
			fprintf(stdout, "in ASCII,  ");
		else
			fprintf(stdout, "in values, ");

		if ((mode & DISPLAY_POSVALS) == DISPLAY_POSVALS)
			fprintf(stdout, "w/  position values:\n");
		else
			fprintf(stdout, "w/o position values:\n");

		fprintf(stdout, " you have: ");
		result = display(myList, mode);
		fprintf(stdout, "should be: ");
		echolst(myList, mode);
		fprintf(stdout, "\n");
		fflush (stdout);

		fprintf(stdout, "Test %d: Checking results:\n", testno++);
		fprintf(stdout, " you have: ");
		lscodes(result);
		fprintf(stdout, "should be: ");
		lscodes(DLL_EMPTY);
		fprintf(stdout, "\n");
		fflush (stdout);
	}

	fprintf(stdout, "Populated List ...\n\n");

	for (i = 0; i < 7; i++)
	{
		tmp                          = NULL;
		mknode(&tmp, data[i]);
		catnode(&myList, myList -> last, tmp);
	}

	for (i = 0; i < 17; i++)
	{
		fprintf(stdout, "Test %d: Displaying ", testno++);
		if (i > 15)
			fprintf(stdout, "(invalid mode) ");
		else
			fprintf(stdout, "list ");

		if ((i & DISPLAY_BACKWARD) == DISPLAY_BACKWARD)
			fprintf(stdout, "backward, ");
		else
			fprintf(stdout, "forward,  ");

		if ((i & DISPLAY_NOSEPS) == DISPLAY_NOSEPS)
			fprintf(stdout, "w/o separators, ");
		else
			fprintf(stdout, "w/  separators, ");

		if ((i & DISPLAY_ASCII) == DISPLAY_ASCII)
			fprintf(stdout, "in ASCII,  ");
		else
			fprintf(stdout, "in values, ");

		if ((i & DISPLAY_POSVALS) == DISPLAY_POSVALS)
			fprintf(stdout, "w/  position values:\n");
		else
			fprintf(stdout, "w/o position values:\n");

		fprintf(stdout, " you have: ");
		result = display(myList, i);
		fprintf(stdout, "should be: ");
		echolst(myList, i);
		fprintf(stdout, "\n");
		fflush (stdout);

		fprintf(stdout, "Test %d: Checking results:\n", testno++);
		fprintf(stdout, " you have: ");
		lscodes(result);
		fprintf(stdout, "should be: ");
		lscodes(DLL_SUCCESS);
		fprintf(stdout, "\n");
		fflush (stdout);
	}

	fprintf(stdout, "==========================================\n");

	return(0);
}
