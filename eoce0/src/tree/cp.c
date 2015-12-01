#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//  cptree_r() - duplicate a given tree (especially the state of
//               its contents), in a new tree. The algorithm/approach
//               used is to be a recursive one.
//
//         note: the recursive implementation of cptree() will 
//               embody the conceptual elegance often found in
//               such solutions: shorter code, less detail-oriented,
//               and relying centrally and heavily on calling some
//               function again and again as the means of processing.
//               While you cannot alter the header file, you may want
//               to implement a custom more local function that this
//               cptree_r() function calls.
//
//  status code: this function can generate the following status code
//                 DLT_SUCCESS:     normal operation
//                 DLT_CREATE_FAIL: *newTree already exists
//                 DLT_EMPTY:       curTree and *newTree are EMPTY
//                 DLT_NULL:        curTree or *newTree is NULL
//                 DLT_FAIL:        a failure was encountered
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
code_t cptree_r(Tree *curTree, Tree **newTree)
{
	// to be implemented (remove this comment upon completion)
	return (DLT_DEFAULT_FAIL);
}
