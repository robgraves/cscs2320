#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//searchtree()- a tree library utility function to locate a node in
//              an existing tree by value it contains.
//
//        note: searchtree() focuses on the actual content of what
//              is in the nodes, setting a (double) pointer to the
//              first node that contains the searchVal (from the
//              root of the tree, if *match is initially NULL, or
//              from the point in the tree that *match points).
//
//              the tree should not be modified as a result of
//              performing this action. Any matched nodes remain in
//              the tree, unmodified.
//
// status code: this function generates the following status codes:
//                DLT_SUCCESS:     match found
//                DLT_EMPTY:       no matches found (or tree empty)
//                DLT_NULL:        tree is in NULL state
//                DLT_FAIL:        an error has taken place (tree
//                                 is NULL or EMPTY).
//
//              you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t searchtree(Tree *myTree, Node **match, sc searchVal)
{
	// your implementation here (please remove this comment when done)
	return(DLT_DEFAULT_FAIL);
}
