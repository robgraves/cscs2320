#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	List   *ltmp          = NULL;
	Node   *ntmp          = NULL;
	Node   *ntmp2         = NULL;
	int     i             = 0;
	int     j             = 0;
	int     data[]        = { 0, 1, 2, 4, 8, 16, 32, 48, 64 };
	int     num           = 0;
	int     testno        = 0;
	code_t  result        = 0;

	char *output[26];
	output[i++]           = "NULL";
	output[i++]           = "-> NULL";
	output[i++]           = "-> NULL";
	output[i++]           = "-> NULL";
	output[i++]           = "1 -> NULL";
	output[i++]           = "1 -> NULL";
	output[i++]           = "0 -> NULL";
	output[i++]           = "0 -> NULL";
	output[i++]           = "1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 -> NULL";
	output[i++]           = "0 -> 2 -> 4 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 32 -> 16 -> 8 -> 4 -> 2 -> 0 -> NULL";
	output[i++]           = "0 -> 1 -> 4 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 32 -> 16 -> 8 -> 4 -> 1 -> 0 -> NULL";
	output[i++]           = "0 -> 1 -> 2 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 32 -> 16 -> 8 -> 2 -> 1 -> 0 -> NULL";
	output[i++]           = "0 -> 1 -> 2 -> 4 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 32 -> 16 -> 4 -> 2 -> 1 -> 0 -> NULL";
	output[i++]           = "0 -> 1 -> 2 -> 4 -> 8 -> 32 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 32 -> 8 -> 4 -> 2 -> 1 -> 0 -> NULL";
	output[i++]           = "0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 48 -> 64 -> NULL";
	output[i++]           = "64 -> 48 -> 16 -> 8 -> 4 -> 2 -> 1 -> 0 -> NULL";
	output[i++]           = "0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> NULL";
	output[i++]           = "64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 -> 0 -> NULL";
	output[i++]           = "0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 48 -> NULL";
	output[i++]           = "48 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 -> 0 -> NULL";

	//////////////////////////////////////////////////////////////////
	//
	// Display unit test banner
	//
	fprintf(stdout, "=========================================\n");
	fprintf(stdout, "UNIT TEST: list library obtain() function\n");
	fprintf(stdout, "=========================================\n");

	//////////////////////////////////////////////////////////////////
	//
	// Test NULL case 1 (non-existent list)
	//
	result                = obtain(NULL, &ntmp);
	fprintf(stdout, "Test %d: Checking non-existent list ... \n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_ERROR | DLL_INVALID);
	fprintf(stdout, "\n");
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Test NULL case 2 (non-existent node)
	//
	result                = obtain(&ltmp, NULL);
	fprintf(stdout, "Test %d: Checking non-existent node ... \n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_ERROR | DLL_NULL);
	fprintf(stdout, "\n");
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Test NULL case 3 (non-existent list and node)
	//
	result                = obtain(NULL, NULL);
	fprintf(stdout, "Test %d: Checking non-existent list and node ... \n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_ERROR | DLL_INVALID);
	fprintf(stdout, "\n");
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Test NULL list case 1 (NULL list and NULL node)
	//
	result                = obtain(&ltmp, &ntmp);
	fprintf(stdout, "Test %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_ERROR | DLL_NULL);
	fprintf(stdout, "\n");
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Create new (EMPTY) list
	//
	mklist(&ltmp);
	num++;

	//////////////////////////////////////////////////////////////////
	//
	// Empty list test 1 (NULL node)
	//
	result                = obtain(&ltmp, &ntmp);
	fprintf(stdout, "Test %d: Obtaining on empty list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	listcat(ltmp);
	fprintf(stdout, "should be: %s\n\n", output[num++]);
	fflush (stdout);
	
	//////////////////////////////////////////////////////////////////
	//
	// Empty list test 1 check status code(s)
	//
	fprintf(stdout, "Test %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_ERROR | DLL_EMPTY);
	fprintf(stdout, "\n");
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Build (and check) the list
	//
	for (i = 0; i <= 8; i++)
	{
		ntmp = NULL;
		mknode(&ntmp, data[i]);
		catnode(&ltmp, ltmp -> last,  ntmp);

		if (i            == 0)
		{
			//////////////////////////////////////////////////////////
			//
			// Edge case 1: Check obtain() from one-node list
			//
			ntmp          = ltmp -> first;
			result        = obtain(&ltmp, &ntmp);
			fprintf(stdout, "Test %d: Obtaining from one-node list (1/2) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			listcat(ltmp);
			fprintf(stdout, "should be: %s\n\n", output[num++]);
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 1: Check obtain() from one-node list
			//
			fprintf(stdout, "Test %d: Checking list integrity (reversed) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			listtac(ltmp);
			fprintf(stdout, "should be: %s\n\n", output[num++]);
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 1: Verify status codes
			//
			fprintf(stdout, "Test %d: Checking results ...\n", testno++);
			fprintf(stdout, " you have: ");
			lscodes(result);
			fprintf(stdout, "should be: ");
			lscodes(DLL_SUCCESS | DLL_EMPTY);
			fprintf(stdout, "\n");
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 1: Verify node contents
			//
			fprintf(stdout, "Test %d: Obtaining on one-node list (2/2) ...\n", testno++);
			fprintf(stdout, " you have: %d\n",   ntmp -> VALUE); 
			fprintf(stdout, "should be: %d\n\n", data[i]); 
			fflush (stdout);
			
			//////////////////////////////////////////////////////////
			//
			// Fix list for next test
			//
			tacnode(&ltmp, ltmp -> first, ntmp);
		}
		else if (i       == 1)
		{
			//////////////////////////////////////////////////////////
			//
			// Edge case 2: Two node list obtain() from start of list
			//
			ntmp          = ltmp -> first;
			result        = obtain(&ltmp, &ntmp);
			fprintf(stdout, "Test %d: Obtain on two-node list (1/4) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			listcat(ltmp);
			fprintf(stdout, "should be: %s\n\n", output[num++]);
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 2: Two node list obtain() (check reverse)
			//
			fprintf(stdout, "Test %d: Check list integrity (reversed) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			listtac(ltmp);
			fprintf(stdout, "should be: %s\n\n", output[num++]);
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 2: Verify status codes
			//
			fprintf(stdout, "Test %d: Checking results ...\n", testno++);
			fprintf(stdout, " you have: ");
			lscodes(result);
			fprintf(stdout, "should be: ");
			lscodes(DLL_SUCCESS);
			fprintf(stdout, "\n");
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 2: Verify node contents
			//
			fprintf(stdout, "Test %d: Obtaining on two-node list (2/4) ...\n", testno++);
			fprintf(stdout, " you have: %d\n",   ntmp -> VALUE); 
			fprintf(stdout, "should be: %d\n\n", data[0]); 
			fflush (stdout);
			
			//////////////////////////////////////////////////////////
			//
			// Edge case 2: Check state of list
			//
			fprintf(stdout, "Test %d: Is first now last? ...\n", testno++);
			fprintf(stdout, " you have: %d\n",   ltmp -> first -> VALUE); 
			fprintf(stdout, "should be: %d\n\n", data[1]); 
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Fix list for next test
			//
			tacnode(&ltmp, ltmp -> first, ntmp);

			//////////////////////////////////////////////////////////
			//
			// Edge case 3: Two node list obtain() from end of list
			//
			ntmp         = ltmp -> last;
			result       = obtain(&ltmp, &ntmp);
			fprintf(stdout, "Test %d: Obtaining on two-node list (3/4) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			listcat(ltmp);
			fprintf(stdout, "should be: %s\n\n", output[num++]);
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 3: Two node list obtain() (check reverse)
			//
			fprintf(stdout, "Test %d: Checking list integrity (reversed) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			listtac(ltmp);
			fprintf(stdout, "should be: %s\n\n", output[num++]);
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 3: Verify status codes
			//
			fprintf(stdout, "Test %d: Checking results ...\n", testno++);
			fprintf(stdout, " you have: ");
			lscodes(result);
			fprintf(stdout, "should be: ");
			lscodes(DLL_SUCCESS);
			fprintf(stdout, "\n");
			fflush (stdout);

			//////////////////////////////////////////////////////////
			//
			// Edge case 3: Verify node contents
			//
			fprintf(stdout, "Test %d: Obtaining on two-node list (4/4) ...\n", testno++);
			fprintf(stdout, " you have: %d\n",   ntmp -> VALUE); 
			fprintf(stdout, "should be: %d\n\n", data[1]); 
			fflush (stdout);
			
			//////////////////////////////////////////////////////////
			//
			// Edge case 3: Check state of list
			//
			fprintf(stdout, "Test %d: Is last now first? ...\n", testno++);
			fprintf(stdout, " you have: %d\n",   ltmp -> last -> VALUE); 
			fprintf(stdout, "should be: %d\n\n", data[0]); 
			fflush (stdout);
			
			//////////////////////////////////////////////////////////
			//
			// Fix list for next test
			//
			catnode(&ltmp, ltmp -> last, ntmp);
		}
	}

	//////////////////////////////////////////////////////////////////
	//
	// Check for out-of-list condition
	//
	ntmp           = NULL;
	mknode(&ntmp, 17);
	result         = obtain(&ltmp, &ntmp);
	fprintf(stdout, "Test %d: Checking for out-of-list node ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_ERROR);
	fprintf(stdout, "\n");
	fflush (stdout);

	for (i = 0; i <= 8; i++)
	{
		//////////////////////////////////////////////////////////////
		//
		// Position ntmp
		//
		ntmp       = ltmp -> first;
		for (j = 0; j < i; j++)
			ntmp   = ntmp -> after;

		//////////////////////////////////////////////////////////////
		//
		// List obtain()
		//
		ntmp2      = ntmp -> after;
		result     = obtain(&ltmp, &ntmp);
		fprintf(stdout, "Test %d: Checking list integrity (pos %d/8) ...\n", testno++, i);
		fprintf(stdout, " you have: "); 
		listcat(ltmp);
		fprintf(stdout, "should be: %s\n\n", output[num++]);
		fflush (stdout);

		//////////////////////////////////////////////////////////////
		//
		// List obtain() reverse check
		//
		fprintf(stdout, "Test %d: Check list integrity (reversed) ...\n", testno++);
		fprintf(stdout, " you have: "); 
		listtac(ltmp);
		fprintf(stdout, "should be: %s\n\n", output[num++]);
		fflush (stdout);

		//////////////////////////////////////////////////////////////
		//
		// List obtain(): verify status codes
		//
		fprintf(stdout, "Test %d: Checking results ...\n", testno++);
		fprintf(stdout, " you have: ");
		lscodes(result);
		fprintf(stdout, "should be: ");
		lscodes(DLL_SUCCESS);
		fprintf(stdout, "\n");
		fflush (stdout);

		//////////////////////////////////////////////////////////////
		//
		// List obtain(): verify node contents
		//
		fprintf(stdout, "Test %d: Checking obtained value ...\n", testno++);
		fprintf(stdout, " you have: %d\n",   ntmp -> VALUE); 
		fprintf(stdout, "should be: %d\n\n", data[i]); 
		fflush (stdout);

		//////////////////////////////////////////////////////////////
		//
		// Further list mangling
		//
		if (ntmp  != ntmp2) // trying to reduce uncompleted obtain problems
		{
			if (i     != 8)
				tacnode(&ltmp, ntmp2, ntmp);
			else
				catnode(&ltmp, ntmp2, ntmp);
		}
	}

	fprintf(stdout, "=========================================\n");

	return(0);
}
