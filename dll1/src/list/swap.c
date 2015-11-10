#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// swapnode() - swap the position of two given nodes in a list, being
//              sure to appropriately adjust any and all pertinent
//              pointers to ensure list integrity following the
//              operation (including potential changes to the list's
//              own first and last pointers, along with connectivity
//              between the nodes from the start to end of the list).
//
//              be sure to utilize existing list and node library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//        note: you are NOT to just adjust node info values. You must
//              disconnect the identified nodes from the list and 
//              reconnect them- the node is our unit of transaction,
//              NOT the data it contains.
//
// status code: this function can generate the following status codes
//                DLN_NULL:    node is NULL
//                DLL_SUCCESS: normal operation
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list is empty
//                DLL_ERROR:   something is NULL or EMPTY, or other
//                             error state encountered.
//                DLL_INVALID: invalid list state
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t  swapnode(List **myList, Node *posA, Node *posB)
{
	// your implementation here (please remove this comment when done)
	return(DLL_DEFAULT_FAIL);
}
