#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  display() - display the list according to mode(s).
//
//       modes: DISPLAY_FORWARD:   display the list forward
//              DISPLAY_NOPOSVALS: display with no positional values
//              DISPLAY_NOASCII:   display numeric values
//              DISPLAY_SEPS:      display separators between values
//              DISPLAY_POSVALS:   display with positional values
//              DISPLAY_BACKWARD:  display the list backward
//              DISPLAY_ASCII:     display ASCII characters
//              DISPLAY_NOSEPS:    do not display separators
//     
//        note: positional values are indexed from 0
//     
// status code: this function can generate the following status codes
//                DLL_SUCCESS:     normal (not NULL, EMPTY, ERROR)
//                DLL_NULL:        list is NULL
//                DLL_EMPTY:       list is EMPTY
//                DLL_ERROR:       non-populated list
//
//    behavior: on a NULL list,    output "(NULL)"
//              on an EMPTY list,  output "-> NULL" or "(EMPTY)" if
//                                 in ASCII mode
//              invalid mode:      MOD by 16 and do the result
//
//      format: output is to be against the left margin, on a single
//              line, ending with a newline character
//
//              DISPLAY_NOSEPS being set will remove all separators
//              and spaces from output, and positional values being
//              displayed change from "[#] " to "#:"
//
//              With DISPLAY_ASCII, separators are commas ', ', but
//              omitting the trailing comma at the end (there is no
//              terminating "NULL" displayed either)
//
//              Please see unit test output for examples. Note that
//              some mode combinations are nonsensical.
//
code_t display(List *myList, int mode)
{
	// Your implementation here (remove this comment once started)
    return(DLL_DEFAULT_FAIL);
}
