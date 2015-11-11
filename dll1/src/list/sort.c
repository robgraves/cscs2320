#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// sortlist() - a list library function to sort an existing list
//              according to the mode indicated.
//
//              the original list is **MODIFIED**, and becomes the
//              sorted list.
//
//              be sure to utilize existing list and node library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//   modes are: 0 - least to greatest (least is first)
//              1 - greatest to least (greatest is first)
//              2 - reverse order of original list
//
//    behavior: on error, list becomes NULL.
//              on invalid mode, MOD by total modes and continue,
//                  performing whatever that result is.
//
// status code: this function can generate the following status codes
//                DLL_SUCCESS: normal operation
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list is empty
//                DLL_ERROR:   error encountered
//                DLL_INVALID: list does not exist
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t  sortlist(List **myList, int mode)
{
    //variable declarations and initializations
    code_t result = 0;

    return(result);
}
