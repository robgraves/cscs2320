#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//    find() - a list library utility function to locate a node in
//             an existing list by value it contains.
//
//       note: find() focuses on the actual content of what is in the
//             nodes, setting a (double) pointer to the first node
//             that contains the matching value (from the start of the
//             list, if foundNode is initially NULL, or from the point
//             in the list that foundNode points).
//
//status code: this function can generate the following status codes
//               DLN_SUCCESS:  match found
//               DLN_NULL:     match not found (node is NULL)
//               DLN_ERROR:    error encountered
//               DLL_NULL:     list is NULL
//               DLL_EMPTY:    list is EMPTY
//               DLL_ERROR:    error encountered
//
//   behavior: on error (NULL list, NULL node), foundNode is
//             NULL
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
code_t find(List *myList, char searchval, Node **foundNode)
{
	// your implementation here (please remove this comment when done)
	return(DLL_DEFAULT_FAIL);
}
