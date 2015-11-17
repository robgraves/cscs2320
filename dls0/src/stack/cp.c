#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//   cpstack() - duplicate a given stack (especially the state of
//               its contents), in a new stack.
//
//     behavior: in the event of an existing yet non-NULL newStack,
//               just fall though (do nothing), and generate the
//               appropriate status code(s).
//
//               be sure to utilize existing list and stack library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//               the top of the stack should follow the last node in
//               its underlying list.
//
//  status code: this function can generate the following status code
//                 DLL_SUCCESS:     normal operation
//                 DLL_EMPTY:       stack data element is empty
//                 DLS_SUCCESS:     normal operation
//                 DLS_CREATE_FAIL: *newStack already exists
//                 DLS_EMPTY:       stack is EMPTY
//                 DLS_NULL:        stack is NULL
//                 DLS_ERROR:       a failure was encountered
//                 DLS_INVALID:     stack does not exist
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
code_t cpstack(Stack *curStack, Stack **newStack)
{
    //variable declarations and initializations
    code_t result = 0;

    

	return (result);
}
