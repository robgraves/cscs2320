#include "tree.h"
#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//traverse_s()- a tree library utility function to walk through the 
//              tree, by order of the indicated traversal mode, and
//              to produce a list of all the nodes encountered, in 
//              the order they were encountered.
//
//        note: traverse_s() focuses on the actual content of what
//              is in the tree, setting a (double) pointer to a
//              list that contains the ordered content as it was
//              encountered in the tree. To avoid an error, the list
//              should be NULL (create it).
//
//              the tree should not be modified as a result of
//              performing this action.
//
//              the stack-based implementation of traverse() will 
//              embody the utilization of a stack to the solution
//              of the tree traversal process. Once again, we are
//              sacrificing detail-oriented control in the moment
//              for conceptual elegance and simplification, which
//              will test your understanding of stack concepts.
//
//              traverse_s() could be used as a prerequisite step 
//              before calling the list display() function.
//
// status code: this function generates the following status codes:
//                DLT_SUCCESS:     traverse successful
//                DLT_EMPTY:       tree is in EMPTY state
//                DLT_NULL:        tree is in NULL state
//                DLT_ERROR:        an error has taken place (tree
//                                 is NULL, list exists, bad mode).
//
//              you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t traverse_s(Tree *myTree, List **result, uc mode)
{
    //variable declarations and initializations
    code_t coderesult = 0;
    Node *tmp = NULL;
    List *myList = NULL;

    //creating a list to put nodes from tree
    //if (myList != NULL)
    //{
    //    coderesult = DLT_ERROR;
    //}
    //else
    //{
        coderesult = mklist(&myList);
    //}

    if (myTree == NULL)
    {
        coderesult = DLT_ERROR;
    }
    else
    {
        if (myTree == NULL)
        {
            coderesult = DLT_NULL | DLT_ERROR;
        }
        else
        {
            if (myTree->root == NULL)
            {
                coderesult = DLT_EMPTY;
            }
        }
    }

    if (mode == 0)
    {

    }

	return(coderesult);
}
