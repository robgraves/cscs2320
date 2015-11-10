#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
    //////////////////////////////////////////////////////////////////
    //
    // Declare variables
    //
    List     *myList1         = NULL;
    List     *myList2         = NULL;
    Node     *ntmp1           = NULL;
    Node     *ntmp2           = NULL;
    int       data[]          = { 1, 2, 4, 8, 16, 32, 48, 64 };
    ulli      pos             = 0;
    code_t    result          = 0;
    int       testno          = 0;
    int       i               = 0;

    fprintf(stdout, "==========================================\n");
    fprintf(stdout, "UNIT TEST: list library compare() function\n");
    fprintf(stdout, "==========================================\n");

    fprintf(stdout, "\nTest %d: Comparing two NULL lists ...\n", testno++);
    result                    = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_L1_NULL | CMP_L2_NULL);
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Comparing non-NULL empty list against a NULL list ...\n", testno++);
    mklist(&myList1);
    result                   = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_L1_EMPTY | CMP_L2_NULL);
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Comparing NULL list against a non-NULL empty list ...\n", testno++);
    myList2                   = myList1;
    myList1                   = NULL;
    result                    = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_L2_EMPTY | CMP_L1_NULL);
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Comparing empty list against an empty list ...\n", testno++);
    mklist(&myList1);
    result                    = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_L2_EMPTY | CMP_L1_EMPTY);
    fflush (stdout);

    for (i = 0; i < 8; i++)
    {
        ntmp1   = NULL;
        mknode(&ntmp1, data[i]);
        tacnode(&myList1, myList1 -> first, ntmp1);
        ntmp2   = NULL;
        mknode(&ntmp2, data[i]);
        tacnode(&myList2, myList2 -> first, ntmp2);
    }

    fprintf(stdout, "\nTest %d: Comparing two identical lists with NULL pos ...\n", testno++);
    result                    = compare(myList1, myList2, NULL);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_EQUALITY);
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Checking pos ...\n", testno++);
    result                    = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: %Lu!\n", pos);
    fprintf(stdout, "should be: 8!\n");
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Comparing empty list against populated list ...\n", testno++);
    myList1                   = NULL; // memory leak!
    mklist(&myList1);
    result                    = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_L1_EMPTY);
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Comparing populated list against empty list ...\n", testno++);
    myList1                   = myList2;
    myList2                   = NULL;
    mklist(&myList2);
    result                    = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_L2_EMPTY);
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Comparing populated lists that differ ...\n", testno++);
    myList2 = NULL;
    cplist(myList1, &myList2);
    myList2 -> first -> after -> after -> after -> VALUE = 37;
    result                    = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_L2_GREATER|CMP_L1_LESS);
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Checking pos ...\n", testno++);
    fprintf(stdout, " you have: %Lu!\n", pos);
    fprintf(stdout, "should be: 4!\n");
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Comparing populated lists that differ ...\n", testno++);
    myList1 -> first -> after -> after = NULL;
    result                    = compare(myList1, myList2, &pos);
    fprintf(stdout, " you have: ");
    lscodes(result);
    fprintf(stdout, "should be: ");
    lscodes(CMP_L2_GREATER);
    fflush (stdout);

    fprintf(stdout, "\nTest %d: Checking pos ...\n", testno++);
    fprintf(stdout, " you have: %Lu!\n", pos);
    fprintf(stdout, "should be: 3!\n");
    fflush (stdout);

    return(0);
}
