#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  display() - display the list in a specified orientation, also
//              with or without positional values (as indicated
//              by the mode parameter).
//
//       modes: DISPLAY_FORWARD:   display the list forward
//              DISPLAY_NOPOSVALS: display with no positional values
//              DISPLAY_POSVALS:   display with positional values
//              DISPLAY_BACKWARD:  display the list backward
//     
//        note: positional values are indexed from 0
//     
// status code: this function can generate the following status codes
//                DLL_SUCCESS:     normal (not NULL, EMPTY, ERROR)
//                DLL_NULL:        list is NULL
//                DLL_EMPTY:       list is EMPTY
//                DLL_ERROR:       non-populated list
//
//    behavior: on a NULL list,    output: "(NULL)"
//              on an EMPTY list,  output: "-> NULL"
//              invalid mode:      MOD by 4 and do the result
//
//      format: output is to be on a single line, with node values
//              space-padded. and separated by "->" sequences, flush
//              against the left margin, of the forms:
//
// for forward: 0 -> 1 -> 2 -> ... -> N-1 -> N -> NULL
//
//   backwards: N -> N-1 -> ... -> 2 -> 1 -> 0 -> NULL
//
//              or, if being displayed with node positions:
//
// for forward: [0] 0 -> [1] 1 -> ... -> [N-1] N-1 -> [N] N -> NULL
//
//   backwards: [N] N -> [N-1] N-1 -> ... -> [1] 1 -> [0] 0 -> NULL
//
//        note: ALL output ends with a newline character
//
//        note: backwards output differs from that of singly-linked list
//              displayb(); with dll0, all display() output is universal
//              regardless of orientation.
//
code_t display(List *myList, int mode)
{
	// to be implemented (remove this comment upon completion)
	return(DLL_DEFAULT_FAIL);
}
