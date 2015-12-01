#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//traverse_r()- a tree library utility function to walk through the 
//              tree, by order of the indicated traversal mode, and
//              to produce a list of all the nodes encountered, in 
//              the order they were encountered.
//
//        note: traverse_r() focuses on the actual content of what
//              is in the tree, setting a (double) pointer to a
//              list that contains the ordered content as it was
//              encountered in the tree. To avoid an error, the list
//              should be NULL (create it).
//
//              the tree should not be modified as a result of
//              performing this action.
//
//              the recursive implementation of traverse_r() will 
//              embody the conceptual elegance often found in
//              such solutions: shorter code, less detail-oriented,
//              and relying centrally and heavily on calling some
//              function again and again as the means of processing.
//              While you cannot alter the header file, you may want
//              to implement a custom more local function that this
//              traverse_r() function calls.
//
//              traverse_r() could be used as a prerequisite step 
//              before calling the list display() function.
//
// status code: this function generates the following status codes:
//                DLT_SUCCESS:     traverse successful
//                DLT_EMPTY:       tree is in EMPTY state
//                DLT_NULL:        tree is in NULL state
//                DLT_FAIL:        an error has taken place (tree
//                                 is NULL, list exists, bad mode).
//
//              you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t traverse_r(Tree *myTree, List **result, uc mode)
{
	// your implementation here (please remove this comment when done)
	return(DLT_DEFAULT_FAIL);
}
