#include <stdio.h>
#include "node.h"
#include "support.h"

int main()
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare Variables
	//
	Node   *tmp     = NULL;
	Node   *tmp2    = NULL;
	int     testno  = 0;
	code_t  result  = 0;

	//////////////////////////////////////////////////////////////////
	//
	// Display unit test banner
	//
	fprintf(stdout, "UNIT TEST: node library cpnode() function\n");
	fprintf(stdout, "=========================================\n");

	//////////////////////////////////////////////////////////////////
	//
	// First test: copying NULL to NULL
	//
	fprintf(stdout, "\nTest %d: Copying NULL to NULL ...\n", testno++);
	result          = cpnode(NULL, NULL);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLN_INVALID);
	fflush (stdout);
	
	//////////////////////////////////////////////////////////////////
	//
	// Second test: copying (NULL) tmp to NULL
	//
	fprintf(stdout, "\nTest %d: Copying NULL node to NULL ...\n", testno++);
	result          = cpnode(tmp, NULL);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLN_INVALID);
	fflush (stdout);
	
	//////////////////////////////////////////////////////////////////
	//
	// Third test: copying (NULL) tmp to (NULL) tmp2
	//
	fprintf(stdout, "\nTest %d: Copying NULL node to NULL node ...\n", testno++);
	result          = cpnode(tmp, &tmp2);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_NULL | DLN_ERROR);
	fflush (stdout);
	
	//////////////////////////////////////////////////////////////////
	//
	// Create an actual node
	//
	mknode(&tmp, 37);

	//////////////////////////////////////////////////////////////////
	//
	// tmp2 is pointing at NULL (set up for clean copy)
	//
	tmp2            = NULL;

	//////////////////////////////////////////////////////////////////
	//
	// Fourth test: copying tmp to tmp2
	//
	fprintf(stdout, "\nTest %d: Copying node ...\n", testno++);
	result          = cpnode(tmp, &tmp2);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_SUCCESS);
	fflush (stdout);
	
	//////////////////////////////////////////////////////////////////
	//
	// Fifth test: checking VALUE
	//
	fprintf(stdout, "\nTest %d: Checking copied node (value) ...\n", testno++);
	fprintf(stdout, " you have: %hhd\n", tmp2 -> VALUE);
	fprintf(stdout, "should be: %hhd\n", tmp  -> VALUE); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Change VALUE of tmp
	//
	if (tmp          != NULL)
		tmp -> VALUE  = 52;

	//////////////////////////////////////////////////////////////////
	//
	// Sixth test: checking VALUE deviation (ensure copied node)
	//
	fprintf(stdout, "\nTest %d: Changing tmp's value ...\n", testno++);
	fprintf(stdout, " you have: %hhd\n", tmp2 -> VALUE);
	fprintf(stdout, "should be: %hhd\n", 37); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Seventh test: checking prior
	//
	fprintf(stdout, "\nTest %d: Checking copied node (prior) ...\n", testno++);
	if (tmp2 -> prior == NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: not NULL\n");

	fprintf(stdout, "should be: NULL\n"); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Eighth test: checking after
	//
	fprintf(stdout, "\nTest %d: Checking copied node (after) ...\n", testno++);
	if (tmp2    -> after                   == NULL)
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: not NULL\n");

	fprintf(stdout, "should be: NULL\n"); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Clear tmp2
	//
	tmp2                                = NULL;

	//////////////////////////////////////////////////////////////////
	//
	// Create new node (tmp2)
	//
	mknode(&tmp2, 73);

	//////////////////////////////////////////////////////////////////
	//
	// Hook new node to original node
	//
	tmp -> after                        = tmp2;

	if (tmp -> after                   != NULL)
	{
		tmp -> after -> prior           = tmp;
		tmp2                            = NULL;

		//////////////////////////////////////////////////////////////
		//
		// Create a third node, hook it in
		//
		mknode(&tmp2, 81);
		tmp -> after -> after           = tmp2;
		tmp -> after -> after -> prior  = tmp -> after;

		result                          = cpnode (tmp -> after, &tmp2);
	}

	//////////////////////////////////////////////////////////////////
	//
	// Ninth test: check results
	//
	fprintf(stdout, "\nTest %d: Copying another node (onto existing node) ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_ERROR | DLN_ALREADY_ALLOC);
	fflush (stdout);
	
	//////////////////////////////////////////////////////////////////
	//
	// Set up another valid copy
	//
	tmp2                                = NULL;
	result                              = cpnode (tmp -> after, &tmp2);

	//////////////////////////////////////////////////////////////////
	//
	// Tenth test: check results
	//
	fprintf(stdout, "\nTest %d: Copying another node ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: "); 
	lscodes(DLN_SUCCESS);
	fflush (stdout);
	
	//////////////////////////////////////////////////////////////////
	//
	// Eleventh test: check VALUE
	//
	fprintf(stdout, "\nTest %d: Checking copied node (value) ...\n", testno++);
	fprintf(stdout, " you have: %hhd\n", tmp2 -> VALUE);
	fprintf(stdout, "should be: %hhd\n", tmp  -> after -> VALUE); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Twelfth test: check prior
	//
	fprintf(stdout, "\nTest %d: Checking copied node (prior) ...\n", testno++);
	fprintf(stdout, " you have: %p\n", tmp2 -> prior);
	fprintf(stdout, "should be: %p\n", tmp  -> after -> prior); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Thirteenth test: check a connected VALUE (via prior)
	//
	fprintf(stdout, "\nTest %d: Checking copied node (priorval) ...\n", testno++);
	fprintf(stdout, " you have: %hhd\n", tmp2 -> prior -> VALUE);
	fprintf(stdout, "should be: %hhd\n", tmp  -> after -> prior -> VALUE); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Fourteenth test: check after
	//
	fprintf(stdout, "\nTest %d: Checking copied node (after) ...\n", testno++);
	fprintf(stdout, " you have: %p\n", tmp2 -> after);
	fprintf(stdout, "should be: %p\n", tmp  -> after -> after); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Fifteenth test: check a connected VALUE (via after)
	//
	fprintf(stdout, "\nTest %d: Checking copied node (afterval) ...\n", testno++);
	fprintf(stdout, " you have: %hhd\n", tmp2 -> after -> VALUE);
	fprintf(stdout, "should be: %hhd\n", tmp  -> after -> after -> VALUE); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Set up valid copy to test DATA element of payload
	//
	tmp2                           = NULL;
	mknode(&tmp2, 64);
	tmp -> after -> DATA           = tmp2;
	tmp -> after -> DATA -> prior  = tmp;
	tmp -> after -> DATA -> after  = tmp -> after -> after;
	tmp2                           = NULL;
	result                         = cpnode(tmp -> after, &tmp2);

	//////////////////////////////////////////////////////////////////
	//
	// Sixteenth test: check that DATA element survived the copy
	//
	fprintf(stdout, "\nTest %d: Checking DATA in copied node ...\n", testno++);
	fprintf(stdout, " you have: %p\n",   tmp2 -> DATA);
	fprintf(stdout, "should be: %p\n",   tmp  -> after -> DATA); 
	fflush (stdout);

	//////////////////////////////////////////////////////////////////
	//
	// Seventeenth test: verify connectivity from tmp2 DATA element
	//
	fprintf(stdout, "\nTest %d: Checking DATA connectivity ...\n", testno++);
	fprintf(stdout, " you have: %p\n",   tmp2 -> DATA -> after -> prior -> prior);
	fprintf(stdout, "should be: %p\n",   tmp); 
	fflush (stdout);

	return(0);
}
