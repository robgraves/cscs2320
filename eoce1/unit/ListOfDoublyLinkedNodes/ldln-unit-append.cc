#include <cstdio>
#include <cstdlib>
#include "ListOfDoublyLinkedNodes.h"

int main()
{
	List *ltmp   = NULL;
	Node *ntmp   = NULL;
	int   i      = 0;
	int   data[] = { 0, 1, 2, 4, 8, 16, 32, 48, 64 };
	int   num    = 0;
	int   testno = 0;

	const char *output[11];
	output[i++]  = "-> NULL";
	output[i++]  = "-> NULL";
	output[i++]  = "0 -> NULL";
	output[i++]  = "0 -> 1 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> 4 -> NULL";
	output[i++]  = "0 -> 8 -> 1 -> 2 -> 4 -> NULL";
	output[i++]  = "0 -> 8 -> 16 -> 1 -> 2 -> 4 -> NULL";
	output[i++]  = "0 -> 8 -> 16 -> 32 -> 1 -> 2 -> 4 -> NULL";
	output[i++]  = "0 -> 8 -> 16 -> 32 -> 1 -> 48 -> 2 -> 4 -> NULL";
	output[i++]  = "0 -> 8 -> 16 -> 32 -> 1 -> 48 -> 2 -> 64 -> 4 -> NULL";

	fprintf(stdout, "UNIT TEST: ListOfDoublyLinkedNodes class append() function\n");
	fprintf(stdout, "==========================================================\n");

	ltmp         = new ListOfDoublyLinkedNodes();

	// EMPTY list test
	fprintf(stdout, "Test %d: Appending on empty list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	ltmp -> append(NULL, NULL);
	ltmp -> display(0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	
	fprintf(stdout, "Test %d: Check list quantity ...\n", testno++);
	fprintf(stdout, " you have: %d\n", ltmp -> getQuantity()); 
	fprintf(stdout, "should be: %d\n\n", 0); 
	fflush(stdout);

	// Building list
	for(i = 0; i < 4; i++)
	{
		fprintf(stdout, "Test %d: Appending %d after end of list ...\n", testno++, data[i]);
		ntmp     = new DoublyLinkedNode(data[i]);
		fprintf(stdout, " you have: "); 
		ltmp -> append(ltmp -> getLast(), ntmp);
		ltmp -> display(0);
		fprintf(stdout, "should be: %s\n\n", output[num++]); 
		fflush(stdout);

		fprintf(stdout, "Test %d: Check list quantity ...\n", testno++);
		fprintf(stdout, " you have: %d\n", ltmp -> getQuantity()); 
		fprintf(stdout, "should be: %d\n\n", (i+1)); 
		fflush(stdout);
	}

	i = 4;

	fprintf(stdout, "Test %d: Appending %d after start of list ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp -> append(ltmp -> getFirst(), new DoublyLinkedNode(data[i]));
	ltmp -> display(0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Check list quantity ...\n", testno++);
	fprintf(stdout, " you have: %d\n", ltmp -> getQuantity()); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush(stdout);

	fprintf(stdout, "Test %d: Appending %d after second node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp -> append(ltmp -> getFirst() -> getAfter(), new DoublyLinkedNode(data[i]));
	ltmp -> display(0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Check list quantity ...\n", testno++);
	fprintf(stdout, " you have: %d\n", ltmp -> getQuantity()); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush(stdout);

	fprintf(stdout, "Test %d: Appending %d after third node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp -> append(ltmp -> getFirst() -> getAfter() -> getAfter(), new DoublyLinkedNode(data[i]));
	ltmp -> display(0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Check list quantity ...\n", testno++);
	fprintf(stdout, " you have: %d\n", ltmp -> getQuantity()); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush(stdout);

	fprintf(stdout, "Test %d: Appending %d after fifth node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp -> append(ltmp -> getFirst() -> getAfter() -> getAfter() -> getAfter() -> getAfter(), new DoublyLinkedNode(data[i]));
	ltmp -> display(0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Check list quantity ...\n", testno++);
	fprintf(stdout, " you have: %d\n", ltmp -> getQuantity()); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush(stdout);

	fprintf(stdout, "Test %d: Appending %d after last -> prior ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp -> append(ltmp -> getLast() -> getPrior(), new DoublyLinkedNode(data[i]));
	ltmp -> display(0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Check list quantity ...\n", testno++);
	fprintf(stdout, " you have: %d\n", ltmp -> getQuantity()); 
	fprintf(stdout, "should be: %d\n\n", i); 
	fflush(stdout);

	return(0);
}
