#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   obtain() - take and isolate indicated node out of list, through
//              a careful adjustment of necessary pointers. obtain()
//              needs to maintain list integrity.
//              
//error states: NULL or EMPTY initial list, NULL thatNode. In such a
//              case, do not modify the list.
//
// status code: this function can generate the following status codes
//                  DLN_NULL:    *thatNode is NULL
//                  DLN_INVALID: thatNode is NULL
//                  DLN_ERROR:   *thatNode not in list
//                  DLL_SUCCESS: normal operation
//                  DLL_NULL:    list is NULL
//                  DLL_ERROR:   error encountered (any error)
//                  DLL_INVALID: cannot proceed (myList is NULL)
//                  DLL_EMPTY:   list is EMPTY (not directly an
//                               error, although likely is associated
//                               with error condition)
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t  obtain(List **myList, Node **thatNode)
{
    //variable declarations and initializations
    code_t result = 0;


	return(result);
}
