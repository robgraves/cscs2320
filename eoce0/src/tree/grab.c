#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//grabnode_r()- grab node out of indicated tree, ensuring integrity
//              is maintained (tree is modified)
//              
// status code: this function can generate the following status codes
//                  DLT_SUCCESS: normal operation
//                  DLT_EMPTY:   tree is now EMPTY after grabnode_r()
//                  DLT_NULL:    tree is NULL
//                  DLT_FAIL:    error occurred (tree is NULL,
//                               tried to grab from an empty tree)
//
//        note: the recursive implementation of grabnode_r() will 
//              embody the conceptual elegance often found in
//              such solutions: shorter code, less detail-oriented,
//              and relying centrally and heavily on calling some
//              function again and again as the means of processing.
//              While you cannot alter the header file, you may want
//              to implement a custom more local function that this
//              grabnode_r() function calls.
//
//              The key with getting a node out of the tree is 
//              that, in many cases, you are removing a parent;
//              so, what takes its place?
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t grabnode_r(Tree **myTree, Node **newNode)
{
	// to be implemented (remove this comment upon completion)
	return (DLT_DEFAULT_FAIL);
}
