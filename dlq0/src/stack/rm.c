#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//  rmstack() - unset, nullify members, and de-allocate the given 
//              stack.
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should follow the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLL_SUCCESS: normal operation
//                  DLL_NULL:    stack data element is NULL
//                  DLS_SUCCESS: no problems encountered
//                  DLS_NULL:    normal operation
//                  DLS_INVALID: stack does not exist
//                  DLS_ERROR:   error encountered (or stack was
//                               already NULL)
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t rmstack(Stack **oldStack)
{
    //variable declaration and initializations
    code_t result = 0;
    code_t list_result = 0;

    //checking out stuff
    if (oldStack != NULL)
    {
        //checking out more stuff
        if ((*oldStack) != NULL)
        {
            //freeing up list and pointers in oldStack
            (*oldStack)->top = NULL;
            list_result = rmlist((*oldStack)->data);
            (*oldStack)->size = 0;
            free(*oldStack);
            (*oldStack) = NULL;
            result = DLS_NULL | DLS_SUCCESS | DLL_NULL | DLL_SUCCESS;
            //result = DLS_NULL | DLS_SUCCESS | list_result;
        }
        else
        {
            //some error message
            result = DLS_ERROR | DLS_NULL;
        }

    }
    else
    {
        //some error message
        result = DLS_INVALID | DLS_ERROR;
    }

	return (result);
}
