#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree   *myTree                   = NULL;
    Tree   *myTree2                  = NULL;
	List   *tmpList                  = NULL;
    Node   *tmp                      = NULL;
    char    data[]                   = { 11, 9, 13, 11, 7, 6, 4, 2, 8 };
    int     testno                   = 0;
   // int     mode                     = 0;
    int     variation                = 0;
    int     k                        = 0;
	code_t  result                   = 0;

    fprintf(stdout,             "UNIT TEST: tree library cptree_r() function\n");
    fprintf(stdout,             "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // number of test cycles
    //
    for (variation = 0; variation < 6; variation++)
    {
        //////////////////////////////////////////////////////////////
        //
        // cycle through our three implementations
        //
    //    for (mode = RECURSIVE; mode <= ITERATIVE; mode++)
     //   {
            //////////////////////////////////////////////////////////
            //
            // after the NULL run, be sure to allocate a tree
            //
            if (variation           == 1)
            {
                mktree(&myTree, 0);
                tmp                  = myTree -> root;
            }

            //////////////////////////////////////////////////////////
            //
            // test logic for trees with only one (just a root) node
            //
            if (variation           == 2)
            {
				if (myTree -> root  == NULL)
                    addnode(&myTree, mknode(data[0]));
            }

            //////////////////////////////////////////////////////////
            //
            // populate our tree for the remaining half of tests
            //
            else if (variation      == 3)
            {
				for (k = 1; k < 9; k++)
					addnode(&myTree, mknode(data[k]));
            }

            //////////////////////////////////////////////////////////
            //
            // identify test run and current mode
            //
            fprintf(stdout,     "Test %d: ", testno++);
//            if (mode                == RECURSIVE)
                fprintf(stdout, "RECURSIVE   ");
//            else if (mode           == STACK_BASED)
//                fprintf(stdout, "STACK_BASED ");
//            else if (mode           == ITERATIVE)
//                fprintf(stdout, "ITERATIVE   ");

            //////////////////////////////////////////////////////////
            //
            // in variation 4 we balance the tree before copying
            //
//            if (variation           == 4)
 //               myTree               = balance(myTree);

            //////////////////////////////////////////////////////////
            //
            // in variation 5 we grab a node out of the tree before
            // copying
            //
            if (variation           == 5)
            //else if (variation      == 5)
            {
                tmp                  = myTree -> root -> prior;
				grabnode_r(&myTree, &tmp);
            }

            //////////////////////////////////////////////////////////
            //
            // set the tree's mode (recursive, stack-based, iterative)
            //
//            myTree                   = set_mode(myTree, mode);

            //////////////////////////////////////////////////////////
            //
            // copy the tree
            //
			myTree2                  = NULL; // bad
			result                   = cptree_r(myTree, &myTree2);

            //////////////////////////////////////////////////////////
            //
            // display a description of the current tree state
            //
            if (variation           == 0)
                fprintf(stdout, "copying NULL tree ...\n");
            else if (variation      == 1)
                fprintf(stdout, "copying empty tree ...\n");
            else if (variation      == 2)
                fprintf(stdout, "copying tree with one node ...\n");
            else if (variation      == 4)
                fprintf(stdout, "copying tree ...\n");
 //               fprintf(stdout, "copying balanced tree ...\n");
            else if (variation      == 5)
                fprintf(stdout, "copying tree we've removed from ...\n");
            else
                fprintf(stdout, "copying populated tree ...\n");

            //////////////////////////////////////////////////////////
            //
            // display the results
            //
            fprintf(stdout,     " you have: ");
			traverse_r(myTree2, &tmpList, INORDER);
            display(tmpList, 0);
			rmlist(&tmpList);

            fprintf(stdout,     "should be: "); 
			traverse_r(myTree,  &tmpList, INORDER);
            display(tmpList, 0);
			rmlist(&tmpList);
            fprintf(stdout,     "\n");
            fflush (stdout);

			fprintf(stdout,     "Test %d: Checking results ...\n", testno++);
			fprintf(stdout,     " you have: ");
			showcode(result);

			fprintf(stdout,     "should be: ");
			if (variation == 0)
				showcode(DLT_FAIL|DLT_NULL);
			else if (variation == 1)
				showcode(DLT_SUCCESS|DLT_EMPTY|DLL_EMPTY);
			else if (variation >= 2)
				showcode(DLT_SUCCESS);

            fprintf(stdout,     "\n");
            fflush (stdout);

//        }
    }
	result = result + 1;
    return(0);
}
