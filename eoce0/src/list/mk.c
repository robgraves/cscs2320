#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  mklist() - allocate, initialize, and return a pointer to the
//             newly created list.
//
//status code: this function generates the following status codes:
//               DLL_SUCCESS:       no problems encountered
//               DLL_EMPTY:         result of normal operation
//               DLL_MALLOC_FAIL:   error on creation
//               DLL_ALREADY_ALLOC: list pointer already allocated
//               DLL_NULL:          list remains in NULL state
//               DLL_ERROR:         an error has taken place
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
code_t mklist(List **newList)
{
    //variable declaration and initialization
    code_t result = 0;

    //checking if newList is NULL
    if (newList == NULL)
    {
        result = DLL_INVALID + DLL_ERROR;
    }
    else
    {
        //cehcking if list exists
        if (*newList != NULL)
        {
            result = DLL_ERROR + DLL_ALREADY_ALLOC;
        }
        else
        {
            //allocating a new list
            (*newList) = (List *)malloc(sizeof(List));
            //setting first and last pointers to NULL
            (*newList)->first = NULL;
            (*newList)->last = NULL;
            //added qty to list
            (*newList)->qty = 0;

            result = DLL_EMPTY + DLL_SUCCESS;

        }

    }

	return(result);
}
