#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "support.h"

int main()
{
    Tree   *myTree                    = NULL;
    List   *tmpList                   = NULL;
	Node   *tmp                       = NULL;
    char    data[]                    = { 11, 9, 13, 11, 7, 6, 4, 2, 8 };
    int     testno                    = 0;
    int     i                         = 0;
    int     j                         = 0;
    code_t  result                    = 0;
    char   *output[3];
    output[INORDER]                   = "11 -> 9 -> 7 -> 6 -> 4 -> 8 -> 11 -> 13 -> NULL";
    output[PREORDER]                  = "4 -> 6 -> 7 -> 8 -> 9 -> 11 -> 11 -> 13 -> NULL";
    output[POSTORDER]                 = "13 -> 11 -> 11 -> 9 -> 8 -> 7 -> 6 -> 4 -> NULL";

    fprintf(stdout,     "UNIT TEST: tree library traverse_s() function\n");
    fprintf(stdout,     "=============================================\n");

    for (i     = 0;         i <  2;             i++)
    {
        if (i                            == 1)
            mklist(&tmpList);

        for (j = INORDER;   j <= POSTORDER + 1; j++)
        {
            fprintf(stdout,     "Test %d: ", testno++);
            fprintf(stdout, "RECURSIVE   ");
            result                        = traverse_s(myTree, &tmpList, j);

            if (j                        == INORDER)
                fprintf(stdout, "INORDER   ");
            else if (j                   == PREORDER)
                fprintf(stdout, "PREORDER  ");
            else if (j                   == POSTORDER)
                fprintf(stdout, "POSTORDER ");
            else
                fprintf(stdout, "*INVALID* ");

            fprintf(stdout,     "traversal of NULL tree (run %d) ...\n", i);

            if (myTree                   == NULL)
            {
                if (tmpList              == NULL)
                    fprintf(stdout, " you have: NULL tree and NULL list\n");
                else
                    fprintf(stdout, " you have: NULL tree and non-NULL list\n");
            }
            else
            {
                if (tmpList              == NULL)
                    fprintf(stdout, " you have: non-NULL tree and NULL list\n");
                else
                    fprintf(stdout, " you have: non-NULL tree and non-NULL list\n");
            }

            if (i                        == 0)
                fprintf(stdout,     "should be: NULL tree and NULL list\n\n");
            else
                fprintf(stdout,     "should be: NULL tree and non-NULL list\n\n");
            fflush (stdout);

            fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
            fprintf(stdout,     " you have: ");
            lscodes(result);
            fprintf(stdout,     "should be: ");
            lscodes(DLT_ERROR | DLT_NULL);
            fprintf(stdout,     "\n");
            fflush (stdout);
        }
    }

    result                            = mktree(&myTree, 4);
    rmlist(&tmpList);

    for (i     = 0;         i <  2;             i++)
    {
        if (i                            == 1)
            mklist(&tmpList);

        for (j = INORDER;   j <= POSTORDER + 1; j++)
        {
            fprintf(stdout,     "Test %d: ", testno++);
            fprintf(stdout, "RECURSIVE ");
            result                        = traverse_s(myTree, &tmpList, j);

            if (j                        == INORDER)
                fprintf(stdout, "INORDER   ");
            else if (j                   == PREORDER)
                fprintf(stdout, "PREORDER  ");
            else if (j                   == POSTORDER)
                fprintf(stdout, "POSTORDER ");
            else
                fprintf(stdout, "*INVALID* ");

            fprintf(stdout,     "traversal of empty tree (run %d)...\n", i);
            fprintf(stdout,     " you have: ");
            display(tmpList, 0);

            if (j                       == POSTORDER + 1)
                fprintf(stdout, "should be: NULL\n\n"); 
            else
                fprintf(stdout, "should be: -> NULL\n\n"); 

            fflush (stdout);

            fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
            fprintf(stdout,     " you have: ");
            lscodes(result);

            fprintf(stdout,     "should be: ");
            if ((i == 0) && (j != POSTORDER+1))
                lscodes(DLT_EMPTY|DLT_SUCCESS|DLL_EMPTY);
            else if (j == POSTORDER+1)
                lscodes(DLT_ERROR|DLT_EMPTY);
            else
                lscodes(DLT_EMPTY|DLT_ERROR|DLL_ERROR|DLL_ALREADY_ALLOC);
            fprintf(stdout,     "\n");
            fflush (stdout);

            rmlist(&tmpList);
        }
    }

//    result                            = mktree(&myTree, 4);

    for (j = 0; j < 9; j++)
	{
		tmp                           = NULL;
		mknode(&tmp, data[j]);
        result                        = addnode(&myTree, tmp);
	}

    for (i     = 0;         i <  2;             i++)
    {
        if (i                            == 1)
            mklist(&tmpList);

        for (j = INORDER;   j <= POSTORDER + 1; j++)
        {
            fprintf(stdout,     "Test %d: ", testno++);
            fprintf(stdout, "RECURSIVE ");
            result                        = traverse_s(myTree, &tmpList, j);

            if (j                        == INORDER)
                fprintf(stdout, "INORDER   ");
            else if (j                   == PREORDER)
                fprintf(stdout, "PREORDER  ");
            else if (j                   == POSTORDER)
                fprintf(stdout, "POSTORDER ");
            else
                fprintf(stdout, "*INVALID* ");

            fprintf(stdout,     "traversal of populated tree (run %d) ...\n", i);
            if (i                        == 0)
            {
                fprintf(stdout,     " you have: ");
                display(tmpList, 0);

                if (j                        != POSTORDER + 1)
                    fprintf(stdout, "should be: %s\n\n", output[j]); 
                else
                    fprintf(stdout, "should be: NULL\n\n"); 

                fflush (stdout);

                fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
            }

            fprintf(stdout,     " you have: ");
            lscodes(result);

            fprintf(stdout,     "should be: ");
            if ((i == 0) && (j != POSTORDER + 1))
                lscodes(DLT_SUCCESS);
            else if (j == POSTORDER+1)
                lscodes(DLT_ERROR);
            else
                lscodes(DLT_ERROR|DLL_ALREADY_ALLOC|DLL_ERROR);
            fprintf(stdout,     "\n");

            fflush (stdout);

            rmlist(&tmpList);
            tmpList = NULL;
        }
    }
    return(0);
}
