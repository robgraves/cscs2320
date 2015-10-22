#include <stdio.h>
#include "list.h"

int main()
{
	List     *myList1         = NULL;
	List     *myList2         = NULL;
	int       data[]          = { 1, 2, 4, 8, 16, 32, 48, 64 };
	ulli      pos             = 0;
	uc        result          = 0;
	int       testno          = 0;
	int       i               = 0;

	fprintf(stdout, "UNIT TEST: list library compare() function\n");
	fprintf(stdout, "==========================================\n");

	fprintf(stdout, "\nTest %d: Comparing two NULL lists ...\n", testno++);
	result                    = compare(myList1, myList2, &pos);
	if (pos                 == 0)
		fprintf(stdout, " you have: EQUAL!\n");
	else if (pos            <  0)
		fprintf(stdout, " you have: myList1 greater!\n");
	else
		fprintf(stdout, " you have: myList2 greater!\n");
	fprintf(stdout, "should be: EQUAL!\n");

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	if ((result & (CMP_L1_NULL | CMP_L2_NULL)) == (CMP_L1_NULL | CMP_L2_NULL))
		fprintf(stdout, " you have: both lists reported as being NULL!\n");
	else
		fprintf(stdout, " you have: error code returned (%.2hhX)\n", result);

	fprintf(stdout, "should be: both lists reported as being NULL!\n"); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Comparing non-NULL empty list against a NULL list ...\n", testno++);
	myList1 = mklist();
	result                   = compare(myList1, myList2, &pos);
	if (result              == CMP_EQUALITY)
		fprintf(stdout, " you have: EQUAL!\n");
	else
		fprintf(stdout, " you have: not equal (%.2hhX)!\n", result);
	fprintf(stdout, "should be: not equal (%.2hhX)!\n", (CMP_L1_EMPTY|CMP_L2_NULL));

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	if ((result & (CMP_L1_EMPTY | CMP_L2_NULL)) == (CMP_L1_EMPTY | CMP_L2_NULL))
		fprintf(stdout, " you have: one list NULL, one list empty!\n");
	else
		fprintf(stdout, " you have: error code returned (%.2hhX)\n", result);

	fprintf(stdout, "should be: one list NULL, one list empty!\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Comparing NULL list against a non-NULL empty list ...\n", testno++);
	myList2                   = myList1;
	myList1                   = NULL;
	result                    = compare(myList1, myList2, &pos);
	if (result               == CMP_EQUALITY)
		fprintf(stdout, " you have: EQUAL!\n");
	else
		fprintf(stdout, " you have: not equal (%.2hhX)!\n", result);
	fprintf(stdout, "should be: not equal (%.2hhX)!\n", (CMP_L2_EMPTY|CMP_L1_NULL));

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	if ((result & (CMP_L2_EMPTY | CMP_L1_NULL)) == (CMP_L2_EMPTY | CMP_L1_NULL))
		fprintf(stdout, " you have: one list NULL, one list empty!\n");
	else
		fprintf(stdout, " you have: error code returned (%.2hhX)\n", result);

	fprintf(stdout, "should be: one list NULL, one list empty!\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Comparing empty list against an empty list ...\n", testno++);
	myList1 = mklist();
	result                    = compare(myList1, myList2, &pos);
	if (result               == CMP_EQUALITY)
		fprintf(stdout, " you have: EQUAL!\n");
	else if ((result & CMP_L1_GREATER) == CMP_L1_GREATER)
		fprintf(stdout, " you have: myList1 greater (%.2hhX)!\n", result);
	else if ((result & (CMP_L1_EMPTY|CMP_L2_EMPTY)) == (CMP_L1_EMPTY|CMP_L2_EMPTY))
		fprintf(stdout, " you have: both lists empty!\n");
	else
		fprintf(stdout, " you have: other condition (%.2hhX)!\n", result);
	fprintf(stdout, "should be: both lists empty!\n");
	fflush (stdout);

	for (i = 0; i < 8; i++)
	{
		myList1 = insert(myList1, myList1 -> first, mknode(data[i]));
		myList2 = insert(myList2, myList2 -> first, mknode(data[i]));
	}

	fprintf(stdout, "\nTest %d: Comparing two identical lists with NULL pos ...\n", testno++);
	result                    = compare(myList1, myList2, NULL);
	if (result               == CMP_EQUALITY)
		fprintf(stdout, " you have: EQUAL!\n");
	else
		fprintf(stdout, " you have: something else (%.2hhX)!\n", result);
	fprintf(stdout, "should be: EQUAL!\n");

	fprintf(stdout, "\nTest %d: Checking pos ...\n", testno++);
	result                    = compare(myList1, myList2, &pos);
	fprintf(stdout, " you have: %Lu!\n", pos);
	fprintf(stdout, "should be: 8!\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Comparing empty list against populated list ...\n", testno++);
	myList1                   = NULL; // memory leak!
	myList1                   = mklist();
	result                    = compare(myList1, myList2, &pos);
	if (result               == CMP_EQUALITY)
		fprintf(stdout, " you have: EQUAL!\n");
	else
		fprintf(stdout, " you have: code (%.2hhX)!\n",result);
	fprintf(stdout, "should be: code (%.2hhX)!\n", CMP_L1_EMPTY);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Comparing populated list against empty list ...\n", testno++);
	myList1                   = myList2;
	myList2                   = NULL;
	myList2                   = mklist();
	result                    = compare(myList1, myList2, &pos);
	if (result               == CMP_EQUALITY)
		fprintf(stdout, " you have: EQUAL!\n");
	else
		fprintf(stdout, " you have: code (%.2hhX)!\n",result);
	fprintf(stdout, "should be: code (%.2hhX)!\n", CMP_L2_EMPTY);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Comparing populated lists that differ ...\n", testno++);
	myList2 = NULL;
	myList2 = cplist(myList1);
	myList2 -> first -> after -> after -> after -> info = 37;
	result                    = compare(myList1, myList2, &pos);
	if (result               == CMP_EQUALITY)
		fprintf(stdout, " you have: EQUAL!\n");
	else
		fprintf(stdout, " you have: code (%.2hhX)!\n", result);
	fprintf(stdout, "should be: code (%.2hhX)!\n", (CMP_L2_GREATER|CMP_L1_LESS));
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking pos ...\n", testno++);
	fprintf(stdout, " you have: %Lu!\n", pos);
	fprintf(stdout, "should be: 4!\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Comparing populated lists that differ ...\n", testno++);
	myList1 -> first -> after -> after = NULL;
	result                    = compare(myList1, myList2, &pos);
	if (result               == CMP_EQUALITY)
		fprintf(stdout, " you have: EQUAL!\n");
	else
		fprintf(stdout, " you have: code (%.2hhX)!\n", result);
	fprintf(stdout, "should be: code (%.2hhX)!\n", CMP_L2_GREATER);
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking pos ...\n", testno++);
	fprintf(stdout, " you have: %Lu!\n", pos);
	fprintf(stdout, "should be: 3!\n");
	fflush (stdout);

	return(0);
}
