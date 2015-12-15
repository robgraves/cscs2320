#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
// addnode()   - place newNode into indicated tree at proper position.
//
//  status code: this function can generate the following status codes
//                  DLT_SUCCESS:  normal operation (success!)
//                  DLT_NULL:     tree is NULL
//                  DLT_MAX:      tried to add onto a full bounded
//                                tree (considered an error)
//                  DLT_ERROR:    error encountered
//                  DLT_INVALID:  tree pointer doesn't exist
//
//         note: a max_height of 0 indicates an unbounded tree
//              
//  assumptions: duplicate values are allowed;
//               nodes with values less than or equal to that of
//               an analyzed node are placed to the left (prior),
//               where greater than are placed to the right (after).
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
code_t addnode(Tree **myTree, Node *newNode)
{
    //variable declarations and initializations
    code_t result = 0;
    uc max = 0;        //max height of tree, 0 indicared unbounded tree

    max = (*myTree)->max_height;

    if ((*myTree) == NULL)
    {
        (*myTree)->root = newNode;       
    }
    else
    {
        
    }

	return (result);
}
