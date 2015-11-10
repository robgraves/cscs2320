#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//     empty() - a list library function to clear an existing list of
//               any and all of its component nodes (deallocate them).
//               The list itself continues to exist, but is in an
//               empty state following the successful call to
//               empty().
//
//               be sure to utilize existing list and node library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//  status code: this function can generate the following status code
//                 DLL_SUCCESS: everything went according to plan
//                 DLL_EMPTY:   list is now empty (normal operation)
//                 DLL_NULL:    *myList is NULL
//                 DLL_ERROR:   a failure was encountered, NULL
//                 DLL_INVALID: invalid condition (myList NULL)
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
code_t  empty(List **myList)
{
	// your implementation here (please remove this comment when done)
	return(DLL_DEFAULT_FAIL);
}
