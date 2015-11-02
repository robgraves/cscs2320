#include "node.h"

//////////////////////////////////////////////////////////////////////
//
//    rmnode() - a node library function to clear and deallocate an 
//               existing node
//
// status codes:
//               DLN_SUCCESS: no problems encountered
//               DLN_NULL:    node in NULL state
//               DLN_ERROR:   some error occurred
//               DLN_INVALID: invalid use (NULL pointer)
//
//         NOTE: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
//               be sure to explicitly set the node to NULL after
//               performing all necessary steps (but don't JUST
//               set it NULL- clear and deallocate first).
//
code_t rmnode(Node **curNode)
{
    //variable declaration adn initializations
    code_t result = 0;

    //check if double pointer is not NULL
    if (curNode != NULL)
    {
        //check if node pointer is NULL
        if (*curNode != NULL)
        {
            //deallocating the node
            free(*curNode);
            //setting node pointer to NULL
            *curNode = NULL;
            //setting result to NULL and SUCCESS
            result = DLN_NULL + DLN_SUCCESS;
        }
        else
        {
            //setting result to Error and NULL
            result = DLN_ERROR + DLN_NULL;
        }
    }
    else 
    {
        //setting result to Invalid and Error
        result = DLN_INVALID + DLN_ERROR;
    }

	return(result);
}
