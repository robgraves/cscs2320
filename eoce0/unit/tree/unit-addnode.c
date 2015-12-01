#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree   *myTree                   = NULL;
    Node   *tmp                      = NULL;
    char    data[]                   = { 11, 9, 13, 11, 7, 6, 4, 2, 8 };
    int     testno                   = 0;
    int     i                        = 0;
    int     nothing                  = 0;
	code_t  result                   = 0;

    fprintf(stdout,     "UNIT TEST: tree library addnode() function\n");
    fprintf(stdout,     "==========================================\n");

    fprintf(stdout,     "Test %d: Adding %hhd to NULL tree ...\n", testno++, data[i]);
    result                           = addnode(&myTree, mknode(data[i]));
    if (myTree                      == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: something\n");

    fprintf(stdout,     "should be: NULL\n\n"); 
    fflush (stdout);

	fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,     " you have: ");
	showcode(result);
	fprintf(stdout,     "should be: ");
	showcode(DLT_NULL | DLT_FAIL);
    fflush (stdout);

    mktree(&myTree, 4);

    fprintf(stdout, "Test %d: Adding %hhd to empty tree ...\n", testno++, data[i]);
    result                           = addnode(&myTree, mknode(data[i]));
    if (myTree                      == NULL)
        fprintf(stdout, " you have: NULL\n");
    else
        fprintf(stdout, " you have: something (success)\n");

    fprintf(stdout,     "should be: something (success)\n\n"); 
    fflush (stdout);

	fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
	fprintf(stdout,     " you have: ");
	showcode(result);
	fprintf(stdout,     "should be: ");
	showcode(DLT_SUCCESS);
    fflush (stdout);

    fprintf(stdout, "Test %d: Checking root ...\n", testno++);
    if (myTree -> root              == NULL)
        fprintf(stdout, " you have: NULL\n");
    else if (myTree -> root ->value == data[i])
        fprintf(stdout, " you have: %hhd\n",   data[i]);
    else
        fprintf(stdout, " you have: %hhd\n",   myTree -> root -> value);

    fprintf(stdout,     "should be: %hhd\n\n", data[i]); 
    fflush (stdout);

    for (i = 1; i < 9; i++)
    {
        // adding a new node to the tree
        fprintf(stdout,     "Test %d: Adding %hhd to tree ...\n", testno++, data[i]);
		result                       = addnode(&myTree, mknode(data[i]));

        switch (i)
        {
            case 1:
                tmp                  = myTree -> root -> prior;
                nothing              = 0;
                break;

            case 2:
                tmp                  = myTree -> root -> after;
                nothing              = 0;
                break;

            case 3:
                tmp                  = myTree -> root -> prior -> after;
                nothing              = 0;
                break;

            case 4:
                tmp                  = myTree -> root -> prior -> prior;
                nothing              = 0;
                break;

            case 5:
                tmp                  = myTree -> root -> prior -> prior -> prior;
                nothing              = 0;
                break;

            case 6:
                tmp                  = myTree -> root -> prior -> prior -> prior -> prior;
                nothing              = 0;
                break;

            case 7:
                tmp                  = myTree -> root -> prior -> prior -> prior -> prior -> prior;
                nothing              = 1;
                break;

            case 8:
                tmp                  = myTree -> root -> prior -> prior -> after;
                nothing              = 0;
                break;
        }

        if (myTree                  == NULL)
            fprintf(stdout, " you have: NULL tree\n");
        else if (myTree -> root     == NULL)
            fprintf(stdout, " you have: empty tree\n");
        else if ((tmp               == NULL) &&
                 (nothing           == 1))
        {
            fprintf(stdout, " you have: exceeded tree height\n");
        }
        else
            fprintf(stdout, " you have: %hhd\n", tmp -> value);

        if (nothing                 == 1)
            fprintf(stdout, "should be: exceeded tree height\n\n"); 
        else
            fprintf(stdout, "should be: %hhd\n\n", data[i]); 
        fflush (stdout);

		fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
		fprintf(stdout,     " you have: ");
		showcode(result);

		fprintf(stdout,     "should be: ");
        if (nothing                 == 1)
			showcode(DLT_MAX | DLT_FAIL);
		else
			showcode(DLT_SUCCESS);
		fflush (stdout);
    }

    tmp                              = myTree -> root;
    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if (myTree      -> root ->value == data[0])
        fprintf(stdout, " you have: OK (%hhd)\n", data[0]);
    else
        fprintf(stdout, " you have: %hhd\n", myTree -> root -> value);

    fprintf(stdout,     "should be: OK (%hhd)\n\n", data[0]); 
    fflush (stdout);

    tmp                              = myTree -> root -> after;
    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if (tmp         -> value        == data[2])
        fprintf(stdout, " you have: OK (%hhd)\n", data[2]);
    else
        fprintf(stdout, " you have: %hhd\n", tmp -> value);

    fprintf(stdout,     "should be: OK (%hhd)\n\n", data[2]); 
    fflush (stdout);

    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if ((tmp        -> after        == NULL) &&
        (tmp        -> prior        == NULL))
    {
        fprintf(stdout, " you have: all connections OK\n");
    }
    else
        fprintf(stdout, " you have: invalid connection\n");

    fprintf(stdout,     "should be: all connections OK\n\n"); 
    fflush (stdout);

    tmp                              = myTree -> root -> prior;
    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if (tmp         -> value        == data[1])
        fprintf(stdout, " you have: OK (%hhd)\n", data[1]);
    else
        fprintf(stdout, " you have: %hhd\n", tmp -> value);

    fprintf(stdout,     "should be: OK (%hhd)\n\n", data[1]); 
    fflush (stdout);

    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if ((tmp        -> after->value == 11) &&
        (tmp        -> prior->value == 7))
    {
        fprintf(stdout, " you have: all connections OK\n");
    }
    else
        fprintf(stdout, " you have: invalid connection\n");

    fprintf(stdout,     "should be: all connections OK\n\n"); 
    fflush (stdout);

    tmp                             = myTree -> root -> prior -> after;
    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if (tmp         -> value        == data[3])
        fprintf(stdout, " you have: OK (%hhd)\n", data[3]);
    else
        fprintf(stdout, " you have: %hhd\n", tmp -> value);

    fprintf(stdout,     "should be: OK (%hhd)\n\n", data[3]); 
    fflush (stdout);

    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if ((tmp        -> after        == NULL) &&
        (tmp        -> prior        == NULL))
    {
        fprintf(stdout, " you have: all connections OK\n");
    }
    else
        fprintf(stdout, " you have: invalid connection\n");

    fprintf(stdout,     "should be: all connections OK\n\n"); 
    fflush (stdout);

    tmp                              = myTree -> root -> prior -> prior;
    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if (tmp         -> value        == data[4])
        fprintf(stdout, " you have: OK (%hhd)\n", data[4]);
    else
        fprintf(stdout, " you have: %hhd\n", tmp -> value);

    fprintf(stdout,     "should be: OK (%hhd)\n\n", data[4]); 
    fflush (stdout);

    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if ((tmp        -> after->value == 8) &&
        (tmp        -> prior->value == 6))
    {
        fprintf(stdout, " you have: all connections OK\n");
    }
    else
        fprintf(stdout, " you have: invalid connection\n");

    fprintf(stdout,     "should be: all connections OK\n\n"); 
    fflush (stdout);

    tmp                              = myTree -> root -> prior -> prior -> prior;
    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if (tmp         -> value        == data[5])
        fprintf(stdout, " you have: OK (%hhd)\n", data[5]);
    else
        fprintf(stdout, " you have: %hhd\n", tmp -> value);

    fprintf(stdout,     "should be: OK (%hhd)\n\n", data[5]); 
    fflush (stdout);

    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if ((tmp        -> after        == NULL) &&
        (tmp        -> prior->value == 4))
    {
        fprintf(stdout, " you have: all connections OK\n");
    }
    else
        fprintf(stdout, " you have: invalid connection\n");

    fprintf(stdout,     "should be: all connections OK\n\n"); 
    fflush (stdout);

    tmp                              = myTree -> root -> prior -> prior -> prior -> prior;
    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if (tmp         -> value        == data[6])
        fprintf(stdout, " you have: OK (%hhd)\n", data[6]);
    else
        fprintf(stdout, " you have: %hhd\n", tmp -> value);

    fprintf(stdout,     "should be: OK (%hhd)\n\n", data[6]); 
    fflush (stdout);

    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if ((tmp        -> after        == NULL) &&
        (tmp        -> prior        == NULL))
    {
        fprintf(stdout, " you have: all connections OK\n");
    }
    else
        fprintf(stdout, " you have: invalid connection\n");

    fprintf(stdout,     "should be: all connections OK\n\n"); 
    fflush (stdout);

    tmp                              = myTree -> root -> prior -> prior -> after;
    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if (tmp         -> value        == data[8])
        fprintf(stdout, " you have: OK (%hhd)\n", data[8]);
    else
        fprintf(stdout, " you have: %hhd\n", tmp -> value);

    fprintf(stdout,     "should be: OK (%hhd)\n\n", data[8]); 
    fflush (stdout);

    fprintf(stdout, "Test %d: Checking tree integrity ...\n", testno++);
    if ((tmp        -> after        == NULL) &&
        (tmp        -> prior        == NULL))
    {
        fprintf(stdout, " you have: all connections OK\n");
    }
    else
        fprintf(stdout, " you have: invalid connection\n");

    fprintf(stdout,     "should be: all connections OK\n\n"); 
    fflush (stdout);

    return(0);
}
