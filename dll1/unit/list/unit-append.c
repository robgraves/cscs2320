#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *ltmp   = NULL;
	Node   *ntmp   = NULL;
	Node   *ntmp2  = NULL;
	int     i      = 0;
	int     data[] = { 0, 1, 2, 4, 8, 16, 32, 48, 64 };
	int     num    = 0;
	int     testno = 0;
	code_t  result = 0;

	char   *output[20];
	output[i++]    = "NULL";
	output[i++]    = "-> NULL";
	output[i++]    = "0 -> NULL";
	output[i++]    = "0 -> NULL";
	output[i++]    = "0 -> 1 -> NULL";
	output[i++]    = "1 -> 0 -> NULL";
	output[i++]    = "0 -> 1 -> 2 -> NULL";
	output[i++]    = "2 -> 1 -> 0 -> NULL";
	output[i++]    = "0 -> 1 -> 2 -> 4 -> NULL";
	output[i++]    = "4 -> 2 -> 1 -> 0 -> NULL";
	output[i++]    = "0 -> 8 -> 1 -> 2 -> 4 -> NULL";
	output[i++]    = "4 -> 2 -> 1 -> 8 -> 0 -> NULL";
	output[i++]    = "0 -> 8 -> 16 -> 1 -> 2 -> 4 -> NULL";
	output[i++]    = "4 -> 2 -> 1 -> 16 -> 8 -> 0 -> NULL";
	output[i++]    = "0 -> 8 -> 16 -> 32 -> 1 -> 2 -> 4 -> NULL";
	output[i++]    = "4 -> 2 -> 1 -> 32 -> 16 -> 8 -> 0 -> NULL";
	output[i++]    = "0 -> 8 -> 16 -> 32 -> 1 -> 48 -> 2 -> 4 -> NULL";
	output[i++]    = "4 -> 2 -> 48 -> 1 -> 32 -> 16 -> 8 -> 0 -> NULL";
	output[i++]    = "0 -> 8 -> 16 -> 32 -> 1 -> 48 -> 2 -> 64 -> 4 -> NULL";
	output[i++]    = "4 -> 64 -> 2 -> 48 -> 1 -> 32 -> 16 -> 8 -> 0 -> NULL";

	fprintf(stdout, "UNIT TEST: list library append() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "Test %d: Checking NULL case ...\n", testno++);
	result         = append(NULL, NULL, NULL);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_ERROR | DLL_INVALID);
	fflush (stdout);

	// NULL list test
	fprintf(stdout, "\nTest %d: Appending on NULL list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	result         = append(&ltmp, NULL, NULL);
	listcat(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_NULL | DLL_ERROR);
	fflush (stdout);

	mklist(&ltmp);

	// EMPTY list test
	fprintf(stdout, "\nTest %d: Appending on empty list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	result         = append(&ltmp, NULL, NULL);
	listcat(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);
	
	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_EMPTY | DLL_ERROR | DLN_NULL);
	fflush (stdout);

	// Building list
	for(i = 0; i < 4; i++)
	{
		fprintf(stdout, "\nTest %d: Appending %d after end of list ...\n", testno++, data[i]);
		ntmp       = NULL;
		mknode(&ntmp, data[i]);
		fprintf(stdout, " you have: "); 
		result     = append(&ltmp, ltmp -> last, ntmp);
		listcat(ltmp);
		fprintf(stdout, "should be: %s\n", output[num++]); 
		fflush (stdout);

		fprintf(stdout, "\nTest %d: Checking list consistency (reverse) ...\n", testno++);
		fprintf(stdout, " you have: "); 
		listtac(ltmp);
		fprintf(stdout, "should be: %s\n", output[num++]); 
		fflush (stdout);

		fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
		fprintf(stdout, " you have: "); 
		lscodes(result);
		fprintf(stdout, "should be: "); 
		lscodes(DLL_SUCCESS);
		fflush (stdout);
	}

	i = 4;

	fprintf(stdout, "\nTest %d: Appending %d after start of list ...\n", testno++, data[i]);
	ntmp         = NULL;
	mknode(&ntmp, data[i]);
	result       = append(&ltmp, ltmp -> first, ntmp);
	fprintf(stdout, " you have: ");
	listcat(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);
	i            = i + 1;

	fprintf(stdout, "\nTest %d: Checking list consistency (reverse) ...\n", testno++);
	fprintf(stdout, " you have: "); 
	listtac(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Appending %d after second node ...\n", testno++, data[i]);
	ntmp          = NULL;
	mknode(&ntmp, data[i]);
	result        = append(&ltmp, ltmp -> first -> after, ntmp);
	fprintf(stdout, " you have: ");
	listcat(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);
	i             = i + 1;

	fprintf(stdout, "\nTest %d: Checking list consistency (reverse) ...\n", testno++);
	fprintf(stdout, " you have: "); 
	listtac(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Appending %d after third node ...\n", testno++, data[i]);
	ntmp          = NULL;
	mknode(&ntmp, data[i]);
	result        = append(&ltmp, ltmp -> first -> after -> after, ntmp);
	fprintf(stdout, " you have: ");
	listcat(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);
	i            = i + 1;

	fprintf(stdout, "\nTest %d: Checking list consistency (reverse) ...\n", testno++);
	fprintf(stdout, " you have: "); 
	listtac(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Appending %d after fifth node ...\n", testno++, data[i]);
	ntmp          = NULL;
	mknode(&ntmp, data[i]);
	result        = append(&ltmp, ltmp -> first -> after -> after -> after -> after, ntmp);
	fprintf(stdout, " you have: ");
	listcat(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);
	i            = i + 1;

	fprintf(stdout, "\nTest %d: Checking list consistency (reverse) ...\n", testno++);
	fprintf(stdout, " you have: "); 
	listtac(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Appending %d after end -> prior ...\n", testno++, data[i]);
	ntmp          = NULL;
	mknode(&ntmp, data[i]);
	result        = append(&ltmp, ltmp -> last -> prior, ntmp);
	fprintf(stdout, " you have: ");
	listcat(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);
	i            = i + 1;

	fprintf(stdout, "\nTest %d: Checking list consistency (reverse) ...\n", testno++);
	fprintf(stdout, " you have: "); 
	listtac(ltmp);
	fprintf(stdout, "should be: %s\n", output[num++]); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLL_SUCCESS);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Appending NULL into existing list ...\n", testno++);
	ntmp     = NULL;
	result   = append(&ltmp, ltmp -> first -> after, ntmp);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_NULL | DLL_ERROR);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Appending node at invalid place ...\n", testno++);
	ntmp     = NULL;
	mknode(&ntmp, 7);
	ntmp2    = NULL;
	mknode(&ntmp2, 9);
	result   = append(&ltmp, ntmp2, ntmp);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLL_INVALID);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Appending node at NULL place ...\n", testno++);
	ntmp     = NULL;
	mknode(&ntmp, 7);
	result   = append(&ltmp, NULL, ntmp);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLN_NULL | DLL_ERROR | DLL_INVALID);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Appending NULL at NULL place ...\n", testno++);
	ntmp     = NULL;
	result   = append(&ltmp, NULL, ntmp);
	fprintf(stdout, " you have: "); 
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_NULL | DLL_ERROR);
	fflush (stdout);

	return(0);
}
