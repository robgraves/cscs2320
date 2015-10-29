#include "node.h"

//////////////////////////////////////////////////////////////////////
//
//    mknode() - a node library function to allocate and initialize a 
//               new node (to provided value).
//
// status codes:
//               DLN_SUCCESS:       no problems encountered
//               DLN_MALLOC_FAIL:   error on creation
//               DLN_ALREADY_ALLOC: already exists
//               DLN_NULL:          node is in NULL state
//               DLN_ERROR:         some error occurred
//               DLN_INVALID:       invalid use (NULL pointer)
//
//         NOTE: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
//               if node is not in valid state, node should be set
//               to NULL.
//
code_t mknode(Node **newNode, char info)
{
    //variable declaration and initialization
    code_t result = 0; 

    //checking for Node pointer is NULL
    if (newNode != NULL)
    {
        //checking for Node is NULL
        if ((*newNode) == NULL)
        {    
            //allocate memory for Node
            (*newNode)=(Node *)malloc(sizeof(Node));
            //Node's payload.value (VALUE) assigned info
            (*newNode)->VALUE=info;
            //Node's after pointer assigned to NULL;
            (*newNode)->after=NULL;
            //Node's prior pointer assigned to NULL;
            (*newNode)->prior=NULL;
            //setting result to DLN_SUCCESS
            result = DLN_SUCCESS;
        }
        else
        {
            //assigning result if Node is already allocated
            result = DLN_ERROR + DLN_ALREADY_ALLOC;
        }
    }
    else
    {
        //if pointer is NULL, assigning result
        result = DLN_INVALID + DLN_ERROR;
    }


	return(result);
}
