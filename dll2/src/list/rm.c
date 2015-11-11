#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   rmlist() - a list library function to deallocate an existing
//              list; care must be taken to ensure any component
//              nodes have been properly deallocated so as to prevent
//              a memory leak. The resulting list will be NULL.
//
//              be sure to utilize existing list libraray functions 
//              to facilitate your implementation.
//
// status code: this function can generate the following status codes
//                DLL_SUCCESS: list successfully deallocated
//                DLL_NULL:    normal operation
//                DLL_ERROR:   error encountered (list already
//                             NULL or in invalid state)
//                DLL_INVALID: myList NULL
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t  rmlist(List **oldList)
{
    //variable declarations and initializations
    code_t result = 0;

	return(result);
}
