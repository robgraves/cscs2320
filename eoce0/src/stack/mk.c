#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
// mkstack() - allocate, initialize, and return a pointer to
//             the newly created stack.
//
//       note: the second parameter is to be the created stack's
//             maximum size (upper bound).
//
//             be sure to utilize existing list and stack library
//             functions to facilitate your implementation. Do NOT
//             reinvent the wheel.
//
//             the top of the stack should follow the last node in
//             its underlying list.
//
//       size: a stack size of 0 will indicate an unbounded stack
//             > 0 will limit the total number of nodes in the stack
//
//   behavior: in the event of an existing yet non-NULL newStack,
//             just fall though (do nothing), and generate the
//             appropriate status code(s).
//
//status code: this function can generate the following status codes:
//                 DLL_SUCCESS:     normal operations
//                 DLL_EMPTY:       result of normal operation
//                 DLS_SUCCESS:     normal operations
//                 DLS_EMPTY:       result of normal operation
//                 DLS_CREATE_FAIL: error on creation
//                 DLS_NULL:        stack remains in NULL state
//                 DLS_ERROR:       an error has taken place
//                 DLS_INVALID:     stack does not exist
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
code_t mkstack(Stack **newStack, ulli size)
{
    //variable declarations and initialization
    code_t result = 0;
    code_t list_result = 0;

    //checking if newStack pointer is NULL
    if (newStack != NULL)
    {
        //checking if pointer to newStack is NULL
        if ((*newStack) != NULL)
        {
            //error code 
            result = DLS_ERROR | DLS_CREATE_FAIL;
        }
        else
        {
        
            //allocating new stack with allocating list
            (*newStack) = (Stack *)malloc(sizeof(Stack));
            (*newStack)->top    = NULL;
            list_result = mklist(&((*newStack)->data));
            (*newStack)->size   = size;

            //success code
            result = DLS_EMPTY | DLS_SUCCESS | list_result;         
        }
    }
    else
    {
        //error code
        result = DLS_INVALID | DLS_ERROR;
    }

    return (result);
}
